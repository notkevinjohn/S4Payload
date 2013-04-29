/*
  HIH6310.h - Library for reading the sensors supported
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #ifndef HIH6310_h
  #define HIH6310_h
  #include "Arduino.h"
  
  class HIH6310
  {
        public:
               HIH6310();
               byte getHumidity(double &humidity, double &temperature);
               
        private:
               
  };
  #endif
