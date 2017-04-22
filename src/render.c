#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>

#include "render.h"
#include "actor.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define RADIUS 400

void render_actor(actor *a);
void render_background();
void render_sphere();

static SDL_Window *_window;
static SDL_Renderer *_renderer;

static SDL_Texture *_placeholder_texture;
static SDL_Texture *_background;

void gfx_init() {
  SDL_Init(SDL_INIT_VIDEO);

  _window = SDL_CreateWindow("ld38", 0, 0, 
      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);
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

  _background = IMG_LoadTexture(_renderer, "../assets/background.jpg");

  // Test code ----
  _placeholder_texture = IMG_LoadTexture(_renderer, "../assets/duck_top_0.png");
  // ------
}

void gfx_cleanup() {
  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void render(game *g) {
  SDL_RenderClear(_renderer);
  render_background();
  render_sphere();
  for (item *i = g->actors->first; i != NULL; i = i->next)
  {
    actor *a = (actor*)i->elem;
    render_actor(a);
  }
  SDL_RenderPresent(_renderer);
}

void render_actor(actor *a) {
  double scale = .5 * a->pos.z + .5;

  int screen_x = (int)((a->pos.x) * RADIUS) 
    + SCREEN_WIDTH / 2 - 25 * scale;
  int screen_y = (int)(-(a->pos.y) * RADIUS) 
    + SCREEN_HEIGHT / 2 - 25 * scale;

  SDL_Rect src;
  SDL_Rect tgt;

  src.x = 0;
  src.y = 0;
  src.w = 200;
  src.h = 200;

  tgt.x = screen_x;
  tgt.y = screen_y;
  tgt.w = 50 * scale;
  tgt.h = 50 * scale;

  SDL_RenderCopyEx(_renderer, _placeholder_texture, &src, &tgt, 0, NULL, 0);
}

void render_background() {
  SDL_RenderCopy(_renderer, _background, NULL, NULL);
}
void render_sphere() {
}
