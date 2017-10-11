#include "main.h"

const char claw = 1;
const char mogoR = 3;
const char mogoL = 4;
const char RDrive = 5;
const char LDrive = 6;
const char arm1R = 7;
const char arm1L = 8;
const char arm2 = 9;

void motorsInit() {
	blrsMotorInit(claw, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(mogoR, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(mogoL, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(LDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm1R, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm1L, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm2, true, DEFAULT_SLEW_RATE, NULL);
}

void driveSet(int left, int right, bool immediate) {
	blrsMotorSet(LDrive, left, immediate);
	blrsMotorSet(LDrive, right, immediate);
}

void armSetStage1(int power, bool immediate) {
	blrsMotorSet(arm1L, power, immediate);
	blrsMotorSet(arm1R, power, immediate);
}

void armSetStage2(int power, bool immediate) {
	blrsMotorSet(arm2, power, immediate);
}

void armSetBothStages(int stage1, int stage2, bool immediate) {
	armSetStage1(stage1, immediate);
	armSetStage2(stage2, immediate);
}

void mogoSet(int power, bool immediate) {
	blrsMotorSet(mogoL, power, immediate);
	blrsMotorSet(mogoR, power, immediate);
}
