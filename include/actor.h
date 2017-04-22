#pragma once

#include "vector.h"

typedef struct actor {
  vector pos;
  vector vel;
  double size;
} actor;

void step_position(actor *a);
int check_collision(actor *a, actor *b);
actor * actor_create();
