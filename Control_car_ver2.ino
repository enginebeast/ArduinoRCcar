#include <Servo.h>
#include <SoftwareSerial.h>

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
}

void loop() {
  String input;
  String drive;
  String steerStr;
  int steer;
  int commaIndex;
  
  if (BtSerial.available()){
    input = BtSerial.readStringUntil('\n');

  commaIndex = input.indexOf(",");
  drive = input.substring(0, commaIndex);
  steerStr = input.substring(commaIndex + 1);
  steer = steerStr.toInt();

  //Stop
  if (drive == "S"){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(speed_a , 0);
    analogWrite(speed_b , 0);
  }

  //Forward
  else if (drive == "F"){
    //Left
    if (1 <= steer && steer < 256){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a, steer);
      analogWrite(speed_b, 255);
    }

    //Neutral and left
    else if (256 <= steer && steer <= 512){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a, steer - 257);
      analogWrite(speed_b, 255);
    }

    //Right
    else if (513 <= steer && steer <= 768){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a, 255);
      analogWrite(speed_b, 767 - steer);
    }

    //Right
    else if (769 <= steer && steer <= 1023){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(speed_a, 255);
      analogWrite(speed_b, steer - 768);
    }
  }

  //Backward
  else if (drive == "B"){
    //Left
    if (1 <= steer && steer <= 255){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(speed_a, steer);
      analogWrite(speed_b, 255);
    }

    //Neutral and left
    else if (256 <= steer && steer <= 512){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(speed_a, steer -257);
      analogWrite(speed_b, 255);
    }

    //Right
    else if (513 <= steer && steer <= 767){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(speed_a, 255);
      analogWrite(speed_b, 767 - steer);
    }

    //Right
    else if (769 <= steer & steer <= 1023){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(speed_a, 255);
      analogWrite(speed_b, steer - 768);
    }
  }
  }
}

