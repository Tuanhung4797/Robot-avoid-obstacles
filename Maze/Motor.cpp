#include "Motor.h"

MotorL298::MotorL298(int mA1,int mA2,int mENA,int mB1,int mB2,int mENB)
{
  _A1 = mA1;
  _A2 = mA2;
  _ENA = mENA;
  _B1 = mB1;
  _B2 = mB2;
  _ENB = mENB;
  pinMode(_A1, OUTPUT);
  pinMode(_A2, OUTPUT);
  pinMode(_ENA, OUTPUT);
  pinMode(_B1, OUTPUT);
  pinMode(_B2, OUTPUT);
  pinMode(_ENB, OUTPUT);
}

void MotorL298::runMA(int speed)
{
  speed = speed > 255 ? 255 : speed;   // if speed > 255 => speed = 255
  speed = speed < -255 ? -255 : speed; // if speed < -255 => speed = -255
  if(speed >= 0)
  {
    digitalWrite(_A1, HIGH);
    digitalWrite(_A2, LOW);
    analogWrite(_ENA, speed);
  }
  else
  {
    digitalWrite(_A1, LOW);
    digitalWrite(_A2, HIGH);
    analogWrite(_ENA, -speed);
  } 
}
void MotorL298::runMB(int speed)
{
  speed = speed > 255 ? 255 : speed;   // if speed > 255 -> speed = 255
  speed = speed < -255 ? -255 : speed; // if speed < -255 -> speed = -255
  if(speed >= 0)
  {
    digitalWrite(_B1, HIGH);
    digitalWrite(_B2, LOW);
    analogWrite(_ENB, speed);
  }
  else
  {
    digitalWrite(_B1, HIGH);
    digitalWrite(_B2, LOW);
    analogWrite(_ENB, -speed);
  }
}
void MotorL298::stop()
{
  analogWrite(_ENA, 0);
  analogWrite(_ENB, 0);
}
void MotorL298::moveForward(int speed)
{
  int speedMotor = speed*255/100; 
  runMA(speedMotor);
  runMB(speedMotor);
}
void MotorL298::moveForward(int MAspeed, int MBspeed)
{
  int speedMA = MAspeed*255/100;
  int speedMB= MBspeed*255/100;
  runMA(speedMA);
  runMB(speedMB);
}
void MotorL298::moveBackward(int speed)
{
  int speedMotor = speed*255/100;
  runMA(-speedMotor);
  runMB(-speedMotor);
}
void MotorL298::turnRight(int speed)
{
  int speedMotor = speed*255/100;
  runMA(-speedMotor);
  runMB(speedMotor);
}
void MotorL298::turnLeft(int speed)
{
  int speedMotor = speed*255/100;
  runMA(speedMotor);
  runMB(-speedMotor);
}
