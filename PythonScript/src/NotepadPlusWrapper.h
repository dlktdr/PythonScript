#ifndef _NOTEPADPLUSWRAPPER_H
#define _NOTEPADPLUSWRAPPER_H

#ifndef NOTEPAD_PLUS_MSGS_H
#include "Notepad_plus_msgs.h"
#endif

#ifndef MENUCMDID_H
#include "menuCmdID.h"
#endif

#include "GILManager.h"

struct SCNotification;
namespace NppPythonScript
{
class ScintillaWrapper;
class CallbackExecArgs;

enum FormatType
{
	WIN_FORMAT,
	MAC_FORMAT,
	UNIX_FORMAT
};

enum BufferEncoding
{
	uni8Bit			= 0,
	uniUTF8			= 1,
	uni16BE			= 2,
	uni16LE			= 3,
	uniCookie		= 4,
	uni7Bit			= 5,
	uni16BE_NoBOM	= 6,
	uni16LE_NoBOM	= 7,
	uniEnd
};

enum StatusBarSection
{
	STATUSBARSECTION_DOCTYPE = STATUSBAR_DOC_TYPE,
	STATUSBARSECTION_DOCSIZE = STATUSBAR_DOC_SIZE,
	STATUSBARSECTION_CURPOS = STATUSBAR_CUR_POS,
	STATUSBARSECTION_EOFFORMAT = STATUSBAR_EOF_FORMAT,
	STATUSBARSECTION_UNICODETYPE = STATUSBAR_UNICODE_TYPE,
	STATUSBARSECTION_TYPINGMODE = STATUSBAR_TYPING_MODE
};

// enum for the notifications
enum Notification
{
	NPPNOTIF_READY = NPPN_READY,
	NPPNOTIF_TBMODIFICATION = NPPN_TBMODIFICATION,
	NPPNOTIF_FILEBEFORECLOSE = NPPN_FILEBEFORECLOSE,
	NPPNOTIF_FILEOPENED = NPPN_FILEOPENED,
	NPPNOTIF_FILECLOSED = NPPN_FILECLOSED,
	NPPNOTIF_FILEBEFOREOPEN = NPPN_FILEBEFOREOPEN,
	NPPNOTIF_FILEBEFORESAVE = NPPN_FILEBEFORESAVE,
	NPPNOTIF_FILESAVED = NPPN_FILESAVED,
	NPPNOTIF_SHUTDOWN = NPPN_SHUTDOWN,
	NPPNOTIF_BUFFERACTIVATED = NPPN_BUFFERACTIVATED,
	NPPNOTIF_LANGCHANGED = NPPN_LANGCHANGED,
	NPPNOTIF_WORDSTYLESUPDATED = NPPN_WORDSTYLESUPDATED,
	NPPNOTIF_SHORTCUTREMAPPED = NPPN_SHORTCUTREMAPPED,
	NPPNOTIF_FILEBEFORELOAD = NPPN_FILEBEFORELOAD,
	NPPNOTIF_FILELOADFAILED = NPPN_FILELOADFAILED,
	NPPNOTIF_READONLYCHANGED = NPPN_READONLYCHANGED,
	NPPNOTIF_DOCORDERCHANGED = NPPN_DOCORDERCHANGED,
	NPPNOTIF_SNAPSHOTDIRTYFILELOADED = NPPN_SNAPSHOTDIRTYFILELOADED,
	NPPNOTIF_BEFORESHUTDOWN = NPPN_BEFORESHUTDOWN,
	NPPNOTIF_CANCELSHUTDOWN = NPPN_CANCELSHUTDOWN,
	NPPNOTIF_FILEBEFORERENAME = NPPN_FILEBEFORERENAME,
	NPPNOTIF_FILERENAMECANCEL = NPPN_FILERENAMECANCEL,
	NPPNOTIF_FILERENAMED = NPPN_FILERENAMED,
	NPPNOTIF_FILEBEFOREDELETE = NPPN_FILEBEFOREDELETE,
	NPPNOTIF_FILEDELETEFAILED = NPPN_FILEDELETEFAILED,
	NPPNOTIF_FILEDELETED = NPPN_FILEDELETED,
	NPPNOTIF_DARKMODECHANGED = NPPN_DARKMODECHANGED,
	NPPNOTIF_CMDLINEPLUGINMSG = NPPN_CMDLINEPLUGINMSG,
	NPPNOTIF_EXTERNALLEXERBUFFER = NPPN_EXTERNALLEXERBUFFER,
	NPPNOTIF_GLOBALMODIFIED = NPPN_GLOBALMODIFIED
};

//lint -e849 Symbol 'MessageBoxFlags::NPPMB_OKCANCEL' has same enumerator value '1' as enumerator 'NPPMB_RESULTOK'
// This is expected. The return codes share the same values as the flags parameter.  This is to make the Python
// end a bit simpler. It could be argued the result codes could go in a separate enum - at the moment I think it's
// more obvious that the same enum is used.
enum MessageBoxFlags
{
	NPPMB_RESULTABORT = IDABORT,
	NPPMB_RESULTCANCEL = IDCANCEL,
	NPPMB_RESULTCONTINUE = IDCONTINUE,
	NPPMB_RESULTIGNORE = IDIGNORE,
	NPPMB_RESULTNO = IDNO,
	NPPMB_RESULTOK = IDOK,
	NPPMB_RESULTRETRY = IDRETRY,
	NPPMB_RESULTTRYAGAIN = IDTRYAGAIN,
	NPPMB_RESULTYES = IDYES,
	NPPMB_OK = MB_OK,
	NPPMB_OKCANCEL = MB_OKCANCEL,
	NPPMB_ABORTRETRYIGNORE = MB_ABORTRETRYIGNORE,
	NPPMB_YESNOCANCEL = MB_YESNOCANCEL,
	NPPMB_YESNO = MB_YESNO,
	NPPMB_RETRYCANCEL = MB_RETRYCANCEL,
	NPPMB_CANCELTRYCONTINUE = MB_CANCELTRYCONTINUE,
	NPPMB_ICONHAND = MB_ICONHAND,
	NPPMB_ICONQUESTION = MB_ICONQUESTION,
	NPPMB_ICONEXCLAMATION = MB_ICONEXCLAMATION,
	NPPMB_ICONASTERISK = MB_ICONASTERISK,
	NPPMB_ICONWARNING = MB_ICONWARNING,
	NPPMB_ICONERROR = MB_ICONERROR,
	NPPMB_ICONINFORMATION = MB_ICONINFORMATION,
	NPPMB_ICONSTOP = MB_ICONSTOP,
	NPPMB_DEFBUTTON1 = MB_DEFBUTTON1,
	NPPMB_DEFBUTTON2 = MB_DEFBUTTON2,
	NPPMB_DEFBUTTON3 = MB_DEFBUTTON3,
	NPPMB_DEFBUTTON4 = MB_DEFBUTTON4
};
//lint +e849

enum MenuCommands
{
	NPPIDM_FILE = IDM_FILE,
	NPPIDM_FILE_NEW = IDM_FILE_NEW,
	NPPIDM_FILE_OPEN = IDM_FILE_OPEN,
	NPPIDM_FILE_CLOSE = IDM_FILE_CLOSE,
	NPPIDM_FILE_CLOSEALL = IDM_FILE_CLOSEALL,
	NPPIDM_FILE_CLOSEALL_BUT_CURRENT = IDM_FILE_CLOSEALL_BUT_CURRENT,
	NPPIDM_FILE_SAVE = IDM_FILE_SAVE,
	NPPIDM_FILE_SAVEALL = IDM_FILE_SAVEALL,
	NPPIDM_FILE_SAVEAS = IDM_FILE_SAVEAS,
	NPPIDM_FILE_CLOSEALL_TOLEFT = IDM_FILE_CLOSEALL_TOLEFT,
	NPPIDM_FILE_PRINT = IDM_FILE_PRINT,
	NPPIDM_FILE_PRINTNOW = IDM_FILE_PRINTNOW,
	NPPIDM_FILE_EXIT = IDM_FILE_EXIT,
	NPPIDM_FILE_LOADSESSION = IDM_FILE_LOADSESSION,
	NPPIDM_FILE_SAVESESSION = IDM_FILE_SAVESESSION,
	NPPIDM_FILE_RELOAD = IDM_FILE_RELOAD,
	NPPIDM_FILE_SAVECOPYAS = IDM_FILE_SAVECOPYAS,
	NPPIDM_FILE_DELETE = IDM_FILE_DELETE,
	NPPIDM_FILE_RENAME = IDM_FILE_RENAME,
	NPPIDM_FILE_CLOSEALL_TORIGHT = IDM_FILE_CLOSEALL_TORIGHT,
	NPPIDM_FILE_OPEN_FOLDER = IDM_FILE_OPEN_FOLDER,
	NPPIDM_FILE_OPEN_CMD = IDM_FILE_OPEN_CMD,
	NPPIDM_FILE_RESTORELASTCLOSEDFILE = IDM_FILE_RESTORELASTCLOSEDFILE,
	NPPIDM_FILE_OPENFOLDERASWORSPACE = IDM_FILE_OPENFOLDERASWORSPACE,
	NPPIDM_FILE_OPEN_DEFAULT_VIEWER = IDM_FILE_OPEN_DEFAULT_VIEWER,
	NPPIDM_FILE_CLOSEALL_UNCHANGED = IDM_FILE_CLOSEALL_UNCHANGED,
	NPPIDM_FILE_CONTAININGFOLDERASWORKSPACE = IDM_FILE_CONTAININGFOLDERASWORKSPACE,
	NPPIDM_FILEMENU_LASTONE = IDM_FILEMENU_LASTONE,
	NPPIDM_FILEMENU_EXISTCMDPOSITION = IDM_FILEMENU_EXISTCMDPOSITION,
	NPPIDM_EDIT = IDM_EDIT,
	NPPIDM_EDIT_CUT = IDM_EDIT_CUT,
	NPPIDM_EDIT_COPY = IDM_EDIT_COPY,
	NPPIDM_EDIT_UNDO = IDM_EDIT_UNDO,
	NPPIDM_EDIT_REDO = IDM_EDIT_REDO,
	NPPIDM_EDIT_PASTE = IDM_EDIT_PASTE,
	NPPIDM_EDIT_DELETE = IDM_EDIT_DELETE,
	NPPIDM_EDIT_SELECTALL = IDM_EDIT_SELECTALL,
	NPPIDM_EDIT_INS_TAB = IDM_EDIT_INS_TAB,
	NPPIDM_EDIT_RMV_TAB = IDM_EDIT_RMV_TAB,
	NPPIDM_EDIT_DUP_LINE = IDM_EDIT_DUP_LINE,
	NPPIDM_EDIT_TRANSPOSE_LINE = IDM_EDIT_TRANSPOSE_LINE,
	NPPIDM_EDIT_SPLIT_LINES = IDM_EDIT_SPLIT_LINES,
	NPPIDM_EDIT_JOIN_LINES = IDM_EDIT_JOIN_LINES,
	NPPIDM_EDIT_LINE_UP = IDM_EDIT_LINE_UP,
	NPPIDM_EDIT_LINE_DOWN = IDM_EDIT_LINE_DOWN,
	NPPIDM_EDIT_UPPERCASE = IDM_EDIT_UPPERCASE,
	NPPIDM_EDIT_LOWERCASE = IDM_EDIT_LOWERCASE,
	NPPIDM_MACRO_STARTRECORDINGMACRO = IDM_MACRO_STARTRECORDINGMACRO,
	NPPIDM_MACRO_STOPRECORDINGMACRO = IDM_MACRO_STOPRECORDINGMACRO,
	NPPIDM_EDIT_BEGINENDSELECT = IDM_EDIT_BEGINENDSELECT,
	NPPIDM_MACRO_PLAYBACKRECORDEDMACRO = IDM_MACRO_PLAYBACKRECORDEDMACRO,
	NPPIDM_EDIT_BLOCK_COMMENT = IDM_EDIT_BLOCK_COMMENT,
	NPPIDM_EDIT_STREAM_COMMENT = IDM_EDIT_STREAM_COMMENT,
	NPPIDM_EDIT_TRIMTRAILING = IDM_EDIT_TRIMTRAILING,
	NPPIDM_MACRO_SAVECURRENTMACRO = IDM_MACRO_SAVECURRENTMACRO,
	NPPIDM_EDIT_RTL = IDM_EDIT_RTL,
	NPPIDM_EDIT_LTR = IDM_EDIT_LTR,
	NPPIDM_EDIT_SETREADONLY = IDM_EDIT_SETREADONLY,
	NPPIDM_EDIT_FULLPATHTOCLIP = IDM_EDIT_FULLPATHTOCLIP,
	NPPIDM_EDIT_FILENAMETOCLIP = IDM_EDIT_FILENAMETOCLIP,
	NPPIDM_EDIT_CURRENTDIRTOCLIP = IDM_EDIT_CURRENTDIRTOCLIP,
	NPPIDM_MACRO_RUNMULTIMACRODLG = IDM_MACRO_RUNMULTIMACRODLG,
	NPPIDM_EDIT_CLEARREADONLY = IDM_EDIT_CLEARREADONLY,
	NPPIDM_EDIT_COLUMNMODE = IDM_EDIT_COLUMNMODE,
	NPPIDM_EDIT_BLOCK_COMMENT_SET = IDM_EDIT_BLOCK_COMMENT_SET,
	NPPIDM_EDIT_BLOCK_UNCOMMENT = IDM_EDIT_BLOCK_UNCOMMENT,
	NPPIDM_EDIT_COLUMNMODETIP = IDM_EDIT_COLUMNMODETIP,
	NPPIDM_EDIT_PASTE_AS_HTML = IDM_EDIT_PASTE_AS_HTML,
	NPPIDM_EDIT_PASTE_AS_RTF = IDM_EDIT_PASTE_AS_RTF,
	NPPIDM_OPEN_ALL_RECENT_FILE = IDM_OPEN_ALL_RECENT_FILE,
	NPPIDM_CLEAN_RECENT_FILE_LIST = IDM_CLEAN_RECENT_FILE_LIST,
	NPPIDM_EDIT_TRIMLINEHEAD = IDM_EDIT_TRIMLINEHEAD,
	NPPIDM_EDIT_TRIM_BOTH = IDM_EDIT_TRIM_BOTH,
	NPPIDM_EDIT_EOL2WS = IDM_EDIT_EOL2WS,
	NPPIDM_EDIT_TRIMALL = IDM_EDIT_TRIMALL,
	NPPIDM_EDIT_TAB2SW = IDM_EDIT_TAB2SW,
	NPPIDM_EDIT_STREAM_UNCOMMENT = IDM_EDIT_STREAM_UNCOMMENT,
	NPPIDM_EDIT_COPY_BINARY = IDM_EDIT_COPY_BINARY,
	NPPIDM_EDIT_CUT_BINARY = IDM_EDIT_CUT_BINARY,
	NPPIDM_EDIT_PASTE_BINARY = IDM_EDIT_PASTE_BINARY,
	NPPIDM_EDIT_CHAR_PANEL = IDM_EDIT_CHAR_PANEL,
	NPPIDM_EDIT_CLIPBOARDHISTORY_PANEL = IDM_EDIT_CLIPBOARDHISTORY_PANEL,
	NPPIDM_EDIT_SW2TAB_LEADING = IDM_EDIT_SW2TAB_LEADING,
	NPPIDM_EDIT_SW2TAB_ALL = IDM_EDIT_SW2TAB_ALL,
	NPPIDM_EDIT_REMOVEEMPTYLINES = IDM_EDIT_REMOVEEMPTYLINES,
	NPPIDM_EDIT_REMOVEEMPTYLINESWITHBLANK = IDM_EDIT_REMOVEEMPTYLINESWITHBLANK,
	NPPIDM_EDIT_BLANKLINEABOVECURRENT = IDM_EDIT_BLANKLINEABOVECURRENT,
	NPPIDM_EDIT_BLANKLINEBELOWCURRENT = IDM_EDIT_BLANKLINEBELOWCURRENT,
	NPPIDM_EDIT_SORTLINES_LEXICOGRAPHIC_ASCENDING = IDM_EDIT_SORTLINES_LEXICOGRAPHIC_ASCENDING,
	NPPIDM_EDIT_SORTLINES_LEXICOGRAPHIC_DESCENDING = IDM_EDIT_SORTLINES_LEXICOGRAPHIC_DESCENDING,
	NPPIDM_EDIT_SORTLINES_INTEGER_ASCENDING = IDM_EDIT_SORTLINES_INTEGER_ASCENDING,
	NPPIDM_EDIT_SORTLINES_INTEGER_DESCENDING = IDM_EDIT_SORTLINES_INTEGER_DESCENDING,
	NPPIDM_EDIT_SORTLINES_DECIMALCOMMA_ASCENDING = IDM_EDIT_SORTLINES_DECIMALCOMMA_ASCENDING,
	NPPIDM_EDIT_SORTLINES_DECIMALCOMMA_DESCENDING = IDM_EDIT_SORTLINES_DECIMALCOMMA_DESCENDING,
	NPPIDM_EDIT_SORTLINES_DECIMALDOT_ASCENDING = IDM_EDIT_SORTLINES_DECIMALDOT_ASCENDING,
	NPPIDM_EDIT_SORTLINES_DECIMALDOT_DESCENDING = IDM_EDIT_SORTLINES_DECIMALDOT_DESCENDING,
	NPPIDM_EDIT_PROPERCASE_FORCE = IDM_EDIT_PROPERCASE_FORCE,
	NPPIDM_EDIT_PROPERCASE_BLEND = IDM_EDIT_PROPERCASE_BLEND,
	NPPIDM_EDIT_SENTENCECASE_FORCE = IDM_EDIT_SENTENCECASE_FORCE,
	NPPIDM_EDIT_SENTENCECASE_BLEND = IDM_EDIT_SENTENCECASE_BLEND,
	NPPIDM_EDIT_INVERTCASE = IDM_EDIT_INVERTCASE,
	NPPIDM_EDIT_RANDOMCASE = IDM_EDIT_RANDOMCASE,
	NPPIDM_EDIT_OPENASFILE = IDM_EDIT_OPENASFILE,
	NPPIDM_EDIT_OPENINFOLDER = IDM_EDIT_OPENINFOLDER,
	NPPIDM_EDIT_SEARCHONINTERNET = IDM_EDIT_SEARCHONINTERNET,
	NPPIDM_EDIT_CHANGESEARCHENGINE = IDM_EDIT_CHANGESEARCHENGINE,
	NPPIDM_EDIT_REMOVE_CONSECUTIVE_DUP_LINES = IDM_EDIT_REMOVE_CONSECUTIVE_DUP_LINES,
	NPPIDM_EDIT_SORTLINES_RANDOMLY = IDM_EDIT_SORTLINES_RANDOMLY,
	NPPIDM_EDIT_REMOVE_ANY_DUP_LINES = IDM_EDIT_REMOVE_ANY_DUP_LINES,
	NPPIDM_EDIT_SORTLINES_LEXICO_CASE_INSENS_ASCENDING = IDM_EDIT_SORTLINES_LEXICO_CASE_INSENS_ASCENDING,
	NPPIDM_EDIT_SORTLINES_LEXICO_CASE_INSENS_DESCENDING = IDM_EDIT_SORTLINES_LEXICO_CASE_INSENS_DESCENDING,
	NPPIDM_EDIT_COPY_LINK = IDM_EDIT_COPY_LINK,
	NPPIDM_EDIT_SORTLINES_REVERSE_ORDER = IDM_EDIT_SORTLINES_REVERSE_ORDER,
	NPPIDM_EDIT_INSERT_DATETIME_SHORT = IDM_EDIT_INSERT_DATETIME_SHORT,
	NPPIDM_EDIT_INSERT_DATETIME_LONG = IDM_EDIT_INSERT_DATETIME_LONG,
	NPPIDM_EDIT_INSERT_DATETIME_CUSTOMIZED = IDM_EDIT_INSERT_DATETIME_CUSTOMIZED,
	NPPIDM_EDIT_COPY_ALL_NAMES = IDM_EDIT_COPY_ALL_NAMES,
	NPPIDM_EDIT_COPY_ALL_PATHS = IDM_EDIT_COPY_ALL_PATHS,
	NPPIDM_EDIT_BEGINENDSELECT_COLUMNMODE = IDM_EDIT_BEGINENDSELECT_COLUMNMODE,
	NPPIDM_EDIT_MULTISELECTALL = IDM_EDIT_MULTISELECTALL,
	NPPIDM_EDIT_MULTISELECTALLMATCHCASE = IDM_EDIT_MULTISELECTALLMATCHCASE,
	NPPIDM_EDIT_MULTISELECTALLWHOLEWORD = IDM_EDIT_MULTISELECTALLWHOLEWORD,
	NPPIDM_EDIT_MULTISELECTALLMATCHCASEWHOLEWORD = IDM_EDIT_MULTISELECTALLMATCHCASEWHOLEWORD,
	NPPIDM_EDIT_MULTISELECTNEXT = IDM_EDIT_MULTISELECTNEXT,
	NPPIDM_EDIT_MULTISELECTNEXTMATCHCASE = IDM_EDIT_MULTISELECTNEXTMATCHCASE,
	NPPIDM_EDIT_MULTISELECTNEXTWHOLEWORD = IDM_EDIT_MULTISELECTNEXTWHOLEWORD,
	NPPIDM_EDIT_MULTISELECTNEXTMATCHCASEWHOLEWORD = IDM_EDIT_MULTISELECTNEXTMATCHCASEWHOLEWORD,
	NPPIDM_EDIT_MULTISELECTUNDO = IDM_EDIT_MULTISELECTUNDO,
	NPPIDM_EDIT_MULTISELECTSSKIP = IDM_EDIT_MULTISELECTSSKIP,
	NPPIDM_EDIT_AUTOCOMPLETE = IDM_EDIT_AUTOCOMPLETE,
	NPPIDM_EDIT_AUTOCOMPLETE_CURRENTFILE = IDM_EDIT_AUTOCOMPLETE_CURRENTFILE,
	NPPIDM_EDIT_FUNCCALLTIP = IDM_EDIT_FUNCCALLTIP,
	NPPIDM_EDIT_AUTOCOMPLETE_PATH = IDM_EDIT_AUTOCOMPLETE_PATH,
	NPPIDM_EDIT_FUNCCALLTIP_PREVIOUS = IDM_EDIT_FUNCCALLTIP_PREVIOUS,
	NPPIDM_EDIT_FUNCCALLTIP_NEXT = IDM_EDIT_FUNCCALLTIP_NEXT,
	NPPIDM_SEARCH = IDM_SEARCH,
	NPPIDM_SEARCH_FIND = IDM_SEARCH_FIND,
	NPPIDM_SEARCH_FINDNEXT = IDM_SEARCH_FINDNEXT,
	NPPIDM_SEARCH_REPLACE = IDM_SEARCH_REPLACE,
	NPPIDM_SEARCH_GOTOLINE = IDM_SEARCH_GOTOLINE,
	NPPIDM_SEARCH_TOGGLE_BOOKMARK = IDM_SEARCH_TOGGLE_BOOKMARK,
	NPPIDM_SEARCH_NEXT_BOOKMARK = IDM_SEARCH_NEXT_BOOKMARK,
	NPPIDM_SEARCH_PREV_BOOKMARK = IDM_SEARCH_PREV_BOOKMARK,
	NPPIDM_SEARCH_CLEAR_BOOKMARKS = IDM_SEARCH_CLEAR_BOOKMARKS,
	NPPIDM_SEARCH_GOTOMATCHINGBRACE = IDM_SEARCH_GOTOMATCHINGBRACE,
	NPPIDM_SEARCH_FINDPREV = IDM_SEARCH_FINDPREV,
	NPPIDM_SEARCH_FINDINCREMENT = IDM_SEARCH_FINDINCREMENT,
	NPPIDM_SEARCH_FINDINFILES = IDM_SEARCH_FINDINFILES,
	NPPIDM_SEARCH_VOLATILE_FINDNEXT = IDM_SEARCH_VOLATILE_FINDNEXT,
	NPPIDM_SEARCH_VOLATILE_FINDPREV = IDM_SEARCH_VOLATILE_FINDPREV,
	NPPIDM_SEARCH_CUTMARKEDLINES = IDM_SEARCH_CUTMARKEDLINES,
	NPPIDM_SEARCH_COPYMARKEDLINES = IDM_SEARCH_COPYMARKEDLINES,
	NPPIDM_SEARCH_PASTEMARKEDLINES = IDM_SEARCH_PASTEMARKEDLINES,
	NPPIDM_SEARCH_DELETEMARKEDLINES = IDM_SEARCH_DELETEMARKEDLINES,
	NPPIDM_SEARCH_MARKALLEXT1 = IDM_SEARCH_MARKALLEXT1,
	NPPIDM_SEARCH_UNMARKALLEXT1 = IDM_SEARCH_UNMARKALLEXT1,
	NPPIDM_SEARCH_MARKALLEXT2 = IDM_SEARCH_MARKALLEXT2,
	NPPIDM_SEARCH_UNMARKALLEXT2 = IDM_SEARCH_UNMARKALLEXT2,
	NPPIDM_SEARCH_MARKALLEXT3 = IDM_SEARCH_MARKALLEXT3,
	NPPIDM_SEARCH_UNMARKALLEXT3 = IDM_SEARCH_UNMARKALLEXT3,
	NPPIDM_SEARCH_MARKALLEXT4 = IDM_SEARCH_MARKALLEXT4,
	NPPIDM_SEARCH_UNMARKALLEXT4 = IDM_SEARCH_UNMARKALLEXT4,
	NPPIDM_SEARCH_MARKALLEXT5 = IDM_SEARCH_MARKALLEXT5,
	NPPIDM_SEARCH_UNMARKALLEXT5 = IDM_SEARCH_UNMARKALLEXT5,
	NPPIDM_SEARCH_CLEARALLMARKS = IDM_SEARCH_CLEARALLMARKS,
	NPPIDM_SEARCH_GOPREVMARKER1 = IDM_SEARCH_GOPREVMARKER1,
	NPPIDM_SEARCH_GOPREVMARKER2 = IDM_SEARCH_GOPREVMARKER2,
	NPPIDM_SEARCH_GOPREVMARKER3 = IDM_SEARCH_GOPREVMARKER3,
	NPPIDM_SEARCH_GOPREVMARKER4 = IDM_SEARCH_GOPREVMARKER4,
	NPPIDM_SEARCH_GOPREVMARKER5 = IDM_SEARCH_GOPREVMARKER5,
	NPPIDM_SEARCH_GOPREVMARKER_DEF = IDM_SEARCH_GOPREVMARKER_DEF,
	NPPIDM_SEARCH_GONEXTMARKER1 = IDM_SEARCH_GONEXTMARKER1,
	NPPIDM_SEARCH_GONEXTMARKER2 = IDM_SEARCH_GONEXTMARKER2,
	NPPIDM_SEARCH_GONEXTMARKER3 = IDM_SEARCH_GONEXTMARKER3,
	NPPIDM_SEARCH_GONEXTMARKER4 = IDM_SEARCH_GONEXTMARKER4,
	NPPIDM_SEARCH_GONEXTMARKER5 = IDM_SEARCH_GONEXTMARKER5,
	NPPIDM_SEARCH_GONEXTMARKER_DEF = IDM_SEARCH_GONEXTMARKER_DEF,
	NPPIDM_FOCUS_ON_FOUND_RESULTS = IDM_FOCUS_ON_FOUND_RESULTS,
	NPPIDM_SEARCH_GOTONEXTFOUND = IDM_SEARCH_GOTONEXTFOUND,
	NPPIDM_SEARCH_GOTOPREVFOUND = IDM_SEARCH_GOTOPREVFOUND,
	NPPIDM_SEARCH_SETANDFINDNEXT = IDM_SEARCH_SETANDFINDNEXT,
	NPPIDM_SEARCH_SETANDFINDPREV = IDM_SEARCH_SETANDFINDPREV,
	NPPIDM_SEARCH_INVERSEMARKS = IDM_SEARCH_INVERSEMARKS,
	NPPIDM_SEARCH_DELETEUNMARKEDLINES = IDM_SEARCH_DELETEUNMARKEDLINES,
	NPPIDM_SEARCH_FINDCHARINRANGE = IDM_SEARCH_FINDCHARINRANGE,
	NPPIDM_SEARCH_SELECTMATCHINGBRACES = IDM_SEARCH_SELECTMATCHINGBRACES,
	NPPIDM_SEARCH_MARK = IDM_SEARCH_MARK,
	NPPIDM_SEARCH_STYLE1TOCLIP = IDM_SEARCH_STYLE1TOCLIP,
	NPPIDM_SEARCH_STYLE2TOCLIP = IDM_SEARCH_STYLE2TOCLIP,
	NPPIDM_SEARCH_STYLE3TOCLIP = IDM_SEARCH_STYLE3TOCLIP,
	NPPIDM_SEARCH_STYLE4TOCLIP = IDM_SEARCH_STYLE4TOCLIP,
	NPPIDM_SEARCH_STYLE5TOCLIP = IDM_SEARCH_STYLE5TOCLIP,
	NPPIDM_SEARCH_ALLSTYLESTOCLIP = IDM_SEARCH_ALLSTYLESTOCLIP,
	NPPIDM_SEARCH_MARKEDTOCLIP = IDM_SEARCH_MARKEDTOCLIP,
	NPPIDM_SEARCH_MARKONEEXT1 = IDM_SEARCH_MARKONEEXT1,
	NPPIDM_SEARCH_MARKONEEXT2 = IDM_SEARCH_MARKONEEXT2,
	NPPIDM_SEARCH_MARKONEEXT3 = IDM_SEARCH_MARKONEEXT3,
	NPPIDM_SEARCH_MARKONEEXT4 = IDM_SEARCH_MARKONEEXT4,
	NPPIDM_SEARCH_MARKONEEXT5 = IDM_SEARCH_MARKONEEXT5,
	NPPIDM_SEARCH_CHANGED_NEXT = IDM_SEARCH_CHANGED_NEXT,
	NPPIDM_SEARCH_CHANGED_PREV = IDM_SEARCH_CHANGED_PREV,
	NPPIDM_SEARCH_CLEAR_CHANGE_HISTORY = IDM_SEARCH_CLEAR_CHANGE_HISTORY,
	NPPIDM_MISC = IDM_MISC,
	NPPIDM_DOCLIST_FILESCLOSE = IDM_DOCLIST_FILESCLOSE,
	NPPIDM_DOCLIST_FILESCLOSEOTHERS = IDM_DOCLIST_FILESCLOSEOTHERS,
	NPPIDM_DOCLIST_COPYNAMES = IDM_DOCLIST_COPYNAMES,
	NPPIDM_DOCLIST_COPYPATHS = IDM_DOCLIST_COPYPATHS,
	NPPIDM_VIEW = IDM_VIEW,
	NPPIDM_VIEW_TOOLBAR_REDUCE = IDM_VIEW_TOOLBAR_REDUCE,
	NPPIDM_VIEW_TOOLBAR_ENLARGE = IDM_VIEW_TOOLBAR_ENLARGE,
	NPPIDM_VIEW_TOOLBAR_STANDARD = IDM_VIEW_TOOLBAR_STANDARD,
	NPPIDM_VIEW_REDUCETABBAR = IDM_VIEW_REDUCETABBAR,
	NPPIDM_VIEW_LOCKTABBAR = IDM_VIEW_LOCKTABBAR,
	NPPIDM_VIEW_DRAWTABBAR_TOPBAR = IDM_VIEW_DRAWTABBAR_TOPBAR,
	NPPIDM_VIEW_DRAWTABBAR_INACIVETAB = IDM_VIEW_DRAWTABBAR_INACIVETAB,
	NPPIDM_VIEW_POSTIT = IDM_VIEW_POSTIT,
	NPPIDM_VIEW_FOLDALL = IDM_VIEW_FOLDALL,
	NPPIDM_VIEW_DISTRACTIONFREE = IDM_VIEW_DISTRACTIONFREE,
	NPPIDM_VIEW_LINENUMBER = IDM_VIEW_LINENUMBER,
	NPPIDM_VIEW_SYMBOLMARGIN = IDM_VIEW_SYMBOLMARGIN,
	NPPIDM_VIEW_FOLDERMAGIN = IDM_VIEW_FOLDERMAGIN,
	NPPIDM_VIEW_FOLDERMAGIN_SIMPLE = IDM_VIEW_FOLDERMAGIN_SIMPLE,
	NPPIDM_VIEW_FOLDERMAGIN_ARROW = IDM_VIEW_FOLDERMAGIN_ARROW,
	NPPIDM_VIEW_FOLDERMAGIN_CIRCLE = IDM_VIEW_FOLDERMAGIN_CIRCLE,
	NPPIDM_VIEW_FOLDERMAGIN_BOX = IDM_VIEW_FOLDERMAGIN_BOX,
	NPPIDM_VIEW_ALL_CHARACTERS = IDM_VIEW_ALL_CHARACTERS,
	NPPIDM_VIEW_INDENT_GUIDE = IDM_VIEW_INDENT_GUIDE,
	NPPIDM_VIEW_CURLINE_HILITING = IDM_VIEW_CURLINE_HILITING,
	NPPIDM_VIEW_WRAP = IDM_VIEW_WRAP,
	NPPIDM_VIEW_ZOOMIN = IDM_VIEW_ZOOMIN,
	NPPIDM_VIEW_ZOOMOUT = IDM_VIEW_ZOOMOUT,
	NPPIDM_VIEW_TAB_SPACE = IDM_VIEW_TAB_SPACE,
	NPPIDM_VIEW_EOL = IDM_VIEW_EOL,
	NPPIDM_VIEW_TOOLBAR_REDUCE_SET2 = IDM_VIEW_TOOLBAR_REDUCE_SET2,
	NPPIDM_VIEW_TOOLBAR_ENLARGE_SET2 = IDM_VIEW_TOOLBAR_ENLARGE_SET2,
	NPPIDM_VIEW_UNFOLDALL = IDM_VIEW_UNFOLDALL,
	NPPIDM_VIEW_FOLD_CURRENT = IDM_VIEW_FOLD_CURRENT,
	NPPIDM_VIEW_UNFOLD_CURRENT = IDM_VIEW_UNFOLD_CURRENT,
	NPPIDM_VIEW_FULLSCREENTOGGLE = IDM_VIEW_FULLSCREENTOGGLE,
	NPPIDM_VIEW_ZOOMRESTORE = IDM_VIEW_ZOOMRESTORE,
	NPPIDM_VIEW_ALWAYSONTOP = IDM_VIEW_ALWAYSONTOP,
	NPPIDM_VIEW_SYNSCROLLV = IDM_VIEW_SYNSCROLLV,
	NPPIDM_VIEW_SYNSCROLLH = IDM_VIEW_SYNSCROLLH,
	NPPIDM_VIEW_DRAWTABBAR_CLOSEBOTTUN = IDM_VIEW_DRAWTABBAR_CLOSEBOTTUN,
	NPPIDM_VIEW_DRAWTABBAR_DBCLK2CLOSE = IDM_VIEW_DRAWTABBAR_DBCLK2CLOSE,
	NPPIDM_VIEW_REFRESHTABAR = IDM_VIEW_REFRESHTABAR,
	NPPIDM_VIEW_WRAP_SYMBOL = IDM_VIEW_WRAP_SYMBOL,
	NPPIDM_VIEW_HIDELINES = IDM_VIEW_HIDELINES,
	NPPIDM_VIEW_DRAWTABBAR_VERTICAL = IDM_VIEW_DRAWTABBAR_VERTICAL,
	NPPIDM_VIEW_DRAWTABBAR_MULTILINE = IDM_VIEW_DRAWTABBAR_MULTILINE,
	NPPIDM_VIEW_LWDEF = IDM_VIEW_LWDEF,
	NPPIDM_VIEW_LWALIGN = IDM_VIEW_LWALIGN,
	NPPIDM_VIEW_LWINDENT = IDM_VIEW_LWINDENT,
	NPPIDM_VIEW_SUMMARY = IDM_VIEW_SUMMARY,
	NPPIDM_VIEW_FOLD = IDM_VIEW_FOLD,
	NPPIDM_VIEW_FOLD_1 = IDM_VIEW_FOLD_1,
	NPPIDM_VIEW_FOLD_2 = IDM_VIEW_FOLD_2,
	NPPIDM_VIEW_FOLD_3 = IDM_VIEW_FOLD_3,
	NPPIDM_VIEW_FOLD_4 = IDM_VIEW_FOLD_4,
	NPPIDM_VIEW_FOLD_5 = IDM_VIEW_FOLD_5,
	NPPIDM_VIEW_FOLD_6 = IDM_VIEW_FOLD_6,
	NPPIDM_VIEW_FOLD_7 = IDM_VIEW_FOLD_7,
	NPPIDM_VIEW_FOLD_8 = IDM_VIEW_FOLD_8,
	NPPIDM_VIEW_UNFOLD = IDM_VIEW_UNFOLD,
	NPPIDM_VIEW_UNFOLD_1 = IDM_VIEW_UNFOLD_1,
	NPPIDM_VIEW_UNFOLD_2 = IDM_VIEW_UNFOLD_2,
	NPPIDM_VIEW_UNFOLD_3 = IDM_VIEW_UNFOLD_3,
	NPPIDM_VIEW_UNFOLD_4 = IDM_VIEW_UNFOLD_4,
	NPPIDM_VIEW_UNFOLD_5 = IDM_VIEW_UNFOLD_5,
	NPPIDM_VIEW_UNFOLD_6 = IDM_VIEW_UNFOLD_6,
	NPPIDM_VIEW_UNFOLD_7 = IDM_VIEW_UNFOLD_7,
	NPPIDM_VIEW_UNFOLD_8 = IDM_VIEW_UNFOLD_8,
	NPPIDM_VIEW_DOCLIST = IDM_VIEW_DOCLIST,
	NPPIDM_VIEW_SWITCHTO_OTHER_VIEW = IDM_VIEW_SWITCHTO_OTHER_VIEW,
	NPPIDM_EXPORT_FUNC_LIST_AND_QUIT = IDM_EXPORT_FUNC_LIST_AND_QUIT,
	NPPIDM_VIEW_DOC_MAP = IDM_VIEW_DOC_MAP,
	NPPIDM_VIEW_PROJECT_PANEL_1 = IDM_VIEW_PROJECT_PANEL_1,
	NPPIDM_VIEW_PROJECT_PANEL_2 = IDM_VIEW_PROJECT_PANEL_2,
	NPPIDM_VIEW_PROJECT_PANEL_3 = IDM_VIEW_PROJECT_PANEL_3,
	NPPIDM_VIEW_FUNC_LIST = IDM_VIEW_FUNC_LIST,
	NPPIDM_VIEW_FILEBROWSER = IDM_VIEW_FILEBROWSER,
	NPPIDM_VIEW_TAB1 = IDM_VIEW_TAB1,
	NPPIDM_VIEW_TAB2 = IDM_VIEW_TAB2,
	NPPIDM_VIEW_TAB3 = IDM_VIEW_TAB3,
	NPPIDM_VIEW_TAB4 = IDM_VIEW_TAB4,
	NPPIDM_VIEW_TAB5 = IDM_VIEW_TAB5,
	NPPIDM_VIEW_TAB6 = IDM_VIEW_TAB6,
	NPPIDM_VIEW_TAB7 = IDM_VIEW_TAB7,
	NPPIDM_VIEW_TAB8 = IDM_VIEW_TAB8,
	NPPIDM_VIEW_TAB9 = IDM_VIEW_TAB9,
	NPPIDM_VIEW_TAB_NEXT = IDM_VIEW_TAB_NEXT,
	NPPIDM_VIEW_TAB_PREV = IDM_VIEW_TAB_PREV,
	NPPIDM_VIEW_MONITORING = IDM_VIEW_MONITORING,
	NPPIDM_VIEW_TAB_MOVEFORWARD = IDM_VIEW_TAB_MOVEFORWARD,
	NPPIDM_VIEW_TAB_MOVEBACKWARD = IDM_VIEW_TAB_MOVEBACKWARD,
	NPPIDM_VIEW_IN_FIREFOX = IDM_VIEW_IN_FIREFOX,
	NPPIDM_VIEW_IN_CHROME = IDM_VIEW_IN_CHROME,
	NPPIDM_VIEW_IN_EDGE = IDM_VIEW_IN_EDGE,
	NPPIDM_VIEW_IN_IE = IDM_VIEW_IN_IE,
	NPPIDM_VIEW_SWITCHTO_PROJECT_PANEL_1 = IDM_VIEW_SWITCHTO_PROJECT_PANEL_1,
	NPPIDM_VIEW_SWITCHTO_PROJECT_PANEL_2 = IDM_VIEW_SWITCHTO_PROJECT_PANEL_2,
	NPPIDM_VIEW_SWITCHTO_PROJECT_PANEL_3 = IDM_VIEW_SWITCHTO_PROJECT_PANEL_3,
	NPPIDM_VIEW_SWITCHTO_FILEBROWSER = IDM_VIEW_SWITCHTO_FILEBROWSER,
	NPPIDM_VIEW_SWITCHTO_FUNC_LIST = IDM_VIEW_SWITCHTO_FUNC_LIST,
	NPPIDM_VIEW_SWITCHTO_DOCLIST = IDM_VIEW_SWITCHTO_DOCLIST,
	NPPIDM_VIEW_TAB_COLOUR_NONE = IDM_VIEW_TAB_COLOUR_NONE,
	NPPIDM_VIEW_TAB_COLOUR_1 = IDM_VIEW_TAB_COLOUR_1,
	NPPIDM_VIEW_TAB_COLOUR_2 = IDM_VIEW_TAB_COLOUR_2,
	NPPIDM_VIEW_TAB_COLOUR_3 = IDM_VIEW_TAB_COLOUR_3,
	NPPIDM_VIEW_TAB_COLOUR_4 = IDM_VIEW_TAB_COLOUR_4,
	NPPIDM_VIEW_TAB_COLOUR_5 = IDM_VIEW_TAB_COLOUR_5,
	NPPIDM_VIEW_TAB_START = IDM_VIEW_TAB_START,
	NPPIDM_VIEW_TAB_END = IDM_VIEW_TAB_END,
	NPPIDM_VIEW_NPC = IDM_VIEW_NPC,
	NPPIDM_VIEW_NPC_CCUNIEOL = IDM_VIEW_NPC_CCUNIEOL,
	NPPIDM_VIEW_GOTO_ANOTHER_VIEW = IDM_VIEW_GOTO_ANOTHER_VIEW,
	NPPIDM_VIEW_CLONE_TO_ANOTHER_VIEW = IDM_VIEW_CLONE_TO_ANOTHER_VIEW,
	NPPIDM_VIEW_GOTO_NEW_INSTANCE = IDM_VIEW_GOTO_NEW_INSTANCE,
	NPPIDM_VIEW_LOAD_IN_NEW_INSTANCE = IDM_VIEW_LOAD_IN_NEW_INSTANCE,
	NPPIDM_VIEW_GOTO_START = IDM_VIEW_GOTO_START,
	NPPIDM_VIEW_GOTO_END = IDM_VIEW_GOTO_END,
	NPPIDM_FORMAT = IDM_FORMAT,
	NPPIDM_FORMAT_TODOS = IDM_FORMAT_TODOS,
	NPPIDM_FORMAT_TOUNIX = IDM_FORMAT_TOUNIX,
	NPPIDM_FORMAT_TOMAC = IDM_FORMAT_TOMAC,
	NPPIDM_FORMAT_ANSI = IDM_FORMAT_ANSI,
	NPPIDM_FORMAT_UTF_8 = IDM_FORMAT_UTF_8,
	NPPIDM_FORMAT_UTF_16BE = IDM_FORMAT_UTF_16BE,
	NPPIDM_FORMAT_UTF_16LE = IDM_FORMAT_UTF_16LE,
	NPPIDM_FORMAT_AS_UTF_8 = IDM_FORMAT_AS_UTF_8,
	NPPIDM_FORMAT_CONV2_ANSI = IDM_FORMAT_CONV2_ANSI,
	NPPIDM_FORMAT_CONV2_AS_UTF_8 = IDM_FORMAT_CONV2_AS_UTF_8,
	NPPIDM_FORMAT_CONV2_UTF_8 = IDM_FORMAT_CONV2_UTF_8,
	NPPIDM_FORMAT_CONV2_UTF_16BE = IDM_FORMAT_CONV2_UTF_16BE,
	NPPIDM_FORMAT_CONV2_UTF_16LE = IDM_FORMAT_CONV2_UTF_16LE,
	NPPIDM_FORMAT_ENCODE = IDM_FORMAT_ENCODE,
	NPPIDM_FORMAT_WIN_1250 = IDM_FORMAT_WIN_1250,
	NPPIDM_FORMAT_WIN_1251 = IDM_FORMAT_WIN_1251,
	NPPIDM_FORMAT_WIN_1252 = IDM_FORMAT_WIN_1252,
	NPPIDM_FORMAT_WIN_1253 = IDM_FORMAT_WIN_1253,
	NPPIDM_FORMAT_WIN_1254 = IDM_FORMAT_WIN_1254,
	NPPIDM_FORMAT_WIN_1255 = IDM_FORMAT_WIN_1255,
	NPPIDM_FORMAT_WIN_1256 = IDM_FORMAT_WIN_1256,
	NPPIDM_FORMAT_WIN_1257 = IDM_FORMAT_WIN_1257,
	NPPIDM_FORMAT_WIN_1258 = IDM_FORMAT_WIN_1258,
	NPPIDM_FORMAT_ISO_8859_1 = IDM_FORMAT_ISO_8859_1,
	NPPIDM_FORMAT_ISO_8859_2 = IDM_FORMAT_ISO_8859_2,
	NPPIDM_FORMAT_ISO_8859_3 = IDM_FORMAT_ISO_8859_3,
	NPPIDM_FORMAT_ISO_8859_4 = IDM_FORMAT_ISO_8859_4,
	NPPIDM_FORMAT_ISO_8859_5 = IDM_FORMAT_ISO_8859_5,
	NPPIDM_FORMAT_ISO_8859_6 = IDM_FORMAT_ISO_8859_6,
	NPPIDM_FORMAT_ISO_8859_7 = IDM_FORMAT_ISO_8859_7,
	NPPIDM_FORMAT_ISO_8859_8 = IDM_FORMAT_ISO_8859_8,
	NPPIDM_FORMAT_ISO_8859_9 = IDM_FORMAT_ISO_8859_9,
	NPPIDM_FORMAT_ISO_8859_13 = IDM_FORMAT_ISO_8859_13,
	NPPIDM_FORMAT_ISO_8859_14 = IDM_FORMAT_ISO_8859_14,
	NPPIDM_FORMAT_ISO_8859_15 = IDM_FORMAT_ISO_8859_15,
	NPPIDM_FORMAT_DOS_437 = IDM_FORMAT_DOS_437,
	NPPIDM_FORMAT_DOS_720 = IDM_FORMAT_DOS_720,
	NPPIDM_FORMAT_DOS_737 = IDM_FORMAT_DOS_737,
	NPPIDM_FORMAT_DOS_775 = IDM_FORMAT_DOS_775,
	NPPIDM_FORMAT_DOS_850 = IDM_FORMAT_DOS_850,
	NPPIDM_FORMAT_DOS_852 = IDM_FORMAT_DOS_852,
	NPPIDM_FORMAT_DOS_855 = IDM_FORMAT_DOS_855,
	NPPIDM_FORMAT_DOS_857 = IDM_FORMAT_DOS_857,
	NPPIDM_FORMAT_DOS_858 = IDM_FORMAT_DOS_858,
	NPPIDM_FORMAT_DOS_860 = IDM_FORMAT_DOS_860,
	NPPIDM_FORMAT_DOS_861 = IDM_FORMAT_DOS_861,
	NPPIDM_FORMAT_DOS_862 = IDM_FORMAT_DOS_862,
	NPPIDM_FORMAT_DOS_863 = IDM_FORMAT_DOS_863,
	NPPIDM_FORMAT_DOS_865 = IDM_FORMAT_DOS_865,
	NPPIDM_FORMAT_DOS_866 = IDM_FORMAT_DOS_866,
	NPPIDM_FORMAT_DOS_869 = IDM_FORMAT_DOS_869,
	NPPIDM_FORMAT_BIG5 = IDM_FORMAT_BIG5,
	NPPIDM_FORMAT_GB2312 = IDM_FORMAT_GB2312,
	NPPIDM_FORMAT_SHIFT_JIS = IDM_FORMAT_SHIFT_JIS,
	NPPIDM_FORMAT_KOREAN_WIN = IDM_FORMAT_KOREAN_WIN,
	NPPIDM_FORMAT_EUC_KR = IDM_FORMAT_EUC_KR,
	NPPIDM_FORMAT_TIS_620 = IDM_FORMAT_TIS_620,
	NPPIDM_FORMAT_MAC_CYRILLIC = IDM_FORMAT_MAC_CYRILLIC,
	NPPIDM_FORMAT_KOI8U_CYRILLIC = IDM_FORMAT_KOI8U_CYRILLIC,
	NPPIDM_FORMAT_KOI8R_CYRILLIC = IDM_FORMAT_KOI8R_CYRILLIC,
	NPPIDM_FORMAT_ENCODE_END = IDM_FORMAT_ENCODE_END,
	NPPIDM_LANG = IDM_LANG,
	NPPIDM_LANGSTYLE_CONFIG_DLG = IDM_LANGSTYLE_CONFIG_DLG,
	NPPIDM_LANG_C = IDM_LANG_C,
	NPPIDM_LANG_CPP = IDM_LANG_CPP,
	NPPIDM_LANG_JAVA = IDM_LANG_JAVA,
	NPPIDM_LANG_HTML = IDM_LANG_HTML,
	NPPIDM_LANG_XML = IDM_LANG_XML,
	NPPIDM_LANG_JS = IDM_LANG_JS,
	NPPIDM_LANG_PHP = IDM_LANG_PHP,
	NPPIDM_LANG_ASP = IDM_LANG_ASP,
	NPPIDM_LANG_CSS = IDM_LANG_CSS,
	NPPIDM_LANG_PASCAL = IDM_LANG_PASCAL,
	NPPIDM_LANG_PYTHON = IDM_LANG_PYTHON,
	NPPIDM_LANG_PERL = IDM_LANG_PERL,
	NPPIDM_LANG_OBJC = IDM_LANG_OBJC,
	NPPIDM_LANG_ASCII = IDM_LANG_ASCII,
	NPPIDM_LANG_TEXT = IDM_LANG_TEXT,
	NPPIDM_LANG_RC = IDM_LANG_RC,
	NPPIDM_LANG_MAKEFILE = IDM_LANG_MAKEFILE,
	NPPIDM_LANG_INI = IDM_LANG_INI,
	NPPIDM_LANG_SQL = IDM_LANG_SQL,
	NPPIDM_LANG_VB = IDM_LANG_VB,
	NPPIDM_LANG_BATCH = IDM_LANG_BATCH,
	NPPIDM_LANG_CS = IDM_LANG_CS,
	NPPIDM_LANG_LUA = IDM_LANG_LUA,
	NPPIDM_LANG_TEX = IDM_LANG_TEX,
	NPPIDM_LANG_FORTRAN = IDM_LANG_FORTRAN,
	NPPIDM_LANG_BASH = IDM_LANG_BASH,
	NPPIDM_LANG_FLASH = IDM_LANG_FLASH,
	NPPIDM_LANG_NSIS = IDM_LANG_NSIS,
	NPPIDM_LANG_TCL = IDM_LANG_TCL,
	NPPIDM_LANG_LISP = IDM_LANG_LISP,
	NPPIDM_LANG_SCHEME = IDM_LANG_SCHEME,
	NPPIDM_LANG_ASM = IDM_LANG_ASM,
	NPPIDM_LANG_DIFF = IDM_LANG_DIFF,
	NPPIDM_LANG_PROPS = IDM_LANG_PROPS,
	NPPIDM_LANG_PS = IDM_LANG_PS,
	NPPIDM_LANG_RUBY = IDM_LANG_RUBY,
	NPPIDM_LANG_SMALLTALK = IDM_LANG_SMALLTALK,
	NPPIDM_LANG_VHDL = IDM_LANG_VHDL,
	NPPIDM_LANG_CAML = IDM_LANG_CAML,
	NPPIDM_LANG_KIX = IDM_LANG_KIX,
	NPPIDM_LANG_ADA = IDM_LANG_ADA,
	NPPIDM_LANG_VERILOG = IDM_LANG_VERILOG,
	NPPIDM_LANG_AU3 = IDM_LANG_AU3,
	NPPIDM_LANG_MATLAB = IDM_LANG_MATLAB,
	NPPIDM_LANG_HASKELL = IDM_LANG_HASKELL,
	NPPIDM_LANG_INNO = IDM_LANG_INNO,
	NPPIDM_LANG_CMAKE = IDM_LANG_CMAKE,
	NPPIDM_LANG_YAML = IDM_LANG_YAML,
	NPPIDM_LANG_COBOL = IDM_LANG_COBOL,
	NPPIDM_LANG_D = IDM_LANG_D,
	NPPIDM_LANG_GUI4CLI = IDM_LANG_GUI4CLI,
	NPPIDM_LANG_POWERSHELL = IDM_LANG_POWERSHELL,
	NPPIDM_LANG_R = IDM_LANG_R,
	NPPIDM_LANG_JSP = IDM_LANG_JSP,
	NPPIDM_LANG_COFFEESCRIPT = IDM_LANG_COFFEESCRIPT,
	NPPIDM_LANG_JSON = IDM_LANG_JSON,
	NPPIDM_LANG_FORTRAN_77 = IDM_LANG_FORTRAN_77,
	NPPIDM_LANG_BAANC = IDM_LANG_BAANC,
	NPPIDM_LANG_SREC = IDM_LANG_SREC,
	NPPIDM_LANG_IHEX = IDM_LANG_IHEX,
	NPPIDM_LANG_TEHEX = IDM_LANG_TEHEX,
	NPPIDM_LANG_SWIFT = IDM_LANG_SWIFT,
	NPPIDM_LANG_ASN1 = IDM_LANG_ASN1,
	NPPIDM_LANG_AVS = IDM_LANG_AVS,
	NPPIDM_LANG_BLITZBASIC = IDM_LANG_BLITZBASIC,
	NPPIDM_LANG_PUREBASIC = IDM_LANG_PUREBASIC,
	NPPIDM_LANG_FREEBASIC = IDM_LANG_FREEBASIC,
	NPPIDM_LANG_CSOUND = IDM_LANG_CSOUND,
	NPPIDM_LANG_ERLANG = IDM_LANG_ERLANG,
	NPPIDM_LANG_ESCRIPT = IDM_LANG_ESCRIPT,
	NPPIDM_LANG_FORTH = IDM_LANG_FORTH,
	NPPIDM_LANG_LATEX = IDM_LANG_LATEX,
	NPPIDM_LANG_MMIXAL = IDM_LANG_MMIXAL,
	NPPIDM_LANG_NIM = IDM_LANG_NIM,
	NPPIDM_LANG_NNCRONTAB = IDM_LANG_NNCRONTAB,
	NPPIDM_LANG_OSCRIPT = IDM_LANG_OSCRIPT,
	NPPIDM_LANG_REBOL = IDM_LANG_REBOL,
	NPPIDM_LANG_REGISTRY = IDM_LANG_REGISTRY,
	NPPIDM_LANG_RUST = IDM_LANG_RUST,
	NPPIDM_LANG_SPICE = IDM_LANG_SPICE,
	NPPIDM_LANG_TXT2TAGS = IDM_LANG_TXT2TAGS,
	NPPIDM_LANG_VISUALPROLOG = IDM_LANG_VISUALPROLOG,
	NPPIDM_LANG_TYPESCRIPT = IDM_LANG_TYPESCRIPT,
	NPPIDM_LANG_JSON5 = IDM_LANG_JSON5,
	NPPIDM_LANG_MSSQL = IDM_LANG_MSSQL,
	NPPIDM_LANG_GDSCRIPT = IDM_LANG_GDSCRIPT,
	NPPIDM_LANG_HOLLYWOOD = IDM_LANG_HOLLYWOOD,
	NPPIDM_LANG_EXTERNAL = IDM_LANG_EXTERNAL,
	NPPIDM_LANG_EXTERNAL_LIMIT = IDM_LANG_EXTERNAL_LIMIT,
	NPPIDM_LANG_USER = IDM_LANG_USER,
	NPPIDM_LANG_USER_LIMIT = IDM_LANG_USER_LIMIT,
	NPPIDM_LANG_USER_DLG = IDM_LANG_USER_DLG,
	NPPIDM_LANG_OPENUDLDIR = IDM_LANG_OPENUDLDIR,
	NPPIDM_LANG_UDLCOLLECTION_PROJECT_SITE = IDM_LANG_UDLCOLLECTION_PROJECT_SITE,
	NPPIDM_ABOUT = IDM_ABOUT,
	NPPIDM_HOMESWEETHOME = IDM_HOMESWEETHOME,
	NPPIDM_PROJECTPAGE = IDM_PROJECTPAGE,
	NPPIDM_ONLINEDOCUMENT = IDM_ONLINEDOCUMENT,
	NPPIDM_FORUM = IDM_FORUM,
	NPPIDM_UPDATE_NPP = IDM_UPDATE_NPP,
	NPPIDM_WIKIFAQ = IDM_WIKIFAQ,
	NPPIDM_CONFUPDATERPROXY = IDM_CONFUPDATERPROXY,
	NPPIDM_CMDLINEARGUMENTS = IDM_CMDLINEARGUMENTS,
	NPPIDM_DEBUGINFO = IDM_DEBUGINFO,
	NPPIDM_SETTING = IDM_SETTING,
	NPPIDM_SETTING_IMPORTPLUGIN = IDM_SETTING_IMPORTPLUGIN,
	NPPIDM_SETTING_IMPORTSTYLETHEMES = IDM_SETTING_IMPORTSTYLETHEMES,
	NPPIDM_SETTING_TRAYICON = IDM_SETTING_TRAYICON,
	NPPIDM_SETTING_SHORTCUT_MAPPER = IDM_SETTING_SHORTCUT_MAPPER,
	NPPIDM_SETTING_REMEMBER_LAST_SESSION = IDM_SETTING_REMEMBER_LAST_SESSION,
	NPPIDM_SETTING_PREFERENCE = IDM_SETTING_PREFERENCE,
	NPPIDM_SETTING_OPENPLUGINSDIR = IDM_SETTING_OPENPLUGINSDIR,
	NPPIDM_SETTING_PLUGINADM = IDM_SETTING_PLUGINADM,
	NPPIDM_SETTING_SHORTCUT_MAPPER_MACRO = IDM_SETTING_SHORTCUT_MAPPER_MACRO,
	NPPIDM_SETTING_SHORTCUT_MAPPER_RUN = IDM_SETTING_SHORTCUT_MAPPER_RUN,
	NPPIDM_SETTING_EDITCONTEXTMENU = IDM_SETTING_EDITCONTEXTMENU,
	NPPIDM_TOOL = IDM_TOOL,
	NPPIDM_TOOL_MD5_GENERATE = IDM_TOOL_MD5_GENERATE,
	NPPIDM_TOOL_MD5_GENERATEFROMFILE = IDM_TOOL_MD5_GENERATEFROMFILE,
	NPPIDM_TOOL_MD5_GENERATEINTOCLIPBOARD = IDM_TOOL_MD5_GENERATEINTOCLIPBOARD,
	NPPIDM_TOOL_SHA256_GENERATE = IDM_TOOL_SHA256_GENERATE,
	NPPIDM_TOOL_SHA256_GENERATEFROMFILE = IDM_TOOL_SHA256_GENERATEFROMFILE,
	NPPIDM_TOOL_SHA256_GENERATEINTOCLIPBOARD = IDM_TOOL_SHA256_GENERATEINTOCLIPBOARD,
	NPPIDM_TOOL_SHA1_GENERATE = IDM_TOOL_SHA1_GENERATE,
	NPPIDM_TOOL_SHA1_GENERATEFROMFILE = IDM_TOOL_SHA1_GENERATEFROMFILE,
	NPPIDM_TOOL_SHA1_GENERATEINTOCLIPBOARD = IDM_TOOL_SHA1_GENERATEINTOCLIPBOARD,
	NPPIDM_TOOL_SHA512_GENERATE = IDM_TOOL_SHA512_GENERATE,
	NPPIDM_TOOL_SHA512_GENERATEFROMFILE = IDM_TOOL_SHA512_GENERATEFROMFILE,
	NPPIDM_TOOL_SHA512_GENERATEINTOCLIPBOARD = IDM_TOOL_SHA512_GENERATEINTOCLIPBOARD,
	NPPIDM_EXECUTE = IDM_EXECUTE,
	NPPIDM_SYSTRAYPOPUP = IDM_SYSTRAYPOPUP,
	NPPIDM_SYSTRAYPOPUP_ACTIVATE = IDM_SYSTRAYPOPUP_ACTIVATE,
	NPPIDM_SYSTRAYPOPUP_NEWDOC = IDM_SYSTRAYPOPUP_NEWDOC,
	NPPIDM_SYSTRAYPOPUP_NEW_AND_PASTE = IDM_SYSTRAYPOPUP_NEW_AND_PASTE,
	NPPIDM_SYSTRAYPOPUP_OPENFILE = IDM_SYSTRAYPOPUP_OPENFILE,
	NPPIDM_SYSTRAYPOPUP_CLOSE = IDM_SYSTRAYPOPUP_CLOSE,
	NPPIDM_WINDOW_WINDOWS = IDM_WINDOW_WINDOWS,
	NPPIDM_WINDOW_SORT_FN_ASC = IDM_WINDOW_SORT_FN_ASC,
	NPPIDM_WINDOW_SORT_FN_DSC = IDM_WINDOW_SORT_FN_DSC,
	NPPIDM_WINDOW_SORT_FP_ASC = IDM_WINDOW_SORT_FP_ASC,
	NPPIDM_WINDOW_SORT_FP_DSC = IDM_WINDOW_SORT_FP_DSC,
	NPPIDM_WINDOW_SORT_FT_ASC = IDM_WINDOW_SORT_FT_ASC,
	NPPIDM_WINDOW_SORT_FT_DSC = IDM_WINDOW_SORT_FT_DSC,
	NPPIDM_WINDOW_SORT_FS_ASC = IDM_WINDOW_SORT_FS_ASC,
	NPPIDM_WINDOW_SORT_FS_DSC = IDM_WINDOW_SORT_FS_DSC,
	NPPIDM_WINDOW_MRU_FIRST = IDM_WINDOW_MRU_FIRST,
	NPPIDM_WINDOW_MRU_LIMIT = IDM_WINDOW_MRU_LIMIT,
	NPPIDM_WINDOW_COPY_NAME = IDM_WINDOW_COPY_NAME,
	NPPIDM_WINDOW_COPY_PATH = IDM_WINDOW_COPY_PATH,
	NPPIDM_DROPLIST_LIST = IDM_DROPLIST_LIST,
	NPPIDM_DROPLIST_MRU_FIRST = IDM_DROPLIST_MRU_FIRST
};


class NotepadPlusWrapper
{
public:
	NotepadPlusWrapper(HINSTANCE hInst, HWND nppHandle);
	~NotepadPlusWrapper();

