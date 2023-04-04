/*
  Created by: Samuel Webster
  Created on: Feb 2023
  Uses distance sensor
*/
#include <Servo.h>
Servo servo;
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
bool isClose = false;

float duration, distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  servo.attach(13);
  servo.write(0);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance <= 50) {
    isClose = true;
  } else {
    isClose = false;
  }
  Serial.print("Is close: ");
  Serial.println(isClose);
  if (isClose) {
    servo.write(90);
  } else {
    servo.write(0);
  }
  delay(100);
}
