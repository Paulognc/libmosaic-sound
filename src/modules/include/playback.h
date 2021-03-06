#ifndef MOSAICSOUND_PLAYBACK_H
#define MOSAICSOUND_PLAYBACK_H

    typedef struct {
        int loop;
        int channels;
        int framesPerBuffer;
        int fileSampleRate;
        int fileFrames;
        int readCount;
        int paused; /* 0: paused ; 1: playing*/
        float *outputL;
        float *outputR;
        float *input;
        char *filename;
        void (*process)(void *self);
    }mosaicsound_playback_t;

    mosaicsound_playback_t *mosaicsound_create_playback(char *filename, int framesPerBuffer);

    void mosaicsound_playback_process_mono();
    void mosaicsound_playback_process_stereo();

#endif /* playback.h */
