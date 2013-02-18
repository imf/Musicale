#include "Musicale.h"

#define DEBUG

#ifdef DEBUG
#define LED 13

#endif

Musicale::Musicale(int soundOutPin) {
	_soundOutPin = soundOutPin;
	_bpm = 120;
}

void Musicale::setBeatsPerMinute(int bpm) {
	_bpm = bpm;
}

Musicale::Musicale(int soundOutPin, int bpm) {
	_soundOutPin = soundOutPin;
	_bpm = bpm;
}

void Musicale::begin() {
	pinMode(_soundOutPin,   OUTPUT);
}

int Musicale::hertzToDelay(float hertz) {
  return (int) 1000.0 / hertz * 1000.0;
}

Musicale& Musicale::rest(float noteValue) {
    delay(this->valueToDuration(noteValue) / 100.0);
//    Serial.println("Rest.");
	return *this;
}

Musicale& Musicale::playNote(float noteValue, float frequency) {
#ifdef DEBUG
  Serial.println("playing note: ");
  Serial.print(noteValue, DEC);
  Serial.print('\t');
  Serial.print(frequency, DEC);
  Serial.print('\t');
  Serial.print(valueToDuration(noteValue), DEC);
  Serial.println("");
#endif
  this->emitTone(this->valueToDuration(noteValue), this->hertzToDelay(frequency));
  return *this;

}

float Musicale::valueToDuration(float noteValue) { // in µSec
  return 100000 * 60 * noteValue / _bpm;
}

void Musicale::blink(int on, int off, int frequency) {
#ifdef DEBUG
  digitalWrite(LED, HIGH);
  emitTone(on, frequency);
  digitalWrite(LED, LOW);
  delay(off);
#endif
}

void Musicale::emitTone(float durationInMiliseconds, int frequencyInMicroseconds) { // Emit tone on pin _soundOutPin
#ifdef DEBUG
  digitalWrite(LED, HIGH);
  Serial.println("Emitting tone: ");
  Serial.print(durationInMiliseconds * 10 / frequencyInMicroseconds, DEC);
  Serial.print('\t');
  Serial.print(frequencyInMicroseconds, DEC);
  Serial.println("");
#endif
  for (int i = 0; i < durationInMiliseconds * 10 / frequencyInMicroseconds; i++) {
    digitalWrite(_soundOutPin, HIGH);
    delayMicroseconds(frequencyInMicroseconds / 2);
    digitalWrite(_soundOutPin, LOW);
    delayMicroseconds(frequencyInMicroseconds / 2);
  }
#ifdef DEBUG
	digitalWrite(LED, LOW);
#endif
}
