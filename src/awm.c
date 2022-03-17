#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "ewmh.h"
#include "init.h"

#define MAX_OF(a, b)  ((a) > (b) ? (a) : (b))

int main(void){
  Display* dpy;
  XWindowAttributes attr;
  XButtonEvent start;
  XEvent ev;

  init_awm(dpy);
  on_start();

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
