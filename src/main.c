#include <stdlib.h>
#include "SDL.h"

#include "main.h"
#include "game.h"
#include "render.h"
#include "input.h"
#include "director.h"

// temp
#include "actor.h"

int main()
{
  srand(0);
  printf("Creating game\n");
  game *g = game_create();
  printf("Adding test actor\n");
  actor *a = g->player;
  a->pos.x = 0.0;
  a->pos.y = 0.0;
  a->pos.z = 1.0;
  a->vel.x = .05;
  a->vel.y = .0;
  a->vel.z = .0;

  printf("Init gfx\n");
  gfx_init();
  init_director();
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