	void notify(SCNotification *notifyCode);

	void newDocument();
	bool newDocumentWithFilename(const char *filename);

	bool save();
	bool saveAs(const char *filename);
	bool saveAsCopy(const char *filename);

	bool open(const char *filename);

	bool activateFile(const char *filename);
	int getCurrentView();
	LangType getCurrentLangType();
	void setCurrentLangType(LangType lang);

	void outputDebugString(const char *s) { OutputDebugStringA(s); }

	boost::python::list getFiles();


	boost::python::list getSessionFiles(const char *sessionFilename);

	void saveSession(const char *sessionFilename, boost::python::list files);
	void saveCurrentSession(const char *filename);

	boost::shared_ptr<ScintillaWrapper> createScintilla();
	void destroyScintilla(boost::shared_ptr<ScintillaWrapper> buffer);

	intptr_t getCurrentDocIndex(int view);

	void setStatusBar(StatusBarSection section, const char *text);

	intptr_t getPluginMenuHandle();
	
	intptr_t hwnd;

	void activateIndex(int view, int index);

	void activateBufferID(intptr_t bufferID);

	void loadSession(boost::python::str filename);

	bool activateFileString(boost::python::str filename);

	bool reloadFile(boost::python::str filename, bool withAlert);

	bool saveAllFiles();

