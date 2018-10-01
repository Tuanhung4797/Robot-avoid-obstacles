
#ifndef Sonar_h
#define Sonar_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CM 1
#define INC 0

class Sonar
{
  public:
    Sonar(int TP, int EP);
  	Sonar(int TP, int EP, long TO);
    long Timing();
    float Ranging(int sys);
    float ReadDistance();

  private:
    int Trig_pin;
    int Echo_pin;
	  long Time_out;
    float duration,distance_cm,distance_inc;
};

#endif
