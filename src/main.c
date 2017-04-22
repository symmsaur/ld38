#include "main.h"
#include "game.h"
#include "render.h"

int main()
{
  game *g = game_create();
  gfx_init();
  int quit = 0;
  while(!quit){
    // Make sure that we can exit ...
    // Handle input
    game_tick(g);
    render(g);
  }
  game_destroy(g);
  gfx_cleanup();
  return 0;
}
