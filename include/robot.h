#ifndef ROBOT_H_
#define ROBOT_H_
#include "main.h"

const char claw;
const char mogoR;
const char mogoL;
const char RDrive;
const char LDrive;
const char arm1R;
const char arm1L;
const char arm2;


simpleSensor powerExpander;
simpleSensor autoSelect;
simpleSensor arm1Pot;
simpleSensor mogoPotL;
simpleSensor mogoPotR;
simpleSensor arm2Enc;
simpleSensor driveEncL;
simpleSensor driveEncR;

fbc_t arm1FBC;
fbc_t arm2FBC;
fbc_pid_t arm1PID;
fbc_pid_t arm2PID;

void encodersInit();
void motorsInit();
void driveSet(int left, int right);
void armSetStage1(int power);
void armSetStage2(int power);
void armSetBothStages(int stage1, int stage2);
void mogoSet(int power);
void initFBCControllers();
#endif
