#include <math.h>
#include <portaudio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/mic.h"

mosaicsound_mic_t *mosaicsound_create_mic(int framesPerBuffer) {
  mosaicsound_mic_t *mic = malloc(sizeof(mosaicsound_mic_t));
  mic->framesPerBuffer = framesPerBuffer;
  mic->output = malloc(framesPerBuffer * sizeof(float));
  mic->process = mosaicsound_mic_process;

  return mic;
}

void mosaicsound_mic_process(mosaicsound_mic_t *mic, float *input) {
  for (int i = 0; i < mic->framesPerBuffer; i++) {
    mic->output[i] = input[i];
  }
}
