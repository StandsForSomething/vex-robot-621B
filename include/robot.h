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

void motorsInit();
void driveSet(int left, int right, bool immediate);
void armSetStage1(int power, bool immediate);
void armSetStage2(int power, bool immediate);
void armSetBothStages(int stage1, int stage2, bool immediate);
void mogoSet(int power, bool immediate);
#endif
