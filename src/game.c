#include <stdlib.h>
#include <stdio.h>

#include "game.h"
#include "actor.h"
#include "sprite.h"
#include "sound.h"

game * game_create(int players) {
  game *g = malloc(sizeof(game));
  g->actors = list_create();
  if(players > 0) {
    g->player = list_add(g->actors, actor_create())->elem;
    g->player->pos.x = 0.0;
    g->player->pos.y = 0.0;
    g->player->pos.z = 1.0;
    g->player->vel.x = .05;
    g->player->vel.y = .0;
    g->player->vel.z = .0;
    g->player->viscosity = 0.005;
    g->player->sprite_index = SPRITE_INDEX_PLAYER;
  }
  else {
	  g->player = NULL;
  }

	  
  g->game_over = 0;
  g->game_time = 0;

  return g;
}
void game_destroy(game *g) {
  list_destroy(g->actors);
  free(g);
}

void game_tick(game *g) {
  static int sound_decay = 0;
  g->game_time += DELTA_T;
  for (item *i = g->actors->first; i != NULL; i = i->next) {
    actor *a = (actor*)i->elem;
    actor_step_position(a, DELTA_T);
  }
  if(g->player != NULL) {
    for (item *j = g->actors->first; j != NULL; j = j->next) {
      if (g->player != j->elem) {
        if(actor_check_collision(g->player, j->elem) == 1) {
          g->game_over = 1;
        }
        else if (actor_check_collision(g->player, j->elem) == 2) {
          if (sound_decay <= 0) {
            sound_decay = 30;
            sound_play(SOUND_SPAWN);
          }
        }
      }
    }
    sound_decay--;
  }
}
