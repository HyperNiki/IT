#ifndef MOTOR
#define MOTOR

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "motor.h"

#define stepsperrev 4096

struct motor {
    uint   pin1;        /* state machine number */
    uint   pin2;        /* state machine number */
    uint   pin3;        /* state machine number */
    uint   pin4;        /* state machine number */
};

void stepper_step_angle (float angle, int direction, int rpm, struct motor *motor);
void stepper_set_rpm (int rpm);  // Set rpm--> max 13, min 1,,,  went to 14 rev/min
void stepper_half_drive (int step, struct motor *motor);

#endif /* MOTOR */
