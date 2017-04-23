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
  double wrap_distance = -.2;
  if (a->pos.z < wrap_distance)
  {
    a->pos.x = -a->pos.x;
    a->pos.y = -a->pos.y;
    a->pos.z = wrap_distance + (wrap_distance - a->pos.z);
    a->vel = vec_smult(-1, a->vel);
  }
  // F = -c*v^2
  // m * v' = F
  // v' = -(1.0 / m)*c*v^2
  vector new_vel_unit = vec_normalize(new_vel);
  double drag = a->viscosity*old_vel_length*old_vel_length / a->size;
  if(drag > old_vel_length)
    drag = old_vel_length;
  a->vel = vec_add(a->vel, vec_smult(-drag, new_vel_unit));
}

int actor_check_collision(actor *a, actor *b)
{
  vector ab = vec_add(a->pos, vec_smult(-1, b->pos));
  double distance = vec_norm(ab);
  if(distance < a->size + b->size) {
    return 1;
  }
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
  a->size = 0.06;
  a->viscosity = 0;
  a->sprite_index = 0;
  return a;
}

void actor_destroy(actor *a) {
  free(a);
}

