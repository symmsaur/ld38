#include <stdlib.h>

#include "actor.h"
#include "vector.h"

void actor_step_position(actor *a, double dt) {
  vector delta_pos = vec_smult(dt, a->vel);
  a->pos = vec_add(a->pos, delta_pos);
}

int actor_check_collision(actor *a, actor *b)
{
  return 0;
}

actor * actor_create() {
  actor *a = malloc(sizeof(actor));
  a->pos.x = 0;
  a->pos.y = 0;
  a->pos.z = 0;
  a->vel.x = 0;
  a->vel.y = 0;
  a->vel.z = 0;
  a->size = 0;
  return a;
}

