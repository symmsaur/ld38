#include <stdlib.h>
#include <stdio.h>

#include "game.h"
#include "actor.h"

game * game_create() {
  game *g = malloc(sizeof(game));
  g->actors = list_create();
  g->player = list_add(g->actors, actor_create())->elem;
  g->game_over = 0;
  return g;
}
void game_destroy(game *g) {
  list_destroy(g->actors);
  free(g);
}

void game_tick(game *g) {
  for (item *i = g->actors->first; i != NULL; i = i->next) {
    actor *a = (actor*)i->elem;
    actor_step_position(a, DELTA_T);
  }
  for (item *j = g->actors->first; j != NULL; j = j->next) {
    if (g->player != j->elem) {
      if(actor_check_collision(g->player, j->elem))
        g->game_over = 1;
    }
  }
}