	boost::python::str getPluginConfigDir();

	boost::python::str getPluginHomePath();

	boost::python::str getSettingsOnCloudPath();

	intptr_t getBookMarkID();

	void menuCommand(int commandID);

	boost::python::tuple getVersion();

	bool hideTabBar();

	bool showTabBar();

	intptr_t getCurrentBufferID();

	void reloadBuffer(intptr_t bufferID, bool withAlert = true);

	LangType getLangType();

	LangType getBufferLangType(intptr_t bufferID);


	void setBufferLangType(LangType lang, intptr_t bufferID);

	BufferEncoding getEncoding();

	BufferEncoding getBufferEncoding(intptr_t bufferID);

	bool setEncoding(BufferEncoding encoding);

	bool setBufferEncoding(BufferEncoding encoding, intptr_t bufferID);

	FormatType getFormatType();

	FormatType getBufferFormatType(intptr_t bufferID);

	bool setFormatType(FormatType format);

	bool setBufferFormatType(FormatType format, intptr_t bufferID);

	void closeDocument();

	void closeAllDocuments();

	void closeAllButCurrentDocument();

	void reloadCurrentDocument();

	intptr_t getMenuHandle(int menu);

	bool isTabBarHidden();

	bool hideToolBar(bool hideOrNot);

	bool isToolBarHidden();

