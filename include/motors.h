#ifndef MOTORS_H_
#define MOTORS_H_
#include "main.h"

typedef struct motor{
  char port;
  bool reversed;
}motor;

motor claw;
motor mogoR;
motor mogoL;
motor RDrive;
motor LDrive;
motor arm1R;
motor arm1L;
motor arm2;

void betterMotorSet(motor motor, signed char speed);
 #endif
