#include <Pushbutton.h>

Pushbutton buttonL(3);
Pushbutton buttonR(2);

#define MIDI_NOTE_ON_EVENT (0x90)
#define MIDI_NOTE_OFF_EVENT (0x80)

const int MIDI_CHANNEL = 1; // choose from 1-16

void setup() {
  Serial1.begin(31250);
}

void loop() {
  if(buttonL.getSingleDebouncedPress()) {
    noteOn(MIDI_NOTE_ON_EVENT | MIDI_CHANNEL - 1, 0x4E, 0x7f);

  }
  if(buttonL.getSingleDebouncedRelease()) {
    noteOn(MIDI_NOTE_ON_EVENT | MIDI_CHANNEL - 1, 0x4E, 0x00);
  }

  if(buttonR.getSingleDebouncedPress()) {
    noteOn(MIDI_NOTE_ON_EVENT | MIDI_CHANNEL - 1, 0x4F, 0x7f);
  }

  if(buttonR.getSingleDebouncedRelease()) {
    noteOn(MIDI_NOTE_ON_EVENT | MIDI_CHANNEL - 1, 0x4F, 0x00);
  }
}

void noteOn(int cmd, int pitch, int velocity) {
  Serial1.write(cmd);
  Serial1.write(pitch);
  Serial1.write(velocity);
}
