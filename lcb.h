#ifndef LCB_H_
#define LCB_H_
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
void define_ncurses_keys(lua_State *L);
void define_ncurses_colors(lua_State *L);
void define_ncurses_attbr(lua_State *L);
#endif