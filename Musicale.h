#include "Arduino.h"

#ifndef Musicale_h
#define Musicale_h

class Musicale {
	public: 
		Musicale(int soundOutPin);
	private:
		int _soundOutPin;
};

#endif
