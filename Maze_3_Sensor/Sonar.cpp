
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Sonar.h"

Sonar::Sonar(int TP, int EP)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=3000;  // 3000 µs = 50cm // 30000 µs = 5 m 
}

Sonar::Sonar(int TP, int EP, long TO)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=TO;
}

long Sonar::Timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH,Time_out);
  if ( duration == 0 ) {
	duration = Time_out; }
  return duration;
}

float Sonar::Ranging(int sys)
{
  Timing();
  if (sys) {
	distance_cm = duration /29.41 / 2 ;
	return distance_cm;
  } else {
	distance_inc = duration / 74.70 / 2;
	return distance_inc; }
}
float Sonar::ReadDistance()
{
  float range = Ranging(CM);
  delay(100);
  return range;
}
