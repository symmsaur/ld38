#include "SDL.h"
#include "SDL_image.h"

#include "render.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

static SDL_Window *_window;

void gfx_init() {
  SDL_Init(SDL_INIT_VIDEO);

  _window = SDL_CreateWindow("ld38", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (window == null) {
    printf("Failed to create window\n.");
    SDL_Quit();
  }
}

void gfx_cleanup()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}

