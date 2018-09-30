#include "Motor.h"

MotorL298::MotorL298(int motor1A,int motor1B,int motor2A,int motor2B)
{
  _M1A = motor1A;
  _M1B = motor1B;
  _M2A = motor2A;
  _M2B = motor2B;
  pinMode(_M1A, OUTPUT);
  pinMode(_M1B, OUTPUT);
  pinMode(_M2A, OUTPUT);
  pinMode(_M2B, OUTPUT);
}

void MotorL298::runM1(int speed)
{
  speed = speed > 255 ? 255 : speed;   // if speed > 255 => speed = 255
  speed = speed < -255 ? -255 : speed; // if speed < -255 => speed = -255
  if(speed >= 0)
  {
    analogWrite(_M1A,speed);
    analogWrite(_M1B,0);
  }
  else
  {
    analogWrite(_M1A,0);
    analogWrite(_M1B,-speed);
  } 
}
void MotorL298::runM2(int speed)
{
  speed = speed > 255 ? 255 : speed;   // if speed > 255 -> speed = 255
  speed = speed < -255 ? -255 : speed; // if speed < -255 -> speed = -255
  if(speed >= 0)
  {
    analogWrite(_M2A,speed);
    analogWrite(_M2B,0);
  }
  else
  {
    analogWrite(_M2A,0);
    analogWrite(_M2B,-speed);
  }
}
void MotorL298::stop()
{
  analogWrite(_M1A, 0);
  analogWrite(_M1B, 0);
  analogWrite(_M2A, 0);
  analogWrite(_M2B, 0);
}
void MotorL298::moveForward(int speed)
{
  int speedMotor = speed*255/100; 
  runM1(speedMotor);
  runM2(speedMotor);
}
void MotorL298::moveForward(int M1speed, int M2speed)
{
  int speedM1 = M1speed*255/100;
  int speedM2 = M2speed*255/100;
  runM1(speedM1);
  runM2(speedM2);
}
void MotorL298::moveBackward(int speed)
{
  int speedMotor = speed*255/100;
  runM1(-speedMotor);
  runM2(-speedMotor);
}
void MotorL298::turnRight(int speed)
{
  int speedMotor = speed*255/100;
  runM1(-speedMotor);
  runM2(speedMotor);
}
void MotorL298::turnLeft(int speed)
{
  int speedMotor = speed*255/100;
  runM1(speedMotor);
  runM2(-speedMotor);
}
