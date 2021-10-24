#ifndef music
#define music

#include "Arduino.h"
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

class music
{
	public:
		
		void play(string name);
		void stop();
		void pause/resume();
		void init();
		
	private:	
}
#endif
