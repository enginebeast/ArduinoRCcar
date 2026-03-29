#include <Servo.h>
#include <SoftwareSerial.h>

Servo steer;
int in1 = 3;
int in2 = 4;
int speed_a = 5;
int speed_b = 6;
int in3 = 7;
int in4 = 8;
int Rx = 9; //Receive
int Tx = 10; //Transmit

SoftwareSerial BtSerial(Rx,Tx);

void setup() {
  pinMode(speed_a, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(speed_b, OUTPUT);

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
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a , 0);
      analogWrite(speed_b , 0);
      
      break;

      //Move front
      case 1:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a , 255);
      analogWrite(speed_b , 255);
      
      break;
      
      //Move back
      case 2:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(speed_a , 255);
      analogWrite(speed_b , 255);

      break;

      //Center
      case 3:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a , 0);
      analogWrite(speed_b , 0);
      
      break;

      //Left
      case 4:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a , 255);
      analogWrite(speed_b , 255);

      break;
      
      //Right
      case 5:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(speed_a , 255);
      analogWrite(speed_b , 255);

      break;
    }
  }
}
