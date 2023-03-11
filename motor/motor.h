#ifndef MOTOR
#define MOTOR

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "motor.h"

#define stepsperrev 4096

struct motor {
    uint   dir;        /* state machine number */
    uint   pin;        /* state machine number */
};

void DriveMotor(struct motor motor,int Steps, int Direction);
void DriveTwoMotors(struct motor motor1,int Direction1, struct motor motor2, int Direction2, int Steps);

#endif /* MOTOR */
