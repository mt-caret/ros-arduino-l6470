#include "Arduino.h"
#include <l6470.h>

#define USE_USBCON

#include <ros.h>
#include <robot_lab/MotorCommand.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

const int SPI_CS_LEFT = 8, SPI_CS_RIGHT = 9;
L6470 leftMotor(SPI_CS_LEFT), rightMotor(SPI_CS_RIGHT);

ros::NodeHandle nh;

Direction numberToDirection(float number) {
  return number >= 0.0 ? Direction::forward : Direction::reverse;
}

void motorCommandCallback(const robot_lab::MotorCommand& msg) {
  if (msg.left == 0.0 && msg.right == 0.0) {
    if (msg.hardStop) {
      leftMotor.hardStop();
      rightMotor.hardStop();
    } else {
      leftMotor.softStop();
      rightMotor.softStop();
    }
    return;
  }
  leftMotor.run(numberToDirection(msg.left), abs(msg.left));
  rightMotor.run(numberToDirection(msg.right), abs(msg.right));
}

ros::Subscriber<robot_lab::MotorCommand> subscriber("motor", &motorCommandCallback);

void setup() {
  nh.initNode();
  nh.subscribe(subscriber);

  pinMode(LED_BUILTIN, OUTPUT);

  leftMotor.initialize();
  rightMotor.initialize();
  leftMotor.setStepMode(StepMode::microstep_128);
  rightMotor.setStepMode(StepMode::microstep_128);
  leftMotor.setKVal(KVal::hold, 255);
  leftMotor.setKVal(KVal::run, 255);
  leftMotor.setKVal(KVal::acc, 255);
  leftMotor.setKVal(KVal::dec, 255);
}

void loop() {
  nh.spinOnce();
  //digitalWrite(LED_BUILTIN, HIGH);
  //leftMotor.run(Direction::forward, 4000);
  //rightMotor.run(Direction::forward, 4000);

  ////leftMotor.updateStatus();
  ////leftMotor.printStatus();

  //delay(10000);

  //digitalWrite(LED_BUILTIN, LOW);
  //leftMotor.softStop();
  //rightMotor.softStop();
  delay(1);
}
