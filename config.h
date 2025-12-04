/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 1;                    /* -c option; centers dmenu on screen */
static int min_width = 700;                    /* minimum width when centered */
static float menu_height_ratio = 4.0f;  /* This is the ratio used in the original calculation */
static int fuzzy  = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static int horizpadbar = 5;                 /* horizontal padding */
static int vertpadbar = 5;                  /* vertical padding */
static const unsigned int alpha = 0xee;     /* Amount of opacity. 0xff is opaque             */
/* -fn option overrides fonts[0]; default X11 font or font set */
static char font[] = "monospace:size=10";
static const char *fonts[] = {
	font,
	"monospace:size=10"
};

static char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

static char normfgcolor[] = "#bbbbbb";
static char normbgcolor[] = "#222222";
static char selfgcolor[]  = "#eeeeee";
static char selbgcolor[]  = "#005577";
static char selhighlightfgcolor[]  = "#ffc978";
static char selhighlightbgcolor[]  = "#005577";
static char normhighlightfgcolor[] = "#ffc978";
static char normhighlightbgcolor[] = "#222222";
static char outfgcolor[] = "#000000";
static char outbgcolor[] = "#00ffff";
static char *colors[SchemeLast][2] = {
	/*                          fg                    bg       */
	[SchemeNorm]           =  { normfgcolor,          normbgcolor },
	[SchemeSel]            =  { selfgcolor,           selbgcolor  },
	[SchemeSelHighlight]   =  { selhighlightfgcolor,  selhighlightbgcolor },
	[SchemeNormHighlight]  =  { normhighlightfgcolor, normhighlightbgcolor },
	[SchemeOut]            =  { outfgcolor,           outbgcolor },
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 7;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
	{ "font",                 STRING,  &font },
	{ "normfgcolor",          STRING,  &normfgcolor },
	{ "normbgcolor",          STRING,  &normbgcolor },
	{ "selfgcolor",           STRING,  &selfgcolor },
	{ "selhighlightfgcolor",  STRING,  &selhighlightfgcolor },
	{ "selhighlightbgcolor",  STRING,  &selhighlightbgcolor },
	{ "normhighlightfgcolor", STRING,  &normhighlightfgcolor },
	{ "normhighlightbgcolor", STRING,  &normhighlightbgcolor },
	{ "outfgcolor",           STRING,  &outfgcolor },
	{ "outbgcolor",           STRING,  &outbgcolor },
	{ "prompt",               STRING,  &prompt },
	{ "topbar",               INTEGER, &topbar },
	{ "centered",             INTEGER, &centered },
	{ "min_width",            INTEGER, &min_width },
	{ "menu_height_ratio",    FLOAT,   &menu_height_ratio },
	{ "fuzzy",                INTEGER, &fuzzy },
	{ "horizpadbar",          INTEGER, &horizpadbar },
	{ "vertpadbar",           INTEGER, &vertpadbar },
};