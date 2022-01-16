#include <stdio.h>
#include <iomanip>
#include "pico/stdlib.h"
#include <iostream>
#include <string.h>

#define LED_PIN  25

int main() 
{	
	// Initialize chosen serial port
	stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    char buffer[1024];

    gpio_put(LED_PIN, false);

    while (true)
    {
        scanf("%1024s", buffer);
        printf("%s\n", buffer);

        if(strcmp(buffer, "on") == 0)
        {
            gpio_put(LED_PIN, true);
        }
        else if(strcmp(buffer, "off") == 0)
        {
            gpio_put(LED_PIN, false);
        }
    }
}
