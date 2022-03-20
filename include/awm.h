/* typedefs */
typedef struct {
    unsigned int mod;
    xcb_keysym_t keysym;
    void (*func)(char **com);
    char **com;
} Key;

typedef struct {
    uint32_t request;
    void (*func)(xcb_generic_event_t *ev);
} handler_func_t;


/* workspaces */
typedef struct {
    const char* app;
    int workspace_id;
} ForceWorkspace;

typedef struct {
    int app_id;
    int workspace_id;
} WKApps;

/* convert keycode to keysym and back */
static xcb_keycode_t *xcb_get_keycodes(xcb_keysym_t keysym);
static xcb_keysym_t    xcb_get_keysym(xcb_keycode_t keycode);

/* user defined command actions */
static void killclient(char **com);
static void spawn(char **com);
static void closewm(char **com);
static void fullclient(char **com);

/* window behavior */
static void setFocus(xcb_drawable_t window);
static void setFocusColor(xcb_drawable_t window, int focus);

/* event hander actions */
static int eventHandler(void);
static void handleMotionNotify(xcb_generic_event_t *ev);
static void handleEnterNotify(xcb_generic_event_t *ev);
static void handleDestroyNotify(xcb_generic_event_t *ev);
static void handleButtonPress(xcb_generic_event_t *ev);
static void handleButtonRelease(xcb_generic_event_t *ev);
static void handleKeyPress(xcb_generic_event_t *ev);
static void handleMapRequest(xcb_generic_event_t *ev);
static void handleFocusIn(xcb_generic_event_t *ev);
static void handleFocusOut(xcb_generic_event_t *ev);
static handler_func_t handler_funs[] = {
    { XCB_MOTION_NOTIFY,  handleMotionNotify },
    { XCB_ENTER_NOTIFY,   handleEnterNotify },
    { XCB_DESTROY_NOTIFY, handleDestroyNotify },
    { XCB_BUTTON_PRESS,   handleButtonPress },
    { XCB_BUTTON_RELEASE, handleButtonRelease },
    { XCB_KEY_PRESS,      handleKeyPress },
    { XCB_MAP_REQUEST,    handleMapRequest },
    { XCB_FOCUS_IN,       handleFocusIn },
    { XCB_FOCUS_OUT,      handleFocusOut },
    { XCB_NONE,           NULL }
};

/* intialize */
static void setup_awm(void);

/* workspaces */
static void   switch_workspace(int workspace_id);      // switch to workspace with workspace_id.
static WKApps gen_win_id(int workspace_id);            // generate a window id for each window in a workspace.