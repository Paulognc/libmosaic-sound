#include <math.h>
#include <stdlib.h>
#include "include/whitenoise.h"

mosaicsound_noise_t* mosaicsound_create_noise(int framesPerBuffer) {
  mosaicsound_noise_t* noise = malloc(sizeof(mosaicsound_noise_t));
  noise->output = malloc(sizeof(float) * framesPerBuffer);
  noise->process = mosaicsound_noise_process;
  noise->framesPerBuffer = framesPerBuffer;

  return noise;
}

void mosaicsound_noise_process(mosaicsound_noise_t* noise) {
  for (int i = 0; i < noise->framesPerBuffer; i++) {
    noise->output[i] = sin(rand() % 20001);
  }
}
