#include <stdlib.h>
#include <time.h>
#include "SDL.h"

#include "main.h"
#include "game.h"
#include "render.h"
#include "sound.h"
#include "input.h"
#include "director.h"
#include "sprite.h"

// temp
#include "actor.h"

#define TICK_RATE (CLOCKS_PER_SEC/60)

int main()
{
  srand(0);
  printf("Creating game\n");
  game *start_screen_game = game_create(0);
  start_screen_enemies(start_screen_game);
  printf("Adding test actor\n");

  printf("Init gfx\n");
  gfx_init();
  sound_init();
  load_sprites();
  SDL_Event e;
  printf("Starting main loop\n");
  clock_t last_refresh = clock();
  clock_t current_clock;
  printf("Framerate: %f\n", (float)CLOCKS_PER_SEC/TICK_RATE);
  while (1) {
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) goto end;
    }
    const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
    if (keyboard_state[SDL_SCANCODE_RETURN]) {
      break;
    }
    current_clock  = clock();
    if(current_clock-last_refresh > TICK_RATE) {
      last_refresh = current_clock;
      game_tick(start_screen_game);
      render(start_screen_game, 1);
    }
  }
  while(1) {
    game *g = game_create(1);
    init_director();
    while (1) {
      if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
          game_destroy(g);
          goto end;
        }
      }

      current_clock  = clock();
      if(current_clock-last_refresh > TICK_RATE) {
        last_refresh = current_clock;
        handle_input(e, g);
        manage_enemies(g, DELTA_T);
        game_tick(g);
        render(g, 0);
        if(g->game_over)
          break;
      }
    }
    while (1) {
      if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
          game_destroy(g);
          goto end;
        }
      }
      const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
      if (keyboard_state[SDL_SCANCODE_RETURN]) {
        break;
      }
      current_clock  = clock();
      if(current_clock-last_refresh > TICK_RATE) {
        last_refresh = current_clock;
        handle_input(e, g);
        render(g, 2);
      }
    }
    game_destroy(g);
  }
 end:
  sound_cleanup();
  gfx_cleanup();
  return 0;
}
