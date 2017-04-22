#include <stdlib.h>

#include "actor.h"
#include "vector.h"

void actor_step_position(actor *a, double dt) {
  vector delta_pos = vec_smult(dt, a->vel);
  a->pos = vec_add(a->pos, delta_pos);
  a->pos = vec_normalize(a->pos);
  double old_vel_length = vec_norm(a->vel);
  vector new_vel_direction = vec_project_plane(a->vel, a->pos);
  vector new_vel = vec_smult(old_vel_length, vec_normalize(new_vel_direction));
  a->vel = new_vel;
  // teleport around backside
  if (a->pos.z < -.2)
  {
    a->pos.x = -a->pos.x;
    a->pos.y = -a->pos.y;
    //a->vel.z = -a->vel.z;
    a->vel = vec_smult(-1, a->vel);
  }
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

