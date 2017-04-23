#include <stdlib.h>

#include "sprite.h"
#include "render.h"

#define N_SPRITES 2

sprite sprite_create(int n_orientations_z, int n_orientations_x,  const char* bname);

static sprite *_sprites;

void load_sprites() {
  _sprites = malloc(sizeof(sprite) * N_SPRITES);
  _sprites[0] = sprite_create(8, 3, "duck");
  _sprites[1] = sprite_create(1, 1, "hand");
}

sprite * get_sprite(int index) {
  return _sprites + index;
}

sprite sprite_create(int n_orientations_z, int n_orientations_x,  const char* bname){
  sprite r;
  r.textures = malloc(sizeof(SDL_Texture*) * n_orientations_x * n_orientations_z);
  r.n_orientations_z = n_orientations_z;
  r.n_orientations_x = n_orientations_x;

  char *prefix = "../assets/";
  char *ext = ".png";
  char *pat = "_X_Y";
  char *filename = malloc(sizeof(char) * (strlen(prefix) +  strlen(bname) + strlen(pat) + strlen(ext)));
  sprintf(filename, "%s%s%s%s", prefix, bname, pat, ext);
  for (int ori_x = 0; ori_x < n_orientations_x; ori_x++) {
    for (int ori_z = 0; ori_z < n_orientations_z; ori_z++) {
      filename[strlen(prefix) + strlen(bname) + 1] = 48 + ori_x;
      filename[strlen(prefix) + strlen(bname) + 3] = 48 + ori_z;
      printf("loading sprite: %s\n", filename);
      r.textures[n_orientations_z * ori_x + ori_z] = render_load_texture(filename);
    }
  }
  free(filename);
  return r;
}

void sprite_destroy(sprite s) {
  printf("W: Sprite not destroyed!");
}

SDL_Texture * sprite_get_texture(sprite *s, int ori_z, int ori_x) {
  return s->textures[ori_x * s->n_orientations_z + ori_z];
}
