/*
  S4Sensor.cpp - Library for the Sensors Supported by S4
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #include "S4Sensor.h"
  #include "Arduino.h"
  #include "WiFly.h"
  #include "S4GPS.h"
  #include "Wire.h"
  #include "SoftwareSerial.h"
  #include "BMP085.h"
  #include "ADXL345.h"
  #include "HIH6310.h"
  #include "HMC5883L.h"
  #include "S4Accelerometer.h"

  BMP085 presSen = BMP085(); 
  HIH6310 hum = HIH6310();
  HMC5883L mag = HMC5883L();
  S4Accelerometer accel = S4Accelerometer();
  
  S4Sensor::S4Sensor()
  {   
      
  }
  void S4Sensor::startBarometric()
  {
       presSen.init();
  }
       
  void S4Sensor::getBarometric(long & pressure, double &temperature)
  {
       long temp;
       presSen.getPressure(&pressure);
       presSen.getTemperature(&temp);
       temperature = (double)temp/10.0;
       
  }
  void S4Sensor::startHumidity()
  {
  }
  
  byte S4Sensor::getHumidity(double &humidity, double &temperature)
  {
    return hum.getHumidity(humidity, temperature);
  }

  void S4Sensor::startAccelerometer()
  {
       accel.init(1,1,1,10,255);
  }
  void S4Sensor::getAccelerometer(double &accelX, double &accelY, double &accelZ)
  {
       accel.getAccel(accelX,accelY,accelZ);
  }
  void S4Sensor::startMagnetometer()
  {    
      mag.init();
  }
  void S4Sensor::getMagnetometer(int &magX, int &magY, int &magZ)
  {
       mag.getMagnetometer(magX,magY,magZ);
  }
