#include <stdlib.h>

#include "game.h"


game * game_create() {
  game *g = malloc(sizeof(game));
  g->actors = list_create();
  return g;
}
void game_destroy(game *g) {
  list_destroy(g->actors);
  free(g);
}

void game_tick(game *g) {}
