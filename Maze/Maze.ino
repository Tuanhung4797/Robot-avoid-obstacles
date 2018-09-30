//Program for Robot avoid obstacles
//Hardware: Arduino Uno, module L298, HCSR04, Servo SG90
//Author: Tuan Hung
//Github: https://github.com/Tuanhung4797
//Project: Maze Runner - UTE

#include <Servo.h>
#include "EasySonar.h"
#include "Motor.h"

////////////// Thông số điều chỉnh robot   ///////////////////
#define DistanceStop  15  // Chọn khoảng cách dừng khi robot lại gần tường là 15 cm
#define TimeAngle90 500   // Chọn thời gian delay để quay đủ góc 90 độ cho robot là 500 ms
#define Lspeed 80      // Chọn tốc độ chuẩn của bánh trái là 80%
#define Rspeed 80      // Chọn tốc độ chuẩn của bánh phải là 80%
//////////////////////////////////////////////////////

#define trig 3 //chân trig của HC-SR04
#define echo 4//chân echo của HC-SR04
#define Servo_pin 5

#define inA1 6 //Định nghĩa chân in1 của động cơ A
#define inA2 7 //Định nghĩa chân in2 của động cơ A
#define inB1 8 //Định nghĩa chân in1 của động cơ B
#define inB2 9 //Định nghĩa chân in2 của động cơ B

Servo SV;  // create servo object to control a servo
EasySonar Distance(trig, echo); // tạo đối tượng để đọc khoảng cách
MotorL298 Motor(inA1,inA2,inB1,inB2); // tạo đối tượng điều khiển motor
// Tốc độ của robot tính bằng %

float Truoc // Tạo biến lưu khoảng cách phía trước
float Phai  // Tạo biến lưu khoảng cách bên phải
float Trai  // Tạo biến lưu khoảng cách bên trái

void setup()
{
  pinMode(inA1, OUTPUT);//Set chân in1 của dc A là output
  pinMode(inA2, OUTPUT);//Set chân in2 của dc A là output
  pinMode(inB1, OUTPUT);//Set chân in1 của dc B là output
  pinMode(inB2, OUTPUT);//Set chân in2 của dc B là output

  Serial.begin(9600);
  SV.attach(Servo_pin);
}
void SaveDistance()
{
  Sv.write(90);
  Truoc = Distance.ReadDistance(); // lưu khoảng cách phía trước
  delay(500);
  Sv.write(0);
  Trai = Distance.ReadDistance(); // lưu khoảng cách bên trái
  delay(500);
  Sv.write(180);
  Phai = Distance.ReadDistance(); // lưu khoảng cách bên phải
  delay(500);
  Sv.write(90); // Trả cảm biến khoảng cách về phía trước
}
void loop()
{
  
}

