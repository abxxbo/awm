#include <X11/Xlib.h>
#include <unistd.h>

#define MAX_OF(a, b) ((a) > (b) ? (a) : (b))

int main(void){
  Display* dpy;
  XWindowAttributes attr;
  XButtonEvent start;
  XEvent ev;

  // try to connect to display
  if(!(dpy = XOpenDisplay(0))) return 1;

  // Raise windows -- Super+R
  XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("R")), Mod4Mask,
          DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);

  // Left click - move window around.
  XGrabButton(dpy, 1, Mod4Mask, DefaultRootWindow(dpy), True,
              ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

  // Right click -- resize window
  XGrabButton(dpy, 3, Mod4Mask, DefaultRootWindow(dpy), True,
              ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

  execl("/bin/bash", "/bin/bash", "sxhkd -c ~/.config/awm/sxhkdrc", 0);

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
