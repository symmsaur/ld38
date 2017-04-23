#pragma once

#include "list.h"
#include "actor.h"

#define DELTA_T 0.01

typedef struct game {
  list *actors;
  actor *player;
  int game_over;
} game;

game * game_create();
void game_destroy(game *g);

void game_tick(game *g);
