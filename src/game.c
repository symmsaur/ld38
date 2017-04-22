#include <stdlib.h>
#include <stdio.h>

#include "game.h"
#include "actor.h"

game * game_create() {
  game *g = malloc(sizeof(game));
  g->actors = list_create();
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
    //printf("pos: [%3f, %3f, %3f]\n", a->pos.x, a->pos.y, a->pos.z);
    //printf("vel: [%3f, %3f, %3f]\n", a->vel.x, a->vel.y, a->vel.z);
  }
}
