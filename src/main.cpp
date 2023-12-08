#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>

const int rxPin = 1;
const int txPin = 0;
const int trigPin = 12;
const int echoPin = 11;
long duration;
int distance;
int leftDistance;
int rightDistance;
const int leftMotorsForward = 2;
const int leftMotorsBackward = 3;
const int rightMotorsForward = 4;
const int rightMotorsBackward = 5;
const int leftMotorsSpeedPin = 10;
const int rightMotorsSpeedPin = 9;
const int servoPin = 13;
int leftMotorsSpeed = 100;  // 0-255
int rightMotorsSpeed = 100; // 0-255
Servo servo;

void setup()
{
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftMotorsForward, OUTPUT);   // left motors  forward
  pinMode(leftMotorsBackward, OUTPUT);  // left motors reverse
  pinMode(rightMotorsForward, OUTPUT);  // right  motors forward
  pinMode(rightMotorsBackward, OUTPUT); // right motors reverse
  pinMode(leftMotorsSpeedPin, OUTPUT);  // left motors speed
  pinMode(rightMotorsSpeedPin, OUTPUT); // right motors speed
  Serial.begin(9600);

  analogWrite(leftMotorsSpeedPin, leftMotorsSpeed);   // left motors speed
  analogWrite(rightMotorsSpeedPin, rightMotorsSpeed); // right motors speed
}
void forward();
void reverse();
void stop();
void left();
void right();
// void distanceCheck();
// void slowDown();
// void speedUp();
// void lookLeft();
// void lookRight();

void loop()
{
  forward();
  delay(1000);
  stop();
  reverse();
  delay(1000);
  stop();
  delay(1000);
  
  // distanceCheck();
  // if (distance > 75)
  // {
  //   printf("distance>75");
  //   forward();
  //   speedUp();
  // }
  // else
  // {
  //   Serial.print("distance<75");
  //   slowDown();
  //   lookRight();
  //   delay(1000);
  //   distanceCheck();
  //   rightDistance = distance;
  //   lookLeft();
  //   delay(1000);
  //   distanceCheck();
  //   leftDistance = distance;
  //   if (leftDistance > rightDistance)
  //   {
  //     Serial.print("leftDistance>rightDistance");
  //     stop();
  //     left();
  //     delay(1000);
  //     stop();
  //     distanceCheck();
  //   }
  //   else
  //   {
  //     Serial.print("leftDistance<rightDistance");
  //     stop();
  //     right();
  //     delay(1000);
  //     stop();
  //     distanceCheck();
  //   }
  // }
  delay(100);
}

// void speedUp()
// {
//   if (leftMotorsSpeed < 100 && rightMotorsSpeed < 100)
//     for (int i = 0; i < 4; i++)
//     {
//       leftMotorsSpeed += 10;
//       rightMotorsSpeed += 10;
//     }
// }

// void slowDown()
// {
//   if (leftMotorsSpeed > 50 && rightMotorsSpeed > 50)
//     for (int i = 0; i < 5; i++)
//     {
//       leftMotorsSpeed -= 10;
//       rightMotorsSpeed -= 10;
//     }
// }

// void lookLeft()
// {
//   servo.write(15);
// }

// void lookRight()
// {
//   servo.write(165);
// }

void forward()
{
  digitalWrite(leftMotorsForward, HIGH);
  digitalWrite(rightMotorsForward, HIGH);
}
void reverse()
{
  digitalWrite(leftMotorsBackward, HIGH);
  digitalWrite(rightMotorsBackward, HIGH);
}
void stop()
{
  digitalWrite(leftMotorsBackward, LOW);
  digitalWrite(rightMotorsBackward, LOW);
  digitalWrite(leftMotorsForward, LOW);
  digitalWrite(rightMotorsForward, LOW);
}
void left()
{
  digitalWrite(leftMotorsBackward, HIGH);
  digitalWrite(rightMotorsForward, HIGH);
}
void right()
{
  digitalWrite(leftMotorsForward, HIGH);
  digitalWrite(rightMotorsBackward, HIGH);
}

// void distanceCheck()
// {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   duration = pulseIn(echoPin, HIGH);
//   distance = duration * 0.034 / 2;
//   Serial.print("Distance: ");
//   Serial.println(distance);
// }