# LCB

Lua curses bindings

* Notes: these bindings are made close to the ncurses library, so anyone who knows ncurses can just download and use it with almost no problems. I can't emulate ncurses perfectly in lua as i'm new to the lua C api and i made this for learning purposes

## using (locally)

* 1. clone the repo and compile using ```make``` command.
* 2. and then, include the ```lcb.lua``` and the ```lcblib.so``` in whatever folder you want.

Example:

```lua
lcb = require("lcblib")
lcb.initscr()
lcb.getch()
lcb.endwin()
```

You dont have to worry about of a misspelling a variable/function name as it has auto completion for some editors.