	bool hideMenu(bool hideOrNot);

	bool isMenuHidden();

	bool hideStatusBar(bool hideOrNot);

	bool isStatusBarHidden();

	bool saveFile(boost::python::str filename);

	void showDocSwitcher(bool showOrNot);

	bool isDocSwitcherShown();

	void docSwitcherDisableExtColumn(bool disableOrNot);

	void docSwitcherDisablePathColumn(bool disableOrNot);

	bool isDarkModeEnabled();

	intptr_t getCurrentNativeLangEncoding();

	boost::python::str getLanguageName(int langType);

	boost::python::str getLanguageDesc(int langType);

	bool getAppdataPluginsAllowed();

	boost::python::tuple getEditorDefaultForegroundColor();

	boost::python::tuple getEditorDefaultBackgroundColor();

	void setSmoothFont(bool setSmoothFontOrNot);

	void setEditorBorderEdge(bool withEditorBorderEdgeOrNot);

	intptr_t getNbUserLang();

	intptr_t encodeSci(int view);

	intptr_t decodeSci(int view);

	void launchFindInFilesDlg(std::wstring dir2Search, std::wstring filter);

	winVer getWindowsVersion();

	bool makeCurrentBufferDirty();

	bool getEnableThemeTextureFunc();

	void triggerTabbarContextMenu(int view, int index2Activate);

