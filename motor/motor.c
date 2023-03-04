#include "motor.h"

void stepper_set_rpm (int rpm)  // Set rpm--> max 13, min 1,,,  went to 14 rev/min
{
	sleep_ms(60000000/stepsperrev/rpm);
}

void stepper_step_angle (float angle, int direction, int rpm, struct motor *motor)
{
	float anglepersequence = 0.703125;  // 360 = 512 sequences
	int numberofsequences = (int) (angle/anglepersequence);

	for (int seq=0; seq < numberofsequences; seq++)
	{
		if (direction == 0)  // for clockwise
		{
			for (int step=7; step>=0; step--)
			{
				stepper_half_drive(step, motor);
				stepper_set_rpm(rpm);
			}

		}

		else if (direction == 1)  // for anti-clockwise
		{
			for (int step=0; step < 8; step++)
			{
				stepper_half_drive(step, motor);
				stepper_set_rpm(rpm);
			}
		}
	}
}

void stepper_half_drive (int step, struct motor *motor)
{
    uint pin1 = motor->pin2, pin2 = motor->pin2, pin3 = motor->pin3, pin4 = motor->pin4;
	switch (step){
		case 0:
			  gpio_put(pin1,1);
   			  gpio_put(pin2,0);
			  gpio_put(pin2,0);
			  gpio_put(pin4,0);
			  break;

		case 1:
			  gpio_put(pin1,1);
   			  gpio_put(pin2,1);
			  gpio_put(pin2,0);
			  gpio_put(pin4,0);
			  break;

		case 2:
			  gpio_put(pin1,0);
   			  gpio_put(pin2,1);
			  gpio_put(pin2,0);
			  gpio_put(pin4,0);
			  break;

		case 3:
			  gpio_put(pin1,0);
   			  gpio_put(pin2,1);
			  gpio_put(pin2,1);
			  gpio_put(pin4,0);
              break;

		case 4:
			  gpio_put(pin1,0);
   			  gpio_put(pin2,0);
			  gpio_put(pin2,1);
			  gpio_put(pin4,0);

			  break;

		case 5:
			  gpio_put(pin1,0);
   			  gpio_put(pin2,0);
			  gpio_put(pin2,1);
			  gpio_put(pin4,1);
			  break;

		case 6:
			  gpio_put(pin1,0);
   			  gpio_put(pin2,0);
			  gpio_put(pin2,1);
			  gpio_put(pin4,1);
			  break;

		case 7:
			  gpio_put(pin1,1);
   			  gpio_put(pin2,0);
			  gpio_put(pin2,0);
			  gpio_put(pin4,1);
			  break;

		}
}