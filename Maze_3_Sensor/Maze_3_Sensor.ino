//Program for Robot avoid obstacles
//Hardware: Arduino Uno, Module L298, HCSR04, ADXL335
//Author: Tuan Hung
//Github: https://github.com/Tuanhung4797
//Project: Maze Runner - UTE

#include <Servo.h>
#include "Sonar.h"
#include "Motor.h"

////////////// Thông số điều chỉnh robot   ///////////////////
#define DistanceStop  15  // Chọn khoảng cách dừng khi robot lại gần tường là 15 cm
#define SpinSpeed 50      // Chọn tốc độ quay mặc định là 50%
#define Lspeed 80         // Chọn tốc độ chuẩn của bánh trái là 80%
#define Rspeed 80         // Chọn tốc độ chuẩn của bánh phải là 80%

#define C90 
/////////////////////////////////////////////////////////////
#define inA1 2 //Định nghĩa chân in1 của động cơ bên Phải
#define inA2 3 //Định nghĩa chân in2 của động cơ bên Phải
#define inB1 4 //Định nghĩa chân in1 của động cơ bên Trái
#define inB2 5 //Định nghĩa chân in2 của động cơ bên Trái

#define trig1 6  //chân trig của HC-SR04
#define echo1 7  //chân echo của HC-SR04

#define trig2 8  
#define echo2 9  

#define trig3 10 
#define echo3 11 

#define Cx  A2
#define Cy  A1
#define Cz  A0

Sonar SonarF(trig1, echo1); // tạo đối tượng để đọc khoảng cách
Sonar SonarR(trig2, echo2);
Sonar SonarL(trig3, echo3);

MotorL9110 Robot(inA1,inA2,inB1,inB2); // tạo đối tượng điều khiển motor
                                      // Tốc độ của robot tính bằng %

float F;  // Tạo biến lưu khoảng cách phía trước
float R;  // Tạo biến lưu khoảng cách bên phải
float L;  // Tạo biến lưu khoảng cách bên trái

void setup()
{
  Serial.begin(9600);
}

void loop()
{
//  while(!(Distance.ReadDistance() < DistanceStop)) // chạy thẳng tới khi khoảng cách < 15 cm
//  {
//    Robot.moveForward(Lspeed, Rspeed);
//  }
  Serial.println(analogRead(A0));
  delay(300);
}

