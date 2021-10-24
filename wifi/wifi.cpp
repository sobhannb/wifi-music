#include<wifi.h>

#define FORMAT_LITTLEFS_IF_FAILED true

int wifi::connection(){
	Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid.c_str(), password.c_str());

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    return WiFi.localIP();
}

void wifi::readfile(){
	void readFile(fs::FS &fs, const char * path = "ssid.txt"){
    	Serial.printf("Reading file: %s\r\n", path);

    	File file = fs.open(path);
    	if(!file || file.isDirectory()){
        	Serial.println("- failed to open file for reading");
        	return;
    	}

    	Serial.println("- read from file:");
    	while(file.available()){
        	//Serial.write(file.read());
        	inChar = (char)file.read();
        	ssid += inChar;
    	}
    	file.close();
	}
	
	void readFile(fs::FS &fs, const char * path = "pass.txt"){
    	Serial.printf("Reading file: %s\r\n", path);

    	File file = fs.open(path);
    	if(!file || file.isDirectory()){
        	Serial.println("- failed to open file for reading");
        	return;
    	}

    	Serial.println("- read from file:");
    	while(file.available()){
        	//Serial.write(file.read());
        	inChar = (char)file.read();
        	password += inChar;
    	}
    	file.close();
	}
}

void wifi::writefile(){
	Serial.println("Enter the ssid of your router :");
	while(Ssid.length()<=2 && Password.length()<=2){
		while (Serial.available()) {
      		if (inChar == '\n') {
        	a = 0;
        	Serial.println("Enter the password of your router :");
      	}
      	if(a){
        // get the new byte:
        	inChar = (char)Serial.read();
        // add it to the inputString:
        	Ssid += inChar;
        // if the incoming character is a newline, set a flag so the main loop can
        // do something about it:
      	}else{
        	inChar = (char)Serial.read();
        	Password += inChar;

      	}
      
    	}
	}

	if(!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)){
        Serial.println("LittleFS Mount Failed");
        return;
    }
	void writeFile(fs::FS &fs, const char * path = "ssid.txt", const char * message = Ssid.c_str()){
    	Serial.printf("Writing file: %s\r\n", path);

    	File file = fs.open(path, FILE_WRITE);
    	if(!file){
        	Serial.println("- failed to open file for writing");
        	return;
    	}
    	if(file.print(message)){
        	Serial.println("- file written");
    	} else {
        	Serial.println("- write failed");
    	}
    	file.close();
	}
	void writeFile(fs::FS &fs, const char * path = "pass.txt", const char * message = Password.c_str()){
    	Serial.printf("Writing file: %s\r\n", path);

    	File file = fs.open(path, FILE_WRITE);
    	if(!file){
        	Serial.println("- failed to open file for writing");
        	return;
    	}
    	if(file.print(message)){
        	Serial.println("- file written");
    	} else {
        	Serial.println("- write failed");
    	}
    	file.close();
	}
	
}

bool wifi::ping(){
	if(Ping.ping(remote_host)) {
    	return true;
  	} else {
    	return false;
  	}
}
