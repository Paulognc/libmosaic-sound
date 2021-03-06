#ifndef MOSAICSOUND_LOWSHELVING_H
#define MOSAICSOUND_LOWSHELVING_H

    typedef struct {
        float *input;
        float *output;
        float gain;
        int framesPerBuffer;
        float sampleRate;
        float cutOff;
        float xn1; /* x(n-1) */
        float xn2; /* x(n-2) */
        float yn1; /* y(n-1) */
        float yn2; /* y(n-2) */
        void (*process)(void *self);
    }mosaicsound_lowshelving_t;

    mosaicsound_lowshelving_t *mosaicsound_create_lowshelving(int framesPerBuffer);
    void mosaicsound_lowshelving_process();

#endif /* lowshelving.h */
