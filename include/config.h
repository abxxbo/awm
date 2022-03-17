#pragma once

#include <xcb/xcb_keysyms.h>
#include <xcb/xcb.h>

#include "exec.h"

/* Modifier masks */
#define MOD1    XCB_MOD_MASK_1    // Alt
#define MOD4    XCB_MOD_MASK_4    // Super

#define XKEnter 0xff0d
#define XKSpace 0x0020

/* Window properties */
#define WINDOW_WIDTH    600
#define WINDOW_HEIGHT   400
#define WINDOW_MIN_W    60        // Smallest possible width
#define WINDOW_MIN_H    40        // Smallest possible height

/* Border */
#define BORDER_WIDTH            1         // in px
#define BORDER_COLOR_UNFOCUSED  0x696969  // Unfocused border color (RRGGBB)
#define BORDER_COLOR_FOCUSED    0xFFFFFF  // Focused border color

/* Commands */
static char* termcmd[] = { "urxvt", NULL };
static char* menucmd[] = { "rofi", "-show", "run", NULL };


/* Key aliases */
static Key keys[] = {
	{ MOD1,      0xff0d, spawn,      termcmd }, /* 0xff0d = XK_Enter */
	{ MOD1,      0x0020, spawn,      menucmd }, /* 0x0020 = XK_space */
};
