#include "Musicale.h"

#define WHOLE 1.0
#define HALF .5
#define QUARTER .25
#define EIGHTH .128

#define MIDDLE_C 261.626
#define CIS 277
#define D 294
#define DIS 311
#define E 330
#define MIDDLE_F 349
#define FIS 370
#define G 392
#define GIS 415
#define A 440
#define AIS 466
#define B 494


Musicale musicale(4);

void setup() {
  musicale.setBeatsPerMinute(110);
  musicale.begin();
}

void loop() {
  musicale.playNote(WHOLE, MIDDLE_C).playNote(2.0, 440).playNote(HALF, MIDDLE_C)
    .playNote(QUARTER, B)
    .playNote(WHOLE, 523.251)
    .rest(WHOLE);
   playScale(musicale, QUARTER);
   musicale.rest(WHOLE);

}

void playScale(Musicale m, float noteValue) {

m.playNote(noteValue, MIDDLE_C)
    .playNote(noteValue, D)
    .playNote(noteValue, E)
    .playNote(noteValue, MIDDLE_F)
    .playNote(noteValue, G)
    .playNote(noteValue, A)
    .playNote(noteValue, B)
    .playNote(noteValue, MIDDLE_C * 2);
}
  
