# -*- coding: utf-8 -*-
# FROM https://raw.githubusercontent.com/bruderstein/PythonScript/master/scripts/Samples/

import re

# --------------------------------------------------------------------------------------------------------------------------------------

#                                           Script "Multiples_SR.py"

# A LITTLE adaptation by guy038 from an ORIGINAL and VALUABLE script of Alan KILBORN ( January 2019 ) !

# See https://notepad-plus-plus.org/community/topic/16942/pythonscript-any-ready-pyscript-to-replace-one-huge-set-of-regex-phrases-with-others/21
# and https://notepad-plus-plus.org/community/topic/16942/pythonscript-any-ready-pyscript-to-replace-one-huge-set-of-regex-phrases-with-others/23

# This script :

#   - Reads an existing "SR_List.txt" file, of the CURRENT directory, containing a list of SEARCH/REPLACEMENT strings, ONE PER line
#   - Selects, one at a time, a COUPLE of SEARCH and REPLACEMENT regexes  / expressions / strings / characters
#   - Executes this present S/R on CURRENT edited file, in NOTEPAD++
#   - Loop till the END of file

# Any PURE BLANK line or COMMENT line, beginning with '#', of the "SR_list.txt" file, are simply IGNORED

# --------------------------------------------------------------------------------------------------------------------------------------

# For EACH line, in the "SR_List.txt" file, the format is <DELIMITER><SEARCH regex><DELIMITER><REPLACE regex><DELIMITER>

## EXAMPLES :
## ¯¯¯¯¯¯¯¯

##  Deletes any [ending] "; comment"  /  Delimiter = '!'
#!(?-s)(^.*?);.+!\1!

##  Changes any LOWER-case string "notepad++" in its UPPER-case equivalent  /  Delimiter = '@'
#@(?-i)notepad\+\+@NOTEPAD++@

##  Changes any "Smith" and 'James' strings, with that EXACT case, to, respectively, "Name" and "First name"  /  Delimiter = '&'
##  Deletes any "TEST" string, with that EXACT case
#&(Smith)|TEST|(James)&(?1Name)(?2First name)&

##  Replaces any BACKSLASH character with the "123" number, both  preceded and followed with 3 SPACE characters  /  Delimiter = '%'
#%\\%   123   %
##    or, also, the syntax   %\x5c%   123   %

##  Deletes any string "Fix", followed with a SPACE char, whatever its CASE  /  Delimiter = '+'
#+(?i)Fix ++

##  Change 3 CONSECUTIVE "#" characters with 3 BACKSLASH characters  /  Delimiter = '*'
#*###*\\\\\\*

# --------------------------------------------------------------------------------------------------------------------------------------

# In the CODE line, right below, you may :

#   - Modify the NAME of the file, containing the SEARCH and REPLACEMENT regexes
#   - Indicate an ABSOLUTE or RELATIVE path, before the filename

#with open(r'SR_list.txt') as f: sr_list = f.readlines()

# You may, as well, insert the SEARCH and REPLACE regexes, directly, in THIS script :

sr_list = [
r'!G90!G90 \(Absolute Programming\)!',
r'!G40!G40 \(Kerf Off\)!',
r'!G41!G41 \(Kerf Left\)!',
r'!G42!G42 \(Kerf Right\)!',
r'!G91!G91 \(Incremental Programming\)!',
r'!G70!G70 \(Inch Mode\)!',
r'!G84!G84 \(Deselect all Stations\)!',
r'!G85\s?I(\d)(\d)\s?J(-?\d*.\d*)(\r|\n)!G85 I($1)($2) J($3) \(Fix St ($1), Move St ($2) Spacing=($3)\)!',
r'!G83\s?I(\d)\s?(\r|\n)!G83 I($1)\(Select Station ($1)\)($2)!',
r'!G83\s?I(\d)\s?J(\d)!G83 I($1) ($2)\(Select Station ($1) Clamp Mode=($2)\)!',
r'!AL\s?(-?\d*.\d*)!AL ($1) \(Tilt to ($1) Degrees\)!',
r'!(M178\s?D1)!($1) \(Send Y1 to Home\)!',
r'!(M178\s?D2)!($1) \(Send Y2 to Home\)!',
r'!G71!G71 \(Metric Mode\)!',
r'!M65!M65 \(Plasma Start\)!',
r'!M02!M02 \(Program Stop\)!',
r'!M66!M66 \(Plasma Stop\)!',
r'!M177!M177 \(Foot Up\)!',
r'!M174!M174 \(Flying Stop\)!',
r'!M176!M176 \(Foot Down\)!',
r'!M35!M35 \(Rotation look ahead 1 block\)!',
r'!M34!M34 \(Rotation skip block\)!',
r'!M58!M58 \(AVHC Enable\)!',
r'!M57!M57 \(AVHC Disable\)!',
r'!M145 D0!M145 D0 \(Straight/I ORG Selection\)!',
r'!M145 D1!M145 D1 \(Y ORG Selection\)!',
r'!M145 D2!M145 D2 \(K ORG Selection\)!',
r'!G160 P1!G160 P1 \(Plasma Process\)!',
r'!G160 P2!G160 P2 \(Oxy-Fuel Process\)!',
r'!M62!M62 \(Rotation Stop\Freeze\)!',
r'!M63!M63 \(Rotation On\)!',
r'!M64!M64 \(Rotation Off\)!',
r'!D3(\r|\n)!D3 \(Comment Block Start\)($1)!',
r'!D4(\r|\n)!D4 \(Comment Block End\)($1)!',
r'!(M129 D(.\d)*)!($1) \(Total Material Thickness\)!',
r'!(M120 D(.\d)*)!($1) \(Feature Height\)!',
r'!(T\d)!($1) \(Tool Offset Select\)!'
]

# The use of RAW strings  r'.......'  is also possible, in order to SIMPLIFY some regexes

# Note that these RAW regexes are strictly IDENTICAL to those, which could be contained in a "SR_List.txt" file, WITHOUT the 'r' PREFIX

#sr_list = [
#    r'!(?-s)(^.*?);.+!\1!',
#    r'@(?-i)notepad\+\+@NOTEPAD++@',
#    r'&(Smith)|TEST|(James)&(?1Name)(?2First name)&',
#    r'%\\%   123   %',
#          # or the syntax  r'%\x5c%   123   %',
#    r'+(?i)Fix ++',
#    r'*###*\\\\\\*',
#    ]

editor.beginUndoAction()

console.write ('\nMODIFICATIONS on FILE "{}: "\n\n'.format(notepad.getCurrentFilename()))

# Note : Variable e is always EMPTY string ( Part AFTER the THIRD delimiter and BEFORE the END of line ! )

for line in sr_list:

    if line[0] == '#' or line == '\n' : continue
    (s,r,e) = line[1:].rstrip('\n').split(line[0])

    console.write('    SEARCH  : >{}<\n'.format(s))
    console.write('    REPLACE : >{}<\n\n'.format(r))

    editor.rereplace(s,r)   # or editor.rereplace(s,r,re.IGNORECASE) / editor.rereplace(s,r,re.I)

editor.endUndoAction()

# END of Multiple_SR.py script
