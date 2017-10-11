#include "main.h"

//wow, look at that symmetry below, I totally planned it that way
motor claw = {2, false};
motor mogoR = {3, true};
motor mogoL = {4, false};
motor RDrive = {5, true };
motor LDrive = {6, false};
motor arm1R = {7, false};
motor arm1L = {8, true};
motor arm2 = {9, true};

void betterMotorSet(motor motor, signed char speed) {
	motor.reversed ? motorSet(motor.port, -speed) : motorSet(motor.port, speed);
}
