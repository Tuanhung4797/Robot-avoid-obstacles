//Program for Robot avoid obstacles
//Hardware: Arduino Uno, Module L298, HCSR04, Servo SG90
//Author: Tuan Hung
//Github: https://github.com/Tuanhung4797
//Project: Maze Runner - UTE

#include <Servo.h>
#include "Sonar.h"
#include "Motor.h"

////////////// Thông số điều chỉnh robot   ///////////////////
#define DistanceStop  15  // Chọn khoảng cách dừng khi robot lại gần tường là 15 cm
#define TimeAngle90 500   // Chọn thời gian delay để quay đủ góc 90 độ cho robot là 500 ms
#define SpinSpeed 50      // Chọn tốc độ quay mặc định là 50%
#define Lspeed 80         // Chọn tốc độ chuẩn của bánh trái là 80%
#define Rspeed 80         // Chọn tốc độ chuẩn của bánh phải là 80%
//////////////////////////////////////////////////////

#define trig 3  //chân trig của HC-SR04
#define echo 4  //chân echo của HC-SR04
#define Servo_pin 5

#define inA1 6 //Định nghĩa chân in1 của động cơ bên Phải
#define inA2 7 //Định nghĩa chân in2 của động cơ bên Phải
#define inB1 8 //Định nghĩa chân in1 của động cơ bên Trái
#define inB2 9 //Định nghĩa chân in2 của động cơ bên Trái

Servo SV;  // tạo đối tượng cho Servo
Sonar Distance(trig, echo); // tạo đối tượng để đọc khoảng cách
MotorL298 Robot(inA1,inA2,inB1,inB2); // tạo đối tượng điều khiển motor
// Tốc độ của robot tính bằng %

float Ahead;  // Tạo biến lưu khoảng cách phía trước
float Right;  // Tạo biến lưu khoảng cách bên phải
float Left;   // Tạo biến lưu khoảng cách bên trái

void setup()
{
  pinMode(inA1, OUTPUT);  //Set chân in1 của dc A là output
  pinMode(inA2, OUTPUT);  //Set chân in2 của dc A là output
  pinMode(inB1, OUTPUT);  //Set chân in1 của dc B là output
  pinMode(inB2, OUTPUT);  //Set chân in2 của dc B là output

  Serial.begin(9600);
  SV.attach(Servo_pin);
  SV.write(90);
}
void SaveDistance()
{
  SV.write(90);
  Ahead = Distance.ReadDistance(); // lưu khoảng cách phía trước
  delay(500);
  SV.write(0);
  Left = Distance.ReadDistance(); // lưu khoảng cách bên trái
  delay(500);
  SV.write(180);
  Right = Distance.ReadDistance(); // lưu khoảng cách bên phải
  delay(500);
  SV.write(90); // Trả cảm biến khoảng cách về phía trước
}
void Rotate() // Đọc khoảng cách 3 hướng, ưu tiên đi về phía  bên phải, sau đó là bên trái, nếu không được thì quay lui
{
  SaveDistance();
  if(Right > 20)
  {
    Robot.turnRight(SpinSpeed);  // Quay phải 90 độ
    delay(TimeAngle90);
    Robot.stop();
  }
  else if(Left > 20)
  {
    Robot.turnLeft(SpinSpeed);   // Quay trái 90 độ
    delay(TimeAngle90);
    Robot.stop();
  }
  else
  {
    Robot.turnLeft(SpinSpeed); // Quay 90 độ lần 1
    delay(TimeAngle90);
    Robot.stop();
    ///////////////////////////////
    Robot.turnLeft(SpinSpeed); // Quay 90 độ lần 2
    delay(TimeAngle90);
    Robot.stop();
  }
}
void loop()
{
  while(!(Distance.ReadDistance() < DistanceStop)) // chạy thẳng tới khi khoảng cách < 15 cm
  {
    Robot.moveForward(Lspeed, Rspeed);
  }
  Robot.stop();
  delay(1000);
  Rotate(); // Khi phía trước < 15 cm thì đo khoảng cách 3 hướng và tiến hành quay robot
  delay(1000);
}

