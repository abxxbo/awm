# awm (Abxxbo's Window Manager)

<div align="center">
    <a href="img/scrot1.png"><img src="img/scrot1.png" width="50%" align="center"></a><a href="img/scrot2.png"><img src="img/scrot2.png" width="50%" align="center"></a>
</div>

<br>

## Features

- Floating only
- Virtual workspaces
- Titlebars
- Modular config system

## Default Keybinds

**Window Management**

| keybind       | action        |
| ------------- | ------------- |
| `Mouse`       | focus         |
| `Mod4+R`      | raise window  |
| `Mod4+F`      | fullscreen    |
| `Mod4+Q`      | kill window   |
| `Mod4+Mouse1` | move window   |
| `Mod4+Mouse3` | resize window |

**Programs**

| keybind       | program       |
| ------------- | ------------- |
| `Mod4+Return` | `urxvt`       |
| `Mod4+Space`  | `rofi`        |

## Dependencies
- xcb

## Installation
1. Create a autostart file, `~/.config/awm/autostart`
2. Build awm: `make`
3. Install via `sudo make install`
4. Add awm to `~/.xinitrc`:
```sh
exec awm
```

