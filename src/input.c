#include "input.h"
#include "actor.h"

void handle_input(SDL_Event e, game *g) {
  const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
  actor *player = g->actors->first->elem;
  vector n = player->pos;
  vector left = vec_cross(n, player->vel);
  if (keyboard_state[SDL_SCANCODE_LEFT]) {
    double vel_norm = vec_norm(player->vel);
    vector delta_v = vec_smult(TURN_SPEED, left);
    vector new_vel_direction = vec_add(player->vel, delta_v);
    player->vel = vec_smult(vel_norm, vec_normalize(new_vel_direction));
  }
  if (keyboard_state[SDL_SCANCODE_RIGHT]) {
    double vel_norm = vec_norm(player->vel);
    vector delta_v = vec_smult(-TURN_SPEED, left);
    vector new_vel_direction = vec_add(player->vel, delta_v);
    player->vel = vec_smult(vel_norm, vec_normalize(new_vel_direction));
  }
  switch (e.type) {
  }
}
