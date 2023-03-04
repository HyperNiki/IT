#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>
#include "motor.h"

int main()
{
    const uint LED_PIN = 25;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT); 

    stdio_init_all();
    char str[80];
    char UserInput;
    //sleep_ms(5000);
    int n = 0;
    struct motor MotorA;

    MotorA.pin1 = 20;
    MotorA.pin1 = 21;
    MotorA.pin1 = 22;
    MotorA.pin1 = 23;

    while(1)
    {
        while ((UserInput != '\n') && (n < 80))
        {
            while( !stdio_usb_connected() ){
                printf("waiting for usb connection\n");
                sleep_ms(100);
            }
            UserInput = getchar_timeout_us(10000);
            str[n] = UserInput;
            printf("n = %d \r\n", n);
            printf("%c\r\n", UserInput);
            n++;
        }
        printf("%s", str);
        UserInput = '\0';
        n = 0;
        if (!strncmp (str, "LED 1",5))
        {
            gpio_put(25, 1);
            printf("Led ON \r\n");
        } else if (!strncmp (str, "LED 0",5))
        {
            gpio_put(25, 0);
            printf("Led OFF \r\n");
        } else 
        printf("Invalid Input \r\n");
    
    }


    return 0;
}
