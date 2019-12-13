
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() 
{
  MIDI.begin(MIDI_CHANNEL_OMNI); 
  MIDI.turnThruOff(); 
}

void loop()
{
  if (MIDI.read()) {
    // get NoteOn event
    // and ignore alternate "0 velocity noteOn" note off
    if(MIDI.getType() == 0x90 && MIDI.getData2() > 0x00) {
      MIDI.send(
        MIDI.getType(),
        MIDI.getData1(),
        0x7f,  //force to max velocity
        0x01   // channel 1
      );
    } else { 
      MIDI.send(
        MIDI.getType(),
        MIDI.getData1(),
        MIDI.getData2(),
        0x01   // channel 1
      );
    }    
  }
}
