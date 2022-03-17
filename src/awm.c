#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_OF(a, b)  ((a) > (b) ? (a) : (b))
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
  XChangeProperty(dpy, root, XInternAtom(dpy, EWMH_ATOMS_NET[3], True), 
}

int main(void){
  Display* dpy;
  XWindowAttributes attr;
  XButtonEvent start;
  XEvent ev;

  // try to connect to display
  if(!(dpy = XOpenDisplay(0))) return 1;

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

  // Run autostart
  system("/bin/bash ~/.config/awm/autostart");
  // Run keybind daemon -- in the future: dont use system
  system("sxhkd -c ~/.config/awm/sxhkdrc &");

  // Event loop
  start.subwindow = None;
  for(;;){
    XNextEvent(dpy, &ev);
    // raise window
    if(ev.type == KeyPress && ev.xkey.subwindow != None) XRaiseWindow(dpy, ev.xkey.subwindow);

    if(ev.type == ButtonPress && ev.xbutton.subwindow != None){
      XGetWindowAttributes(dpy, ev.xbutton.subwindow, &attr);
      start = ev.xbutton;
    } else if(ev.type == MotionNotify && start.subwindow != None){
      int x = ev.xbutton.x_root - start.x_root;
      int y = ev.xbutton.y_root - start.y_root;
      XMoveResizeWindow(dpy, start.subwindow,
                        attr.x + (start.button == 1 ? x : 0),
                        attr.y + (start.button == 1 ? y : 0),
                        MAX_OF(1, attr.width + (start.button == 3 ? x : 0)),
                        MAX_OF(1, attr.height + (start.button == 3 ? y : 0)));
    } else if(ev.type == ButtonRelease) start.subwindow = None;
  }
}
