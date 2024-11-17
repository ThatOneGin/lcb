#include "lcbdef.c"
#include <lauxlib.h>
#include <lua.h>
#include <ncurses.h>

static int echo_enabled = 0;

static WINDOW *towin(lua_State *L, int i) {
  WINDOW *win = (WINDOW *)lua_touserdata(L, i);
  return win;
}

static int l_initscr(lua_State *L) {
  initscr();

  lua_getfield(L, LUA_REGISTRYINDEX, "lcb");
  lua_pushlightuserdata(L, stdscr);
  lua_setfield(L, -2, "stdscr");

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
  int colorpair_i = luaL_checkinteger(L, -3);
  int foreground = luaL_checkinteger(L, -2);
  int background = luaL_checkinteger(L, -1);

  init_pair(colorpair_i, foreground, background);
  return 0;
}

static int l_wrefresh(lua_State *L) {
  wrefresh(towin(L, 1));
  return 0;
}

static int l_wbkgd(lua_State *L) {
  WINDOW *win = towin(L, 1);
  int cpair = luaL_checkinteger(L, -1);
  wbkgd(win, cpair);
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
{NULL, NULL}
};

int luaopen_lcb(lua_State *L) {
  luaL_newlib(L, lcbl);

  lua_pushlightuserdata(L, stdscr);
  lua_setfield(L, -2, "stdscr");

  define_ncurses_attbr(L);
  define_ncurses_keys(L);
  define_ncurses_colors(L);

  lua_pushvalue(L, -1);
  lua_setfield(L, LUA_REGISTRYINDEX, "lcb");

  return 1;
}