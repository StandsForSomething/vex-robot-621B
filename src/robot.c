#include "main.h"

void driveSet(signed char left, signed char right) {
	betterMotorSet(LDrive, left);
	betterMotorSet(LDrive, right);
}

void armSetStage1(signed char power) {
	betterMotorSet(arm1L, power);
	betterMotorSet(arm1R, power);
}

void armSetStage2(signed char power) {
	betterMotorSet(arm2, power);
}

void armSetBothStages(signed char stage1, signed char stage2) {
	armSetStage1(stage1);
	armSetStage2(stage2);
}

void mogoSet(signed char power) {
	betterMotorSet(mogoL, power);
	betterMotorSet(mogoR, power);
}
