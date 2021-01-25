#include <Servo.h>

const int NSERVOS = 7;
const int ON = 90;
Servo myservo[NSERVOS];

int offset[7] = {0, 0, -20, 0, -10, 0, -10};      //Servo on position values for each servo
int numbers[10][7] = {{1, 1, 0, 1, 1, 1, 1}, {0, 0, 0, 1, 0, 0, 1}, {1, 0, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 0, 0, 1, 1}, {1, 1, 1, 0, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 1}};

void on(int i){
    myservo[i].write(ON + offset[i]);
}

void off(int i){
    int mode;
    if (i == 1 || i == 4 || i == 5) mode = 1;
    else mode = -1;
    myservo[i].write(ON + offset[i] + 60*mode);
}

void onAll(){
  for (int i = 0; i < 7; ++i)
    on(i);
}

void offAll(){
  for (int i = 0; i < 7; ++i)
    off(i);
}

void changeNum(int num){
  for (int i = 0; i < 7; ++i)
    if (numbers[num][i]){
      on(i);
    }
    else{
      off(i);
    }
}

void setup()
{
  //Assigng pin number for each servo
  myservo[0].attach(11);
  myservo[1].attach(10);
  myservo[2].attach(9);
  myservo[3].attach(7);
  myservo[4].attach(6);
  myservo[5].attach(5);
  myservo[6].attach(3);
  Serial.begin(9600);
  onAll();
}
 int incomingByte;
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();
    changeNum(incomingByte);
   Serial.read(); 
  }
  /*
  onAll();
  delay(2000);
  offAll();
  delay(2000);
  */

//  This is just some random bullshit
}