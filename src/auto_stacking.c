#include "main.h"
#define ARM_2_START 50

TaskHandle autoStackTaskHandle = NULL;
char autoStackCone = 1;
int armPositions[13][2] = {
//arm1 | arm2
	{275,  -44},  //cone 1
	{275,  -84},  //cone 2
	{750,   20},  //cone 3
	{660,   20},  //cone 4
	{925,   20},  //cone 5
	{1100,  20},  //cone 6
	{1130,  20},  //cone 7
	{1410, -52},  //cone 8
	{1475, -85},  //come 9
	{1600, -86},  //cone 10
	{1815, -70},  //cone 11
	{2363, -430}, //cone 12 (step one)
	{2055, -430}, //cone 12 (step two)
};

void _autoStackTask(void *ignore) {
	fbcSetGoal(&arm1FBC, armPositions[autoStackCone-1][0]);
	while((int)getSensor(arm1Pot) < arm1FBC.goal - ARM_2_START) {
		print("[autoStack] waiting\n\r");
		delay(20);
	}
	print("[autoStack] setting arm2\n\r");
	fbcSetGoal(&arm2FBC, armPositions[autoStackCone-1][1]);

	if(autoStackCone == 12) {
		fbcSetGoal(&arm1FBC, armPositions[12][0]);
		while((int)getSensor(arm1Pot) < arm1FBC.goal - ARM_2_START) {
			delay(20);
		}
		fbcSetGoal(&arm2FBC, armPositions[12][1]);
	}
	autoStackCone++;
}

void autoStack() {
	if(autoStackTaskHandle == NULL ||
		 taskGetState(autoStackTaskHandle) != TASK_RUNNING) {
		autoStackTaskHandle = taskCreate(&_autoStackTask, TASK_DEFAULT_STACK_SIZE,
																		 NULL,
																		 TASK_PRIORITY_DEFAULT);
		printf("[autoStack] starting task for cone %d\n\r", autoStackCone);
	}

	else {
		print("[autoStack] couldn't start task\n\r");
	}
}

void cancelStack() {
	print("[autoStack] stopping task\n\r");
	taskDelete(autoStackTaskHandle);
	fbcSetGoal(&arm1FBC, (int)getSensor(arm1Pot));
	fbcSetGoal(&arm2FBC, (int)getSensor(arm2Enc));
}
