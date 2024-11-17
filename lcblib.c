#include "lcbdef.c"
#include <lauxlib.h>
#include <lua.h>
#include <ncurses.h>

#define LCB_VERSION "lcblib_0.1"

static int echo_enabled = 0;

static WINDOW *towin(lua_State *L, int i) {
  WINDOW *win = (WINDOW *)lua_touserdata(L, i);
  return win;
}

static int l_initscr(lua_State *L) {
  initscr();
	start_color();
  has_colors();
  lua_getfield(L, LUA_REGISTRYINDEX, "lcb");
  lua_pushlightuserdata(L, stdscr);
  lua_setfield(L, -2, "stdscr");
	
	lua_pushinteger(L, LINES);
	lua_setfield(L, -2, "LINES");

	lua_pushinteger(L, COLS);
	lua_setfield(L, -2, "COLUMNS");
  return 0;
}

static int l_endwin() {
  endwin();
  return 0;
}

static int l_printw(lua_State *L) {
  printw(luaL_checkstring(L, -1));
  return 0;
}

static int l_addstr(lua_State *L) {
  while (lua_gettop(L) != 0) {
    addstr(luaL_checkstring(L, -1));
    lua_pop(L, -1);
  }

  return 0;
}

static int l_getch(lua_State *L) {
  int ch = getch();
  lua_pushinteger(L, ch);
  return 1;
}

static int l_cbreak(lua_State *L) {
  cbreak();
  return 0;
}

static int l_echo(lua_State *L) {
  echo();
  echo_enabled = 1;
  return 0;
}

static int l_noecho(lua_State *L) {
  noecho();
  echo_enabled = 0;
  return 0;
}

static int l_newwin(lua_State *L) {
  WINDOW *window = newwin(
    luaL_checkinteger(L, 1),
    luaL_checkinteger(L, 2),
    luaL_checkinteger(L, 3),
    luaL_checkinteger(L, 4)
  );
  lua_pushlightuserdata(L, window);
  return 1;
}

static int l_delwin(lua_State *L) {
  delwin(towin(L, 1));
  return 1;
}

static int l_keypad(lua_State *L) {
  WINDOW *win = towin(L, 1);
  keypad(win, lua_toboolean(L, 2));
  return 0;
}

static int l_colorpair(lua_State *L) {
  int foreground = luaL_checkinteger(L, -1);
  int background = luaL_checkinteger(L, -2);
	int index = luaL_checkinteger(L, -3);

  init_pair(index, foreground, background);
  return 0;
}

static int l_wrefresh(lua_State *L) {
  wrefresh(towin(L, 1));
  return 0;
}

static int l_wbkgd(lua_State *L) {
  wbkgd(stdscr, luaL_checkinteger(L, -1));
  return 0;
}

static int l_move(lua_State *L) {
	move(luaL_checkinteger(L, -1), luaL_checkinteger(L, -2));
	return 0;
}

static int l_getmaxyx(lua_State *L) {
	int l = luaL_checkinteger(L, -1);
	int c = luaL_checkinteger(L, -2);
	int ml, mc = getmaxyx(stdscr, l, c);
	lua_pushinteger(L, ml);
	lua_pushinteger(L, mc);
	return 2;
}

static int l_attron(lua_State *L) {
	int attr = luaL_checkinteger(L, -1);
	attron(attr);
	return 0;
}

static luaL_Reg lcbl[] = {
{"initscr", l_initscr},   
{"endwin", l_endwin},
{"printw", l_printw},
{"addstr", l_addstr},     
{"getch", l_getch},  
{"cbreak", l_cbreak},
{"echo", l_echo},         
{"noecho", l_noecho},
{"keypad", l_keypad},
{"initpair", l_colorpair},
{"wrefresh", l_wrefresh},
{"delwin", l_delwin},
{"newwin", l_newwin},
{"wbkgd", l_wbkgd},
{"move", l_move},
{"getmaxyx", l_getmaxyx},
{"attron", l_attron},
{NULL, NULL}
};

int luaopen_lcblib(lua_State *L) {
  luaL_newlib(L, lcbl);

  lua_pushlightuserdata(L, stdscr);
  lua_setfield(L, -2, "stdscr");

  lua_pushinteger(L, LINES);
  lua_setfield(L, -2, "LINES");

  lua_pushinteger(L, COLS);
  lua_setfield(L, -2, "COLUMNS");

  lua_pushstring(L, LCB_VERSION);
  lua_setfield(L, -2, "lcb_version");

  define_ncurses_attbr(L);
  define_ncurses_keys(L);
  define_ncurses_colors(L);

  lua_pushvalue(L, -1);
  lua_setfield(L, LUA_REGISTRYINDEX, "lcb");

  return 1;
}