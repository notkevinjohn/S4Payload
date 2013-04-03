/*
  S4WiFiSetup.cpp - Library for setting up the wifi shield
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/


// NEEED TO SET WIFIDEVICE TO PUBLIC NOT PRIVATE FUNCTIONS!!!!

  #include "Arduino.h"
  #include "WiFly.h"
  #include "S4WiFiSetup.h"
  #include "WiFlyDevice.h"
    
   S4WiFiSetup::S4WiFiSetup()
  {
           
  }
  
   void S4WiFiSetup::begin()
   {
     
      WiFly.uart.begin();
      WiFly.reboot();     
      Serial.print("Setup");
      WiFly.requireFlowControl();
      WiFly.enterCommandMode();     
   }
   

   void S4WiFiSetup::setDCHP(int value)
   {
       sendCommand("set ip dchp ",true);
       sendCommand(value,true);
       sendCommand("\r",true);
               
   }
   void S4WiFiSetup::setIpGateway(char* gateway)
   {
               
   }
   void S4WiFiSetup::setLocalPort(char* port)
   {
               
   }
   void S4WiFiSetup::setWlanAuth(int auth)
   {
               
   }
   void S4WiFiSetup::setDataRate(int rate)
   {
               
   }
   void S4WiFiSetup::setDeviceName(char* deviceName)
   {
               
   }
   void S4WiFiSetup::setRouterKey(char* routerKey)
   {
               
   }
   void S4WiFiSetup::setIpAddress(char* ipAddress)
   {
               
   }
   void S4WiFiSetup::setHostAdderss(char* hostAddress)
   {
               
   }
   void S4WiFiSetup::setBrodcastAddress(char* brodcastAddress)
   {
               
   }
   void S4WiFiSetup::setBordcastInterval(int seconds)
   {
               
   }
   void S4WiFiSetup::setExternalAntenna(bool isExtAnt)
   {
               
   }
   void S4WiFiSetup::setFlushSize(int size)
   {
               
   }
   void S4WiFiSetup::setProto(int proto)
   {
               
   }
   void S4WiFiSetup::setChannel(int channel)
   {
               
   }
   void S4WiFiSetup::setJoin(int join)
   {
               
   }


/*
  
void WiFlyDevice::setup(const char *deviceName, const char *accessPoint, boolean isWep, const char *key)
{
    DEBUG_LOG(1, "Entered WiFlyDevice::setup");   
    uart.begin();
    reboot();
    
    Serial.print("Setup");
    requireFlowControl();
    
    enterCommandMode();
    if(isWep)
    {
       sendCommand("set wlan auth 1 \r",true);
       
       sendCommand("set wlan key ",true);
       sendCommand(key,true);
       sendCommand("\r",true);
    }
    else
    {
       sendCommand("set wlan auth 0 \r",true);
    }
    sendCommand("set wlan ssid ",true);
    sendCommand(accessPoint,true);
    sendCommand("\r",true);
    
    sendCommand("set opt deviceid ",true);
    sendCommand(deviceName,true);
    sendCommand("\r",true);
    
    delay(3000);
    
    sendCommand("save \r",true);
     
}
*/
