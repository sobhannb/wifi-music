#ifndef wifi
#define wifi

#include "Arduino.h"
#include <WiFi.h>
#include "FS.h"
#include <LittleFS.h>
#include <ESP32Ping.h>

class wifi
{
	public:
		int connection();
		void readfile();
		void writefile();
		bool ping();
	private:
		String ssid;
        	String password;
        	char inChar;
        	int a = 0;
        	String Ssid;
		String Password;
		const char* remote_host = "www.google.com";
}
#endif
