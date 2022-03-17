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

static xcb_keycode_t *xcb_get_keycodes(xcb_keysym_t keysym);
static xcb_keysym_t    xcb_get_keysym(xcb_keycode_t keycode);

static void killclient(char **com);
static void spawn(char **com);
static void closewm(char **com);
static void fullclient(char **com);

static void setFocus(xcb_drawable_t window);
static void setFocusColor(xcb_drawable_t window, int focus);

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

static void setup(void);

static int die(char *errstr);
static int strcmp_c(char *str1, char *str2);

