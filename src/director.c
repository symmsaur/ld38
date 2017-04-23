#include <math.h>

#include "director.h"
#include "vector.h"
#include "actor.h"
#include "sprite.h"

int should_spawn(double dt);

#define INTENSITY_INTERVAL 20
#define INTENSITY_RATE .02
#define REST_INTERVAL 10
#define LIFETIME 10
#define START_INTENSITY .5

static double intensity;

void init_director() {
  intensity = START_INTENSITY;
}

void manage_actors(game *g, double dt) {
  if (should_spawn(dt))
  {
    list *actors = g->actors;
    actor *a = actor_create();
    a->pos = vec_rand_on_sphere();
    // should be pushed onto sphere by position update code
    a->vel = vec_rand_on_sphere();
    a->sprite_index = SPRITE_INDEX_PLAYER;
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
    intensity += dt * INTENSITY_RATE;
    return 0;
  }
}

