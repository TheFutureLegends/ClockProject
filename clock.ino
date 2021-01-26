#include <Servo.h>
//Declaring servos as variables
Servo myservo[14];

//int segmentOff[7] = {0,180,0,0,180,0,0};      //Servo off position values for each servo
int segmentOn[7] = {90,90,85,82,86,90,90};  //Servo on position values for each servo
int digits[10][7] = {
  {90,90,0,82,86,90,90},        // Number 0
  {0,180,0,82,180,0,90},        // Number 1
  {90,180,85,82,86,90,0},       // Number 2
  {90,180,85,82,180,90,90},     // Number 3
  {0,90,85,82,180,0,90},        // Number 4
  {90,90,85,0,180,90,90},       // Number 5
  {90,90,85,0,86,90,90},        // Number 6
  {90,180,0,82,180,0,90},       // Number 7
  {90,90,90,82,86,90,90},       // Number 8
  {90,90,85,82,180,90,90}       // Number 9
};

void setup()
{
  //Assigng pin number for each servo
  myservo[0].attach(11);  //045
  myservo[1].attach(10);  //1
  myservo[2].attach(9);   //2
  
  myservo[3].attach(7);   //3610
  myservo[4].attach(6);   //4
  myservo[5].attach(5);   //5
  myservo[6].attach(3);   //60

 for(int i = 0; i < 7;i++)
 {
    myservo[i].write(segmentOn[i]);
    
 }
 delay(3000);
}

void loop()
{
  for(int i = 9; i >= 0;i--)
  {
    for(int j = 0; j < 7; j++)
    {
      myservo[j].write(digits[i][j]);
    }
    delay(2000);
  }
}