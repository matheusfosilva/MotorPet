#include <SoftwareSerial.h>

SoftwareSerial BT_Serial(2,3);

#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

char bt_data;
int Speed = 150;

void setup() {

  Serial.begin(9600);
  BT_Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  delay(200);
}

void loop() {

  if(BT_Serial.available() > 0) {
    bt_data = BT_Serial.read();
    Serial.println(bt_data);
  }

  if (bt_data == 'f') {
    forword(); 
    Speed = 180;
  } else if (bt_data == 'b') {
    backword(); 
    Speed = 180;
  } else if (bt_data == 'l') {
    turnLeft(); 
    Speed = 250;
  } else if (bt_data == 'r') {
    turnRight(); 
    Speed = 250;
  } else if (bt_data == 's') {
    breaking();
  }

 analogWrite(enA, Speed);
 analogWrite(enB, Speed);

 delay(50);

}

void forword(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
}

void backword(){
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
