// Read docs/configuring.h for more information on
// how to configure AWM.

#include <X11/keysym.h>


// Modifiers
#define MOD4                   XCB_MOD_MASK_4


// Autostart
char* abs_path_conf = "~/.config/awm/autostart"; // Autostart config file
char* default_shell = "/bin/bash ";              // The shell to run autostart script

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
	{ MOD4,      XK_Return, spawn,      termcmd }, // Execute terminal
	{ MOD4,      XK_space,  spawn,      menucmd }, // Run program launcher
  { MOD4,      XK_p,      spawn,      scrcmd  }, // Execute maim
	{ MOD4,      XK_f,      fullclient, NULL },    // Full screen active window
	{ MOD4,      XK_q,      killclient, NULL },    // Kill active window
};

/******************************************************************************************************************/

#define WORKSPACES 3		// Amonut of workspaces

// Workspace IDs
// format if you want to add more workspaces:
// [WORKSPACE NUMBER]0000 | Example: Workspace1 = 10000
#define WORKSPACE_ID_0 00000	// Workspace 1
#define WORKSPACE_ID_1 10000	// Workspace 2
#define WORKSPACE_ID_2 20000	// Workspace 3

// If you want to, you can set certain applications to start on certain workspaces
static ForceWorkspace force_apps[] = {
	// fmt: {[Application], [workspace id]}
	{ "urxvt", WORKSPACE_ID_0 } 					// Force urxvt onto workspace 0 (workspace 1)
};
