/*
  S4.cpp - Library for the overall S4 Program
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #include "S4.h"
  #include "Arduino.h"
  #include "WiFly.h"
  #include "S4GPS.h"
  #include "Wire.h"
  #include <SoftwareSerial.h>
  
  #define microRX 5
  #define microTX 4
  #define buadRate 9600
  
  #define BUFFSIZE 90
  
  S4GPS S4GPS;  
  
  bool WiFiIsOn = true; // used to turn on or off the WiFi connection
  
  char gps[BUFFSIZE];
  String sensorData;
  
  SoftwareSerial microSerial = SoftwareSerial(microRX, microTX); 
  


  
  S4::S4()
  {   
  }
  void S4::begin(String DeviceName, char* RouterName)
  {
       WDTCSR |= (1 << WDCE) | (1 << WDE);
       WDTCSR = 0;
       microSerial.begin(buadRate);  // this had to be before the gps
       Wire.begin(); 
       
       
       S4GPS.begin(buadRate);
       
       if(WiFiIsOn)
       {
           WiFly.begin();                // start the WiFly process
           WiFly.join(RouterName); // connect to the router
           WiFiHankshake(DeviceName);    // connect to the server
       }
      
      
       
       
       sensorData = "<sensor>";
       Serial.println("Starting");
  }
  
  bool S4::WiFiHankshake(String DeviceName)
  {
       
       boolean start = false;
       long previousMillis = 0;
       long interval = 1000;
       char tempChar;
       
       while(!start)
       {
          SpiSerial.println("open");
          delay(100);
          while(SpiSerial.available() > 0) 
          {
              tempChar = SpiSerial.read();
              Serial.write(tempChar);
              if(tempChar == '#')
              {
                  SpiSerial.print("DeviceName");
                  SpiSerial.println(DeviceName);
              }
              if(tempChar == '@')
              {
                  delay (1000);
                  start = true;
              }
          }
          delay(900);
       }
          Serial.println("START");
                 
       
      return start;
  }
  
  int S4::getIncommingMessage()
  {
      char tempChar;
      int command = 0;
      while(SpiSerial.available() > 0) 
      {
        tempChar = SpiSerial.read();
        
        if(tempChar == '&')
        {
          tempChar = SpiSerial.read();
          command = tempChar;
        }
      }
      return command-48;  // to drop the askii down to the number
  } 
       
  bool S4::writeData()
  {
      bool wait = true;
      int command;
      if(S4GPS.getGPS(gps))
      {   
          Serial.print("<gps>");
          Serial.print(gps);
          Serial.println("</gps>");
          
          sensorData += "</sensor>";
          Serial.println(sensorData);
          
          
          microSerial.print("<gps>");
          microSerial.print(gps);
          microSerial.print("</gps>");
          
          microSerial.print(sensorData);
          
          if(WiFiIsOn)
          {
              SpiSerial.print("<gps>");      
              SpiSerial.print(gps);
              SpiSerial.print("</gps>");
              SpiSerial.print(sensorData);
              command = getIncommingMessage(); 
          }
          sensorData = "<sensor>";
          wait = false;
      }
      return wait;
    } 
    
  int S4::getCommand()
  {
     int command; 
     command = getIncommingMessage();  
     return command; 
  }
 
 
  void S4::addData(char* key, int value)
  {
      sensorData += ",";
      sensorData += key;
      sensorData += ",";
      sensorData += value;
  }
   
  void S4::addData(char* key, char* value)
  {
      sensorData += ",";
      sensorData += key;
      sensorData += ",";
      sensorData += value;  
  }
  void S4::addData(char* key, long value)
  {
      sensorData += ",";
      sensorData += key;
      sensorData += ",";
      sensorData += value;   
  }
  void S4::addData(char* key, unsigned int value)
  {
      sensorData += ",";
      sensorData += key;
      sensorData += ",";
      sensorData += value; 
  }   
  void S4::addData(char* key, double value, int precision)
  {
      sensorData += ",";
      sensorData += key;
      sensorData += ",";
      char output[10];
      dtostrf(value,2,precision,output);
      sensorData += output; 
  } 
  
  void S4::useWiFi(bool statement)
  {
      WiFiIsOn = statement;
  }
