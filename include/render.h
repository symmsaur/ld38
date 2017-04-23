#pragma once

#include "SDL.h"

#include "game.h"

void gfx_init();
void gfx_cleanup();
void render_text(char *msg, int x, int y, SDL_Color color);
void render(game *g, int show_time);
void render_start_overlay();

SDL_Texture * render_load_texture(const char* filename);

