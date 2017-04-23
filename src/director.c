#include <math.h>

#include "director.h"
#include "vector.h"
#include "actor.h"

int should_spawn(double dt);

#define INTENSITY_INTERVAL 20
#define INTENSITY_FACTOR .1
#define REST_INTERVAL 10
#define LIFETIME 10

static double intensity;

void init_director() {
  intensity = 1;
}

void manage_actors(game *g, double dt) {
  if (should_spawn(dt))
  {
    list *actors = g->actors;
    actor *a = actor_create();
    a->pos = vec_rand_on_sphere();
    // should be pushed onto sphere by position update code
    a->vel = vec_rand_on_sphere();
    list_add(actors, a);
  }
}

int should_spawn(double dt) {
  static double acc = 0;
  acc += dt * intensity;
  if (acc > 1)
  {
    acc = 0;
    return 1;
  }
  else 
  {
    intensity += dt * INTENSITY_FACTOR;
    return 0;
  }
}
