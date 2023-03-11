#include "motor.h"


void DriveMotor(struct motor motor,int Steps, int Direction)
{
    gpio_put(motor.dir, Direction);
	for(int i = 0; i < Steps; i++)
	{
    	  gpio_put(motor.pin, 1);
		  sleep_ms(2);
    	  gpio_put(motor.pin, 1);
		  sleep_ms(2);
	}
}

void DriveTwoMotors(struct motor motor1,int Direction1, struct motor motor2, int Direction2, int Steps)
{
    gpio_put(motor1.dir, Direction1);
    gpio_put(motor2.dir, Direction2);
	for(int i = 0; i < Steps; i++)
	{
    	gpio_put(motor1.pin, 1);
    	gpio_put(motor2.pin, 1);
		sleep_ms(2);
    	gpio_put(motor1.pin, 0);
    	gpio_put(motor2.pin, 0);
		sleep_ms(2);
	}
}