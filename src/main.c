#include <stdlib.h>
#include "SDL.h"

#include "main.h"
#include "game.h"
#include "render.h"

// temp
#include "actor.h"

int main()
{
  printf("Creating game\n");
  game *g = game_create();
  printf("Adding test actor\n");
  list_add(g->actors, actor_create());
  actor *a = (actor*)g->actors->first->elem;
  a->pos.x = 0.0;
  a->pos.y = 0.0;
  a->pos.z = 1.0;
  a->vel.x = 2.0;
  a->vel.y = 1.0;
  a->vel.z = .0;

  printf("Init gfx\n");
  gfx_init();
  SDL_Event e;
  printf("Starting main loop\n");
  while (1) {
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) break;
    }
    // Handle input
    game_tick(g);
    render(g);
  }
  game_destroy(g);
  gfx_cleanup();
  return 0;
}
