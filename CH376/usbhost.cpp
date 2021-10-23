#include "usbhost.h"

void datalog::init(int chipselect){
	Ch376msc flashDrive(chipselect,SPI_SCK_KHZ(500)); // chipSelect

	StaticJsonDocument<300> doc;
	
	flashDrive.init();
}

void datalog::senddata(){
	
	if(flashDrive.driveReady()){// if drive is attached
     flashDrive.resetFileList();
       while(flashDrive.listDir()){
         doc["Number"] = i;
         doc["Name"] = flashDrive.getFileName();
         doc["Size"] = flashDrive.getFileSizeStr();
         doc["Year"] = flashDrive.getYear();// returns int value
         doc["Month"] = flashDrive.getMonth();// returns int value
         doc["Day"] = flashDrive.getDay();// returns int value
         doc["Hour"] = flashDrive.getHour();// returns int value
         doc["Minute"] = flashDrive.getMinute();// returns int value
         doc["Second"] = flashDrive.getSecond();// returns int value
         switch(flashDrive.getFileAttrb()){
          case CH376_ATTR_READ_ONLY:
            doc["Attribute"] = "read only";
            break;
          case CH376_ATTR_HIDDEN:
             doc["Attribute"] = "hidden";
            break;
          case CH376_ATTR_SYSTEM:
            doc["Attribute"] = "system file";
            break;
          case CH376_ATTR_VOLUME_ID:
            doc["Attribute"] = "Volume label";
            break;
          case CH376_ATTR_DIRECTORY:
            doc["Attribute"] = "subdirectory (folder)";
            break;
          case CH376_ATTR_ARCHIVE:
            doc["Attribute"] = "archive (normal) file";
            break;         
         }
         serializeJson(doc, Serial);        
         serializeJsonPretty(doc, JSONmessageBuffer);
         Serial.println(JSONmessageBuffer);
         i++;
       }

  }
}
