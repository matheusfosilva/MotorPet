#include <SoftwareSerial.h>

SoftwareSerial BT_Serial(2,3); //TX,RX

#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

int Speed = 120;
char Direction;

void setup() {
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600);
  BT_Serial.begin(9600);

  delay(200);
}

void loop() {

 Direction = '0';

   while(BT_Serial.available() > 0) {
    Direction = BT_Serial.read();
  }

  if (Direction == '1' ) {
    accelerate(); 
  } else if (Direction == '2') {
     re();
  } else if (Direction == '3') {
    turnRight(); 
  } else if (Direction == '4') {
    turnLeft(); 
  } else if ( Direction == '0' ) {
    breaking();
  }
  
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);
 delay(100);
}

void accelerate(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
}

void re(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
}

void turnRight(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
}

void breaking(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}
