#include <stdlib.h>
#include "SDL.h"

#include "main.h"
#include "game.h"
#include "render.h"
#include "input.h"
#include "director.h"
#include "sprite.h"

// temp
#include "actor.h"

int main()
{
  srand(0);
  printf("Creating game\n");
  game *g = game_create();
  printf("Adding test actor\n");

  printf("Init gfx\n");
  gfx_init();
  init_director();
  load_sprites();
  SDL_Event e;
  printf("Starting main loop\n");
  while (1) {
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) break;
    }
    handle_input(e, g);
    manage_actors(g, DELTA_T);
    game_tick(g);
    render(g);
    if(g->game_over)
      break;
  }
  game_destroy(g);
  gfx_cleanup();
  return 0;
}
