#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>

#include "render.h"
#include "actor.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define SCALE 800

void render_actor(actor *a);

static SDL_Window *_window;
static SDL_Renderer *_renderer;

static SDL_Texture *_placeholder_texture;

void gfx_init() {
  SDL_Init(SDL_INIT_VIDEO);

  _window = SDL_CreateWindow("ld38", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (_window == NULL) {
    printf("Failed to create window\n.");
    SDL_Quit();
  }

  _renderer = SDL_CreateRenderer(_window, -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (_renderer == NULL) {
    printf("Fialed to create renderer");
    SDL_Quit();
  }

  // Test code ----
  _placeholder_texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 50, 50);
  SDL_Rect r;
  r.x = 0;
  r.y = 0;
  r.w = 50;
  r.h = 50;
  SDL_SetRenderTarget(_renderer, _placeholder_texture);
  SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(_renderer);
  SDL_RenderDrawRect(_renderer,&r);
  SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0x00);
  SDL_RenderFillRect(_renderer, &r);
  SDL_SetRenderTarget(_renderer, NULL);
  // ------
}

void gfx_cleanup() {
  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void render(game *g) {
  SDL_RenderClear(_renderer);
  for (item *i = g->actors->first; i != NULL; i = i->next)
  {
    actor *a = (actor*)i->elem;
    render_actor(a);
  }
}

void render_actor(actor *a) {
  int screen_x = (int)(a->pos.x * SCALE);
  int screen_y = (int)(a->pos.y * SCALE);

  SDL_Rect src;
  SDL_Rect tgt;

  src.x = 0;
  src.y = 0;
  src.w = 50;
  src.h = 50;

  tgt.x = screen_x;
  tgt.y = screen_y;
  tgt.w = 50;
  tgt.h = 50;

  SDL_RenderCopyEx(_renderer, _placeholder_texture, &src, &tgt, 0, NULL, 0);
}

