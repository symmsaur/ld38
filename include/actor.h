#pragma once

#include "vector.h"

typedef struct actor {
  vector pos;
  vector vel;
  double size;
} actor;

void actor_step_position(actor *a, double dt);
int actor_check_collision(actor *a, actor *b);
actor * actor_create();
