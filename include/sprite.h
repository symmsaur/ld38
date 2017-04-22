#include "SDL.h"

typedef struct sprite {
  int n_orientations_z;
  int n_orientations_x;
  SDL_Texture textures[];
} sprite;

sprite sprite_create(int n_orientations_z, int n_orientations_z);
void sprite_destroy(sprite);

