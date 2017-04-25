#include <math.h>

#include "director.h"
#include "vector.h"
#include "actor.h"
#include "sprite.h"
#include "sound.h"

int should_spawn(double dt);
int in_spawn_interval(double t);
void kill_enemies(game *g);

#define SPAWN_INTERVAL 10
#define INTENSITY_RATE .2
#define REST_INTERVAL 5
#define START_INTENSITY 1
#define INTENSITY_VELOCITY_FACTOR .25

static double intensity;

void init_director() {
  intensity = START_INTENSITY;
}

void start_screen_enemies(game *g) {
  for(int i = 0; i < 4; i++) {
    list *actors = g->actors;
    actor *a = actor_create();
    vector r = vec_rand_on_sphere();
    r.z = -.17;
    a->pos = vec_normalize(r);
    // should be pushed onto sphere by position update code
    vector s = vec_rand_on_sphere();
    a->vel = vec_smult(.6 + INTENSITY_VELOCITY_FACTOR * intensity, s);
    a->sprite_index = SPRITE_INDEX_PLAYER;
    list_add(actors, a);
  }
}

void manage_enemies(game *g, double dt) {
  if (in_spawn_interval(g->game_time)) {
    if (should_spawn(dt)) {
      list *actors = g->actors;
      actor *a = actor_create();
      vector r = vec_rand_on_sphere();
      r.z = -.17;
      a->pos = vec_normalize(r);
      // should be pushed onto sphere by position update code
      vector s = vec_rand_on_sphere();
      a->vel = vec_smult(.6 + INTENSITY_VELOCITY_FACTOR * intensity, s);
      a->sprite_index = SPRITE_INDEX_PLAYER;
      list_add(actors, a);
    }
  }
  else {
    intensity += dt * INTENSITY_RATE;
    kill_enemies(g);
  }
}

void kill_enemies(game *g) {
  for (item *i = g->actors->first; i != NULL; i = i->next) {	  
    actor *a = (actor*)i->elem;
	if (a == g->player) {
	  continue;
	}
    if (a->pos.z < -.17)
    {
      item *tmp = i->prev;
      list_remove(g->actors, i);
      actor_destroy(a);
      i = tmp;
    }
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
  return 0;
}

int in_spawn_interval(double t) {
  double total_interval = SPAWN_INTERVAL + REST_INTERVAL;
  double e_time = fmod(t, total_interval);
  return e_time < SPAWN_INTERVAL;
}

