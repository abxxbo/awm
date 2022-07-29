#include <X11/keysym.h>


// Modifiers
#define MOD4                   XCB_MOD_MASK_4


// Autostart
const char* autostart_cmd = "/bin/bash ~/.config/awm/autostart";

// Window parameters
#define WINDOW_WIDTH           600      
#define WINDOW_HEIGHT          400      
#define WINDOW_MIN_W           60       // Minimum size, in px
#define WINDOW_MIN_H           40       // Minimum size, in px
#define BORDER_WIDTH           1        // px
#define BORDER_COLOR_UNFOCUSED 0x696969 // fmt: 0xRRGGBB
#define BORDER_COLOR_FOCUSED   0xFFFFFF // fmt: 0xRRGGBB

// Aliased commands
static char *termcmd[] = { "urxvt", NULL };
static char *menucmd[] = { "rofi", "-show", "run", NULL };
static char *scrcmd[]  = { "maim", "-s", "-u", "|", "xclip", "-se", "c", "-t", "image/png", NULL };

// Keybinds
static Key keys[] = {
	{ MOD4, 	 XK_Return, spawn,      termcmd }, // Execute terminal
	{ MOD4,      XK_space,  spawn,      menucmd }, // Run program launcher
    { MOD4,      XK_p,      spawn,      scrcmd  }, // Execute maim
	{ MOD4,      XK_f,      fullclient, NULL },    // Full screen active window
	{ MOD4,      XK_q,      killclient, NULL },    // Kill active window
};
