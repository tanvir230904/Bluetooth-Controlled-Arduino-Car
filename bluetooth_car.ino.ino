#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

// Motor pins
int IN1 = 4;
int IN2 = 3;
int IN3 = 6;
int IN4 = 7;

int ENA = 5;
int ENB = 9;

char command;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  stopCar();   // ✔ now correctly defined below
}

void loop() {
  if (BT.available()) {
    command = BT.read();

    Serial.println(command);

    if (command == '\n' || command == '\r' || command == ' ') return;

    switch (command) {

      case 'L': moveForward(); break;
      case 'R': moveBackward(); break;
      case 'F': turnLeft(); break;
      case 'B': turnRight(); break;
      case 'S': stopCar(); break;

      default: stopCar(); break;
    }
  }
}

// ================= MOTOR FUNCTIONS =================

void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void moveBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}