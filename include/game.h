#pragma once

#include "list.h"

#define DELTA_T 0.01

typedef struct game {
  list *actors;
} game;

game * game_create();
void game_destroy(game *g);

void game_tick(game *g);
