#include "music.h"

#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin




void music::play(string name){
	musicPlayer.startPlayingFile(name);
}

void music::pause/resume(){
	  if (! musicPlayer.paused()) {
        Serial.println("Paused");
        musicPlayer.pausePlaying(true);
      } else { 
        Serial.println("Resumed");
        musicPlayer.pausePlaying(false);
      }
}
void music::stop(){
	musicPlayer.stopPlaying();
}

void music::init(){
	
	if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  	}
  	Serial.println(F("VS1053 found"));
  
   	if (!SD.begin(CARDCS)) {
    	Serial.println(F("SD failed, or not present"));
    	while (1);  // don't do anything more
  	}
  	Adafruit_VS1053_FilePlayer musicPlayer = 
  // create breakout-example object!
  	Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
  // create shield-example object!
  //Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);
	musicPlayer.setVolume(20,20);
	
	musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);
}
