#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdlib.h>

#include "render.h"
#include "actor.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define RADIUS 400
#define RADIUS_POND 390

void render_actor(actor *a);
void render_background();
void render_sphere();

static SDL_Window *_window;
static SDL_Renderer *_renderer;

static SDL_Texture *_placeholder_texture;
static SDL_Texture *_background;
static SDL_Texture *_sphere;
static TTF_Font *font; 

static int ttf_initialized = 1;

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
  if(TTF_Init() == -1) {
    printf("Failed to init TTF font");
    ttf_initialized = 0;
  }
  if(ttf_initialized) {
    font = TTF_OpenFont("../assets/roboto_bold.ttf", 24);
    if(font == NULL) {
      printf("Font loading failed!");
    }
  }

  _background = IMG_LoadTexture(_renderer, "../assets/background.jpg");
  _sphere = IMG_LoadTexture(_renderer, "../assets/sphere.png");

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
  for (item *i = g->actors->first; i != NULL; i = i->next) {
    actor *a = (actor*)i->elem;
    if(a->pos.z < 0)
      render_actor(a);
  }
  render_sphere();
  for (item *i = g->actors->first; i != NULL; i = i->next) {
    actor *a = (actor*)i->elem;
    if(a->pos.z >= 0)
      render_actor(a);
  }
  SDL_Color duck_pond_text_color = {0, 255, 0};
  render_text("Duck pond of dOOm", 20, 20, duck_pond_text_color);
  char time_string[50];
  sprintf(time_string, "Time: %.2f", g->game_time);
  render_text(time_string, 20, 120, duck_pond_text_color);
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

  double angle = 180.0 / 3.14159 * atan2(a->vel.x, a->vel.y) + 180.0;

  SDL_RenderCopyEx(_renderer, _placeholder_texture, &src, &tgt, angle, NULL, 0);
}

void render_background() {
  SDL_RenderCopy(_renderer, _background, NULL, NULL);
}
void render_sphere() {
  SDL_Rect tgt;
  tgt.x = SCREEN_WIDTH / 2.0 - RADIUS_POND;
  tgt.y = SCREEN_HEIGHT / 2.0 - RADIUS_POND;
  tgt.w = 2*RADIUS_POND;
  tgt.h = 2*RADIUS_POND;
  SDL_RenderCopy(_renderer, _sphere, NULL, &tgt);
}

void render_text(char *msg, int x, int y, SDL_Color color) {
  if(ttf_initialized) {
    SDL_Surface* surface_text = TTF_RenderText_Blended(font, msg, color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

    SDL_Texture* message = SDL_CreateTextureFromSurface(_renderer, surface_text);
    SDL_Rect tgt;
    SDL_QueryTexture( message, NULL, NULL, &tgt.w, &tgt.h );
    tgt.x = x;
    tgt.y = y;
    SDL_RenderCopy(_renderer, message, NULL, &tgt);
    SDL_FreeSurface(surface_text);
    SDL_DestroyTexture(message);
  }
}