	void disableAutoUpdate();

	int messageBox(const char *message, const char *title, UINT flags);
	int messageBoxNoFlags(const char *message, const char *title)
			{ return messageBox(message, title, 0); };
	int messageBoxNoTitle(const char *message)
			{ return messageBox(message, "Python Script for Notepad++", 0); };

	boost::python::object prompt(boost::python::object promptObj, boost::python::object title, boost::python::object initial);
	boost::python::object promptDefault(boost::python::object promptObj, boost::python::object title)
		{ return prompt(promptObj, title, boost::python::object()); };

	boost::python::str getBufferFilename(intptr_t bufferID);
	boost::python::str getCurrentFilename();
	boost::python::str getNppDir();
	boost::python::str getCommandLine();

	bool runPluginCommand(boost::python::str pluginName, boost::python::str menuOption, bool refreshCache);
	bool runPluginCommandNoRefresh(boost::python::str pluginName, boost::python::str menuOption)
			{	return runPluginCommand(pluginName, menuOption, false); };

	bool runMenuCommand(boost::python::str menuName, boost::python::str menuOption, bool refreshCache);
	bool runMenuCommandNoRefresh(boost::python::str menuName, boost::python::str menuOption)
			{	return runMenuCommand(menuName, menuOption, false); };

	bool addCallback(boost::python::object callback, boost::python::list events);

