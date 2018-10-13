#ifndef Motor_H_
#define Motor_H_

#include "stdint.h"
#include "Arduino.h"

class MotorL9110
{
  
  public:
    MotorL9110(int motor1A,int motor1B,int motor2A,int motor2B);        

    void runM1(int speed);
    void runM2(int speed);
    void moveForward(int speed);
    void moveForward(int M1speed, int M2speed);
    void moveBackward(int speed); 
    void turnRight(int speed);
    void turnLeft(int speed);
    void stop();
  private:
    int _M1A;
    int _M1B;
    int _M2A;
    int _M2B; 
    
};
#endif
