#ifndef AUTO_STACKING_H_
#define AUTO_STACKING_H_
#include "main.h"

char autoStackCone;
TaskHandle autoStackTaskHandle;
TaskHandle armReturnTaskHandle;

void autoStack();
void returnArm();
void cancelStack();
#endif
