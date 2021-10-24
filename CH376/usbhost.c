#ifndef usbhost
#define usbhost

#include "Arduino.h"
#include <Ch376msc.h>
#include <ArduinoJson.h>

class datalog
{
	public:
		void init(int);
		void send_data();
		
	private:
		int i;
		unsigned char Name[10] ,Size[10] ,Attribute[10];
		int Year[10] ,Month[10] ,Day[10] ,Hour[10] ,Minute[10] ,Second[10];
		char JSONmessageBuffer[300];
}
#endif