	void clearAllCallbacks();
	void clearCallbackFunction(boost::python::object callback);
	void clearCallbackEvents(boost::python::list events);
	void clearCallback(boost::python::object callback, boost::python::list events);

	bool allocateSupported();
	boost::python::object allocateCmdID(int quantity);
	boost::python::object allocateMarker(int quantity);
	boost::python::object allocateIndicator(int quantity);

	typedef std::multimap<idx_t, boost::python::object> callbackT;

	boost::python::str getPluginVersion();

	bool isSingleView();
	void flashWindow(UINT count, DWORD timeout) const;

protected:
	LRESULT callNotepad(UINT message, WPARAM wParam = 0, LPARAM lParam = 0)
	{
		GILRelease release;
		return SendMessage(m_nppHandle, message, wParam, lParam);
	}


private:
	NotepadPlusWrapper(); // default constructor disabled

	HWND m_nppHandle;
	HINSTANCE m_hInst;

	callbackT m_callbacks;
	bool m_notificationsEnabled;
	HANDLE m_callbackMutex;

	void notAllowedInScintillaCallback(const char *message);
	bool checkForValidBuffer(intptr_t bufferID);
	void invalidValueProvided(const char *message);
	bool handleFileNameToLongPath(UINT nppmID, boost::python::str filename, WPARAM wParam = 0);
};
}
#endif
