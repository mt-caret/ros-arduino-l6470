#include "Arduino.h"
#include <l6470.h>

#define USE_USBCON

#include <ros.h>
#include <std_msgs/String.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

const int SPI_CS_LEFT = 8, SPI_CS_RIGHT = 9;
L6470 leftMotor(SPI_CS_LEFT), rightMotor(SPI_CS_RIGHT);

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[] = "hello, world!";

void setup() {
  nh.initNode();
  nh.advertise(chatter);

  //Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  //leftMotor.initialize();
  //rightMotor.initialize();
  //leftMotor.setStepMode(StepMode::microstep_128);
  //rightMotor.setStepMode(StepMode::microstep_128);
  //leftMotor.setKVal(KVal::hold, 255);
  //leftMotor.setKVal(KVal::run, 255);
  //leftMotor.setKVal(KVal::acc, 255);
  //leftMotor.setKVal(KVal::dec, 255);
}

void loop() {
  str_msg.data = hello;
  chatter.publish(&str_msg);
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

  delay(1000);
}
