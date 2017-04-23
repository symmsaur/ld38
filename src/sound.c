#include "sound.h"

#define N_SOUNDS 3

static int sound_initialized = 1;

static Mix_Chunk **sounds;

void sound_init() {
  if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0) {
      printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
      sound_initialized = 0;
    }
  sounds = malloc(sizeof(Mix_Chunk*)*N_SOUNDS);
  sounds[0] = load_wav("../assets/test.wav");
  sounds[1] = load_wav("../assets/ploe.wav");
  sounds[2] = load_wav("../assets/flofloflo.wav");
}

void sound_cleanup() {
  for(int i = 0; i < N_SOUNDS; i++) {
    Mix_FreeChunk(sounds[i]);
  }
  free(sounds);
  Mix_Quit();
}

Mix_Chunk *load_wav(char *filename) {
  Mix_Chunk *ret = Mix_LoadWAV(filename);
  if (ret == NULL) {
    printf("Failed to load ");
    printf(filename);
    printf("\n");
  }
  return ret;
}

void sound_play(int sound) {
  if (sound_initialized && sound < N_SOUNDS)
    Mix_PlayChannel(-1, sounds[sound], 0);
}
