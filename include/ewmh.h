#pragma once

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <stdio.h>

#define ARR_SIZEOF(x) (sizeof(x)/sizeof(x[0]))

// wm stuff
#define WM_NAME "awm" // ...


// EWMH atoms that start with NET.
char* EWMH_ATOMS_NET[] = {
  "_NET_ACTIVE_WINDOW",
  "_NET_SUPPORTED",
  "_NET_WM_NAME",
  "_NET_WM_STATE",
  "_NET_WM_STATE_ABOVE",
  "_NET_WM_STATE_MAXIMIZED_VERT",
  "_NET_WM_STATE_MAXIMIZED_HORZ"
};

// Set ewmh atoms (_NET)
void EWMH_atoms_net(Display* dpy, Window root){
  // Create atoms if they do not exist -- most efficient way to do this
  for(int i = 0; i < ARR_SIZEOF(EWMH_ATOMS_NET); i++){
    XInternAtom(dpy, EWMH_ATOMS_NET[i], False);
    printf("EWMH NET Atom \"%s\" created.\n", EWMH_ATOMS_NET[i]);
  }

  // Set property of atoms

  // Active Window

  // Supported
  XChangeProperty(dpy, root, XInternAtom(dpy, EWMH_ATOMS_NET[1], True), XInternAtom(dpy, EWMH_ATOMS_NET[1], True),
                  32, PropModeReplace, EWMH_ATOMS_NET, ARR_SIZEOF(EWMH_ATOMS_NET));


  // WM Name
  XChangeProperty(dpy, root, XInternAtom(dpy, EWMH_ATOMS_NET[2], True), XInternAtom(dpy, EWMH_ATOMS_NET[2], True), 8,
                  PropModeReplace, WM_NAME, 3);

  // WM State
  // XChangeProperty(dpy, root, XInternAtom(dpy, EWMH_ATOMS_NET[3], True),
}
