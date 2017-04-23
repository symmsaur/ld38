#include "input.h"
#include "actor.h"
#include "sound.h"

void handle_input(SDL_Event e, game *g) {
  static int sound_decay = 0;
  const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
  actor *player = g->actors->first->elem;
  vector n = player->pos;
  vector left = vec_cross(n, player->vel);
  vector vel_unit = vec_normalize(player->vel);
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
  if (keyboard_state[SDL_SCANCODE_UP] && vec_norm(player->vel) < 3) {
    if (sound_decay == 0) {
      sound_decay = 60 * (abs(rand()) % 3 + 2);
      sound_play(SOUND_SWIM);
    }
    player->vel = vec_add(player->vel, vec_smult(0.1, vel_unit));
    sound_decay--;
  }
  else
  {
    sound_decay = 0;
  }
  if (keyboard_state[SDL_SCANCODE_DOWN] && vec_norm(player->vel) > 0.05) {
    player->vel = vec_add(player->vel, vec_smult(-0.1, vel_unit));
  }
}
