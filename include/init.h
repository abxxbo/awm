#pragma once

#include <X11/Xlib.h>
#include <stdlib.h>

// initializes awm -- EWMH, Grab buttons
void init_awm(Display* dpy){
  // try to connect to display
  if(!(dpy = XOpenDisplay(0))) exit(1);

  // Set EWMH atoms
  EWMH_atoms_net(dpy, DefaultRootWindow(dpy));

  // Raise windows -- Super+R
  XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("R")), Mod4Mask,
          DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);

  // Left click - move window around.
  XGrabButton(dpy, 1, Mod4Mask, DefaultRootWindow(dpy), True,
              ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

  // Right click -- resize window
  XGrabButton(dpy, 3, Mod4Mask, DefaultRootWindow(dpy), True,
              ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
}

void on_start(){
  // Run autostart
  system("/bin/bash ~/.config/awm/autostart");
  // Run keybind daemon -- in the future: dont use system
  system("sxhkd -c ~/.config/awm/sxhkdrc &");
}
