#include <stdlib.h>

#include "SDL.h"

#define SPRITE_INDEX_PLAYER 0
#define SPRITE_INDEX_HAND 1

typedef struct sprite {
  int n_orientations_z;
  int n_orientations_x;
  SDL_Texture **textures;
} sprite;

void load_sprites();
sprite * get_sprite(int index);

SDL_Texture * sprite_get_texture(sprite *s, int ori_z, int ori_x);

