#pragma once
#include <SDL_mixer.h>

#define SOUND_CRASH 0

void sound_init();
void sound_cleanup();
Mix_Chunk *load_wav(char *filename);
void sound_play(int sounds);
