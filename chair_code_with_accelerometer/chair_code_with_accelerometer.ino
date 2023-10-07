#include <SoftwareSerial.h>

SoftwareSerial BT_Serial(2, 3); // TX, RX

#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

int Speed = 100;
char last = '0'; // Inicializa com um valor que não representa nenhuma direção
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
  if (BT_Serial.available() > 0) {
    Direction = BT_Serial.read();
    Serial.println(Direction);

    if (Direction != '0') { // Se recebeu uma nova direção
      executeDirection(Direction);
      last = Direction;
    }
  } else if (last != '0') { // Nenhuma nova direção informada, continua a última direção
    stopMotors();
    last = '0';
  }

  analogWrite(enA, Speed);
  analogWrite(enB, Speed);
}

void executeDirection(char direction) {
  if (direction == '1') {
    accelerate();
  } else if (direction == '2') {
    re();
  } else if (direction == '3') {
    turnRight();
  } else if (direction == '4') {
    turnLeft();
  }
}


void accelerate() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void re() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
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

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
