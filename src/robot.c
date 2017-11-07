#include "main.h"

const char claw = 2;
const char mogoR = 3;
const char mogoL = 4;
const char RDrive = 5;
const char LDrive = 6;
const char arm1R = 7;
const char arm1L = 8;
const char arm2 = 9;

simpleSensor powerExpander = {1, ANALOG, false};
simpleSensor autoSelect = {2, ANALOG, false};
simpleSensor arm1Pot = {3, ANALOG, false};
simpleSensor mogoPotL = {5, ANALOG, false};
simpleSensor mogoPotR = {4, ANALOG, false};
simpleSensor arm2Enc = {11, OTHER, false};
simpleSensor driveEncL = {8, OTHER, false};
simpleSensor driveEncR = {6, OTHER, false};

fbc_t arm1FBC;
fbc_t arm2FBC;
fbc_pid_t arm1PID;
fbc_pid_t arm2PID;

void encodersInit() {
	initEncoder(&arm2Enc, 12, SPEED, TWO_WIRE, TICKS, 5);
	initEncoder(&driveEncL, 9, SPEED, TWO_WIRE, TICKS, 1);
	initEncoder(&driveEncR, 42, SPEED, TWO_WIRE, TICKS, 1);
}

void motorsInit() {
	blrsMotorInit(claw, true, DEFAULT_SLEW_RATE, NULL);
<<<<<<< HEAD
	blrsMotorInit(mogoR, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(mogoL, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(LDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm1R, false, 0.35, NULL);
	blrsMotorInit(arm1L, true, 0.35, NULL);
=======
	blrsMotorInit(mogo, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RDrive2, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RDrive1, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(LDrive1, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(LDrive2, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm1, true, 0.35, NULL);
>>>>>>> 4a64943... try to do things to prevent gear skippings
	blrsMotorInit(arm2, true, 2, NULL);
}

void driveSet(int left, int right) {
	blrsMotorSet(LDrive, left, false);
	blrsMotorSet(RDrive, right, false);
}

void armSetStage1(int power) {
<<<<<<< HEAD
	blrsMotorSet(arm1L, power, false);
	blrsMotorSet(arm1R, power, false);
=======
		blrsMotorSet(arm1, power, true);
>>>>>>> 4a64943... try to do things to prevent gear skippings
}

void armSetStage2(int power) {
	blrsMotorSet(arm2, power, false);
}

void armSetBothStages(int stage1, int stage2) {
	armSetStage1(stage1);
	armSetStage2(stage2);
}

void mogoSet(int power) {
	blrsMotorSet(mogoL, power, false);
	blrsMotorSet(mogoR, power, false);
}

void clawMove() {
	static bool open = true;
	if(!open) {
		blrsMotorSet(claw, -80, true);
		open = true;
	}

	else {
		blrsMotorSet(claw, 50, true);
		open = false;
	}
}

int _arm1Sense() {
	static bool armMoveDown = false;
	static lastGoal = 0;
	static long lastMillis;
	int timePassed;
	timePassed = millis() - lastMillis;

	if(arm1FBC.goal > ARM_1_LOWER_P) {
		arm1PID.kP = 0.13;
	}

	else {
		arm1PID.kP = 0.2;
	}
	return (int)getSensor(arm1Pot);
}

int _arm2Sense() {
	return (int)getSensor(arm2Enc);
}
void initFBCControllers() {
	fbcInit(&arm1FBC, &armSetStage1, &_arm1Sense, NULL, NULL, -1, 1, 250, 15);
	fbcInit(&arm2FBC, &armSetStage2, &_arm2Sense, NULL, NULL, -1, 1, 5, 10);
	fbcPIDInitializeData(&arm1PID, 0.2, 0, 10, 0, 0);
	fbcPIDInitializeData(&arm2PID, 0.7, 0, 0, 0, 0);
	fbcPIDInit(&arm1FBC, &arm1PID);
	fbcPIDInit(&arm2FBC, &arm2PID);
}
