// Read docs/configuring.h for more information on
// how to configure AWM.

#include <X11/keysym.h>


// Modifiers
#define MOD4                   XCB_MOD_MASK_4


// Autostart
char* abs_path_conf = "/home/$(whoami)/.config/awm/autostart";
char* default_shell = "/bin/bash ";                             // The shell that awm will use to run autostart script with

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

// Keybinds
static Key keys[] = {
	{ MOD4,      XK_Return, spawn,      termcmd }, // Execute terminal
	{ MOD4,      XK_space,  spawn,      menucmd }, // Run program launcher
	{ MOD4,      XK_f,      fullclient, NULL },    // Full screen active window
	{ MOD4,      XK_q,      killclient, NULL },    // Kill active window
};

