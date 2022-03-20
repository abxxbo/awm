# Configuring AWM

## Why would you do this?
Stock AWM sucks.

# Window Parameters

## `WINDOW_WIDTH` / `WINDOW_HEIGHT`
The default width/height (in pixels) that awm will use when opening new windows.

## `WINDOW_MIN_W` / `WINDOW_MIN_H`
The smallest width/height (in pixels) that a window can go.

## `BORDER_WIDTH`
Borders around windows. If set to 0, no border will be shown.

## `BORDER_COLOR_UNFOCUSED` / `BORDER_COLOR_FOCUSED`
Self explanatory. Format is `0xRRGGBB`.

# Workspaces

*DO NOT MODIFY ANYTHING SHOWN HERE. IT IS **VERY** VOLATILE. YOU **WILL** BREAK YOUR INSTALLATION. ONLY MODIFY IF THIS MESSAGE IS **DELETED/STRIKED OUT.***

## `WORKSPACES`
Amount of workspaces that awm will use.

## `WORKSPACE_ID_[X]`
Workspace ID for workspace `X`. Format is `[X-1]0000`

# Bar Configuring

## `bar_background_color`
It's self explanatory. The format is `0xRRGGBB`

## `bar_foreground_color`
It's self explanatory. The format is `0xRRGGBB`

## `time_fmt`
The format that the bar's time will use. For example, `%H:%M` will produce `13:03` if that is the time.
