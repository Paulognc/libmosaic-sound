
#include <stdio.h>
#include <stdlib.h>
#include "../../src/modules/include/audiomath.h"
#include "../../src/modules/include/biquad.h"
#include "../../src/modules/include/devices.h"
#include "../../src/modules/include/highshelving.h"
#include "../../src/modules/include/lowshelving.h"
#include "../../src/modules/include/mic.h"
#include "../../src/modules/include/oscillators.h"
#include "../../src/modules/include/parametricequalizer.h"
#include "../../src/modules/include/playback.h"
#include "../../src/modules/include/record.h"
#include "../../src/modules/include/whitenoise.h"

#define NUM_SECONDS 12
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256
#define CHANNELCOUNT 1 /* mono output */

playback_t *pb;

static int speakerCallback(const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo *timeInfo,
                           PaStreamCallbackFlags statusFlags, void *userData) {
  float *in = (float *)inputBuffer;
  float *out = (float *)outputBuffer;
  unsigned long i;

  (void)timeInfo; /* Prevent unused variable warnings. */
  (void)statusFlags;
  (void)userData;
  (void)in;

  pb->process(pb);

  for (i = 0; i < framesPerBuffer; i++) {
    out[i] = pb->outputL[i] + pb->outputR[i];
  }

  return paContinue;
}

/*
 * This routine is called by portaudio when playback is done.
 */
static void StreamFinished(void *data) { printf("Stream Completed!\n"); }

/*******************************************************************/
int main(int argc, char *argv[]) {
  PaStreamParameters inputParameters, outputParameters;
  PaStream *stream;
  PaError err;

  err = Pa_Initialize();
  if (err != paNoError) goto error;

  /*inputParameters*/
  inputParameters.device =
      Pa_GetDefaultInputDevice(); /* default input device */
  if (inputParameters.device == paNoDevice) {
    fprintf(stderr, "Error: No default input device.\n");
    goto error;
  }
  inputParameters.channelCount = CHANNELCOUNT; /* stereo input */
  inputParameters.sampleFormat = paFloat32;
  inputParameters.suggestedLatency =
      Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
  inputParameters.hostApiSpecificStreamInfo = NULL;

  pb = create_playback("examples/samples/miles_davis-solar.wav",
                       FRAMES_PER_BUFFER);
  pb->loop = 1;

  /*-------------------------------------------------------------------------*/
  /*outputParameters*/
  outputParameters.device =
      Pa_GetDefaultOutputDevice(); /* default output device */
  if (outputParameters.device == paNoDevice) {
    fprintf(stderr, "Error: No default output device.\n");
    goto error;
  }
  outputParameters.channelCount = CHANNELCOUNT; /* stereo output */
  outputParameters.sampleFormat = paFloat32; /* 32 bit floating point output */
  outputParameters.suggestedLatency =
      Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
  outputParameters.hostApiSpecificStreamInfo = NULL;
  err = Pa_OpenStream(&stream, &inputParameters, &outputParameters, SAMPLE_RATE,
                      FRAMES_PER_BUFFER,
                      paClipOff, /* we won't output out of range samples so
                                    don't bother clipping them */
                      speakerCallback, NULL);
  if (err != paNoError) goto error;

  err = Pa_SetStreamFinishedCallback(stream, &StreamFinished);
  if (err != paNoError) goto error;

  err = Pa_StartStream(stream);
  if (err != paNoError) goto error;

  printf("Playing until the Enter key is pressed.\n");
  getchar();

  err = Pa_StopStream(stream);
  if (err != paNoError) goto error;

  err = Pa_CloseStream(stream);
  if (err != paNoError) goto error;

  Pa_Terminate();

  return err;
error:
  Pa_Terminate();
  fprintf(stderr, "An error occured while using the portaudio stream\n");
  fprintf(stderr, "Error number: %d\n", err);
  fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
  return err;
}