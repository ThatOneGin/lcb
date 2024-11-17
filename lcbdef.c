#include "lcb.h"
#include <lua.h>
#include <ncurses.h>

void define_ncurses_keys(lua_State *L) {
  lua_pushinteger(L, KEY_UP);
  lua_setfield(L, -2, "KEY_UP");
  lua_pushinteger(L, KEY_DOWN);
  lua_setfield(L, -2, "KEY_DOWN");
  lua_pushinteger(L, KEY_LEFT);
  lua_setfield(L, -2, "KEY_LEFT");
  lua_pushinteger(L, KEY_RIGHT);
  lua_setfield(L, -2, "KEY_RIGHT");
};
void define_ncurses_colors(lua_State *L) {
  lua_pushinteger(L, COLOR_BLACK);
  lua_setfield(L, -2, "COLOR_BLACK");
  lua_pushinteger(L, COLOR_BLUE);
  lua_setfield(L, -2, "COLOR_BLUE");
  lua_pushinteger(L, COLOR_WHITE);
  lua_setfield(L, -2, "COLOR_WHITE");
  lua_pushinteger(L, COLOR_CYAN);
  lua_setfield(L, -2, "COLOR_CYAN");
  lua_pushinteger(L, COLOR_GREEN);
  lua_setfield(L, -2, "COLOR_GREEN");
  lua_pushinteger(L, COLOR_RED);
  lua_setfield(L, -2, "COLOR_RED");
  lua_pushinteger(L, COLOR_YELLOW);
  lua_setfield(L, -2, "COLOR_YELLOW");
};
void define_ncurses_attbr(lua_State *L) {
  lua_pushinteger(L, A_NORMAL);
  lua_setfield(L, -2, "A_NORMAL");
  lua_pushinteger(L, A_STANDOUT);
  lua_setfield(L, -2, "A_STANDOUT");
  lua_pushinteger(L, A_UNDERLINE);
  lua_setfield(L, -2, "A_UNDERLINE");
  lua_pushinteger(L, A_REVERSE);
  lua_setfield(L, -2, "A_REVERSE");
  lua_pushinteger(L, A_BLINK);
  lua_setfield(L, -2, "A_BLINK");
  lua_pushinteger(L, A_DIM);
  lua_setfield(L, -2, "A_DIM");
  lua_pushinteger(L, A_BOLD);
  lua_setfield(L, -2, "A_BOLD");
  lua_pushinteger(L, A_PROTECT);
  lua_setfield(L, -2, "A_PROTECT");
  lua_pushinteger(L, A_INVIS);
  lua_setfield(L, -2, "A_INVIS");
  lua_pushinteger(L, A_ALTCHARSET);
  lua_setfield(L, -2, "A_ALTCHARSET");
  lua_pushinteger(L, A_CHARTEXT);
  lua_setfield(L, -2, "A_CHARTEXT");
};