#include <Servo.h>
#include <SoftwareSerial.h>

Servo steer;
int in1 = 4;
int in2 = 5;
int speed = 6;
int Rx = 7; //Receive
int Tx = 8; //Transmit
int Servo = 9;

SoftwareSerial BtSerial(Rx,Tx);

void setup() {
  pinMode(speed, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.begin(9600);
  BtSerial.begin(9600);

  steer.attach(Servo, 500, 2500);
}

void loop() {
  if (BtSerial.available()) {
    switch(BtSerial.read()){
      //Stop
      case 0:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(speed , 0);
      break;

      //Move front
      case 1:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(speed , 255);
      break;
      
      //Move back
      case 2:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(speed , 255);
      break;

      //Center
      case 3:
      steer.writeMicroseconds(1500);
      break;

      //Left
      case 4:
      steer.writeMicroseconds(2000);
      break;
      
      //Right
      case 5:
      steer.writeMicroseconds(1000);
      break;
    }
  }
}
