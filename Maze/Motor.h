#ifndef Motor_H_
#define Motor_H_

#include "stdint.h"
#include "Arduino.h"

class MotorL298
{
  
  public:
    MotorL298(int mA1,int mA2,int mENA,int mB1,int mB2,int mENB);        

    void runMA(int speed);
    void runMB(int speed);
    void moveForward(int speed);
    void moveForward(int M1speed, int M2speed);
    void moveBackward(int speed); 
    void turnRight(int speed);
    void turnLeft(int speed);
    void stop();
  private:
    int _A1;
    int _A2;
    int _ENA;
    int _B1;
    int _B2;
    int _ENB;
    
};
#endif
