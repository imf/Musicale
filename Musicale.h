#include "Arduino.h"

#ifndef Musicale_h
#define Musicale_h

class Musicale {
	public: 
		Musicale(int soundOutPin);
		void begin();
		void setBeatsPerMinute(int bpm);
		Musicale* playNote(float noteValue, float pitch);
		Musicale* rest(float noteValue);
		
	private:
		int _soundOutPin;
		int _bpm;
		int hertzToDelay(float hertz);
		float valueToDuration(float noteValue);
		void emitTone(float durationInMiliseconds, int frequencyInMicroseconds);
};

//TODO: Add Midi class.

#endif
