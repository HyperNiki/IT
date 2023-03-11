#include <stdio.h>
#include <string.h>
#include "motor.h"
#include <stdlib.h>

unsigned char mygetchar();
void Clear_r_n(char str[], int Len);
void Clear_Space(char str[]);
char CorrectSymbol(char elem);

int main()
{
    const uint LED_PIN = 25;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT); 

    stdio_init_all();
    char str[80];
    char UserInput;
    char * pEnd;
    char * pEndx2;   
    int n = 0;
    struct motor MotorA;
    struct motor MotorB;

    MotorA.dir = 20;
    MotorA.pin = 21;

    MotorB.dir = 22;
    MotorB.pin = 23;

    while(1)
    {
        while ((UserInput != '\n') && (n < 78))
        {
            UserInput = mygetchar();
            str[n] = UserInput;
            n++;
        }
        Clear_r_n(str, strlen(str));
        Clear_Space(str);
        UserInput = '\0';
        n = 0;
        
        for (int IndexForCorrect = 0; IndexForCorrect < (strchr((char*)&str,' ') - str); IndexForCorrect++)
		{
		    str[IndexForCorrect] = CorrectSymbol(str[IndexForCorrect]);
		}
        
        if (!strncmp (str, "led 1",5))
        {
            gpio_put(25, 1);
            printf("Led ON \r\n");
        } else if (!strncmp (str, "led 0",5))
        {
            gpio_put(25, 0);
            printf("Led OFF \r\n");
        } else if (!strncmp (str, "motor ",6 ))
        {
		  	if ((strtol(str + 6, &pEnd ,10) != '\0' || (!strncmp(str+6,"0,",2))) &&
		  	(strtol(strchr(pEnd,',')+1,&pEndx2,10) != '\0' || (!strcmp(strchr(pEnd,',')+1,"0"))))
		  	{
		  	    uint16_t motor = strtol(str+6, &pEnd,10);
			    uint16_t value = strtol(strchr(pEnd,',')+1,&pEndx2,10);
                if (motor)
                DriveMotor(MotorA, value, 1);
                else 
                DriveMotor(MotorB, value, 1);
		  	  	printf("Motor %d drive %d\r\n", motor, value);
		  	} else {
		  	  printf("No correct value\r\n");
		  	}
        } else
        printf("Invalid Input \r\n");
    
    }


    return 0;
}

// Function for get char without error
unsigned char mygetchar() {
	int c;
	while ( (c = getchar_timeout_us(0)) < 0); 
	return (unsigned char)c;
};

void Clear_r_n(char str[], int Len)
{
	int Index;
	int Flag = 0;
	for (Index = 0; Index < Len; Index++)
	{
		if (Flag == 0)
		{
			if ((str[Index] == '\n') || (str[Index] == '\r'))
			{
				str[Index] = '\0';
				Flag = 1;
			}
		} else {
			str[Index] = '\0';
		}
	}
}

void Clear_Space(char str[])
{
	while (str[strlen(str) - 1] == ' ')
	{
		str[strlen(str) - 1] = '\0';
	}
}

char CorrectSymbol(char elem)
{
	switch(elem)
	{
	case 'A':
		return 'a';
		break;
	case 'B':
		return 'b';
		break;
	case 'C':
		return 'c';
		break;
	case 'D':
		return 'd';
		break;
	case 'E':
		return 'e';
		break;
	case 'F':
		return 'f';
		break;
	case 'G':
		return 'g';
		break;
	case 'H':
		return 'h';
		break;
	case 'I':
		return 'i';
		break;
	case 'J':
		return 'j';
		break;
	case 'K':
		return 'k';
		break;
	case 'L':
		return 'l';
		break;
	case 'M':
		return 'm';
		break;
	case 'N':
		return 'n';
		break;
	case 'O':
		return 'o';
		break;
	case 'P':
		return 'p';
		break;
	case 'Q':
		return 'q';
		break;
	case 'R':
		return 'r';
		break;
	case 'S':
		return 's';
		break;
	case 'T':
		return 't';
		break;
	case 'U':
		return 'u';
		break;
	case 'V':
		return 'v';
		break;
	case 'W':
		return 'w';
		break;
	case 'X':
		return 'x';
		break;
	case 'Y':
		return 'y';
		break;
	case 'Z':
		return 'z';
		break;
	}

	return elem;
}