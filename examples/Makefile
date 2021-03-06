CC := gcc
CFLAGS :=	-g -Wall
LIBS :=	-lportaudio -lm `pkg-config --libs sndfile`
LIB_FLAGS :=  -I/usr/include/mosaic/mosaic-sound -lmosaic-sound
SRC :=	src/
BUILD :=	build/
OBJSRC :=	../build/
BIN :=	bin/
OBJS := $(OBJSRC)list.o \
        $(OBJSRC)devices.o \
        $(OBJSRC)whitenoise.o \
        $(OBJSRC)audiomath.o \
        $(OBJSRC)oscillators.o \
        $(OBJSRC)mic.o \
        $(OBJSRC)biquad.o \
        $(OBJSRC)parametricequalizer.o \
        $(OBJSRC)lowshelving.o \
        $(OBJSRC)highshelving.o \
        $(OBJSRC)playback.o \
		$(OBJSRC)record.o

TARGET := $(BIN)record_mic $(BIN)playback_mono $(BIN)playback_stereo \
		  $(BIN)osc_math $(BIN)noise $(BIN)devices $(BIN)allpass $(BIN)lowpass \
		  $(BIN)highpass $(BIN)bandpass $(BIN)bandreject $(BIN)parametric_eq \
		  $(BIN)lowshelving $(BIN)highshelving


all: $(TARGET)

# Example: record microphone
$(BIN)record_mic:	$(BUILD)record_mic.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)record_mic.o: $(SRC)record_mic.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: playback mono
$(BIN)playback_mono:	$(BUILD)playback_mono.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)playback_mono.o: $(SRC)playback_mono.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: playback stereo
$(BIN)playback_stereo:	$(BUILD)playback_stereo.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)playback_stereo.o: $(SRC)playback_stereo.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: sum of two oscillators
$(BIN)osc_math:	$(BUILD)osc_math.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)osc_math.o: $(SRC)osc_math.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: white noise
$(BIN)noise:	$(BUILD)noise.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)noise.o: $(SRC)noise.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: list devices
$(BIN)devices:	$(BUILD)devices.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)devices.o: $(SRC)devices.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: allpass
$(BIN)allpass:	$(BUILD)allpass.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)allpass.o: $(SRC)allpass.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: lowpass
$(BIN)lowpass:	$(BUILD)lowpass.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)lowpass.o: $(SRC)lowpass.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: highpass
$(BIN)highpass:	$(BUILD)highpass.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)highpass.o: $(SRC)highpass.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: bandpass
$(BIN)bandpass:	$(BUILD)bandpass.o $(OBJS)
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)bandpass.o: $(SRC)bandpass.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: bandreject
$(BIN)bandreject:	$(BUILD)bandreject.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)bandreject.o: $(SRC)bandreject.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: parametric equalizer
$(BIN)parametric_eq:	$(BUILD)parametric_eq.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)parametric_eq.o: $(SRC)parametric_eq.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: lowshelving
$(BIN)lowshelving:	$(BUILD)lowshelving.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)lowshelving.o: $(SRC)lowshelving.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)

# Example: highshelving
$(BIN)highshelving:	$(BUILD)highshelving.o
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $^ $(LIB_FLAGS) -o $@  $(LIBS)

$(BUILD)highshelving.o: $(SRC)highshelving.c
	mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) -o $@  $(LIBS)
