/*
  S4WiFiSetup.h - Library for setting up the wifi shield
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
  
  To use this libary the WiFiDevive.h needs to set functions to public
*/
  #ifndef S4WiFiSetup_h
  #define S4WiFiSetup_h
  #include "Arduino.h"
  #include "WiFly.h"
  
  
   class S4WiFiSetup
  {
        public:
               S4WiFiSetup();
               void begin();
               void setDCHP(int value);
               void setIpGateway(char* gateway);
               void setLocalPort(char* port);
               void setWlanAuth(int auth);
               void setDataRate(int rate);
               void setDeviceName(char* deviceName);
               void setRouterKey(char* routerKey);
               void setIpAddress(char* ipAddress);
               void setHostAdderss(char* hostAddress);
               void setBrodcastAddress(char* brodcastAddress);
               void setBordcastInterval(int seconds);
               void setExternalAntenna(bool isExtAnt);
               void setFlushSize(int size);
               void setProto(int proto);
               void setChannel(int channel);
               void setJoin(int join);
               
               
               
        private:
                
  };
  #endif
