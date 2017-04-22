#include "main.h"
#include "game.h"
#include "render.h"

int main()
{
  game *g = game_create();
  int quit = 0;
  while(!quit){
    // Make sure that we can exit ...
    game_tick(g);
    render(g);
  }
  game_destroy(g);
  return 0;
}
