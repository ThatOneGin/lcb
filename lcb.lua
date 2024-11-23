--[[
This is the file for the autocomplete of some editors, to include it, first compile using make.
and require it in your directory.
]]

---@class lcblib
---@meta lcb
---Ncurses bindings library for manipulating terminal in lua.
lcb = require("lcblib")

---Standard screen when using 'initscr' function.
---@type userdata
lcb.stdscr = nil

---Lcb version
---@type string
lcb.lcb_version = "lcblib_0.1"

---Initializes the standard screen (stdscr).
function lcb.initscr() end

---Ends the standard screen (stdscr).
function lcb.endwin() end

---Print text without format at the stdscr.
---@param str string
function lcb.printw(str) end

---@param str string
---Displays text at the cursor.
function lcb.addstr(str) end

---Gets char from the user keyboard without waiting for a carriage return and returns the char as integer.
---@return integer
function lcb.getch() end

---Disables line buffering and erase/kill character-processing
function lcb.cbreak() end

---Enables echo at the current screen.
function lcb.echo() end

---Disables echo at the current screen
function lcb.noecho() end

---Enables keypad for terminal
function lcb.keypad() end

---Initializes a pair of colors ant takes 3 arguments: index of pair, foreground and background
---@param i integer
---@param foreground integer
---@param background integer
function lcb.initpair(i, foreground, background) end

---Refresh the given window.
---@param win userdata
function lcb.wrefresh(win) end

---Delete given window.
---@param win userdata
function lcb.delwin(win) end

---Creates a new window in given arguments
---@param x1 integer
---@param y1 integer
---@param x2 integer
---@param y2 integer
function lcb.newwin(x1, y1, x2, y2) end

---Changes the colors of the terminal based on the color pair given.
---@param screen userdata
---@param pair integer
function lcb.wbkgd(screen, pair) end

---Move the current cursor to position (x, y)
---@param x integer
---@param y integer
function lcb.move(x, y) end

---Get the max y, x of the current terminal.
---@param LINES integer
---@param COLS integer
---@return integer[]
function lcb.getmaxyx(LINES, COLS) end

---Activates attribute to the stdscr.
---@param attr integer
function lcb.attron(attr) end

---Deactivates attribute of the stdscr
---@param attr integer
function lcb.attroff(attr) end

---Activate given color pair
---@param p integer
function lcb.COLOR_PAIR(p) end

---Disable cbreak
function lcb.nocbreak() end

---Clear the terminal window
function lcb.clear() end

---Refresh the terminal window
function lcb.refresh() end

--[[
colors, attributes and keys just for the autocomplete of some editors.
]]

---@type integer
lcb.KEY_UP       = lcb.KEY_UP
---@type integer
lcb.KEY_DOWN     = lcb.KEY_DOWN
---@type integer
lcb.KEY_LEFT     = lcb.KEY_LEFT
---@type integer
lcb.KEY_RIGHT    = lcb.KEY_RIGHT

lcb.COLOR_BLACK  = lcb.COLOR_BLACK
---@type integer
lcb.COLOR_BLUE   = lcb.COLOR_BLUE
---@type integer
lcb.COLOR_WHITE  = lcb.COLOR_WHITE
---@type integer
lcb.COLOR_CYAN   = lcb.COLOR_CYAN
---@type integer
lcb.COLOR_GREEN  = lcb.COLOR_GREEN
---@type integer
lcb.COLOR_RED    = lcb.COLOR_RED
---@type integer
lcb.COLOR_YELLOW = lcb.COLOR_YELLOW

lcb.A_NORMAL     = lcb.A_NORMAL
---@type integer
lcb.A_STANDOUT   = lcb.A_STANDOUT
---@type integer
lcb.A_UNDERLINE  = lcb.A_UNDERLINE
---@type integer
lcb.A_REVERSE    = lcb.A_REVERSE
---@type integer
lcb.A_BLINK      = lcb.A_BLINK
---@type integer
lcb.A_DIM        = lcb.A_DIM
---@type integer
lcb.A_BOLD       = lcb.A_BOLD
---@type integer
lcb.A_PROTECT    = lcb.A_PROTECT
---@type integer
lcb.A_INVIS      = lcb.A_INVIS
---@type integer
lcb.A_ALTCHARSET = lcb.A_ALTCHARSET
---@type integer
lcb.A_CHARTEXT   = lcb.A_CHARTEXT

return require("lcblib")