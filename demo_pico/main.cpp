#include <stdio.h>
#include "pico/stdlib.h"
#include "PID.h"

int main() 
{	
	// Initialize chosen serial port
	stdio_init_all();
	
    const uint led_pin = 25;
	int a = 1000;

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
	
	//setup PID controller
	PID pid(7.8, 5.2, 2.3, "auto");
	pid.set_Kp(8.0);
	pid.set_Ki(10.0);
	pid.set_mode("normal");
	
    while (true)
    {
        std::cout<<"Hello everyone my name is Le Thanh Duong!!!"<<std::endl;
		
		pid.show_info();

        gpio_put(led_pin, true);
        sleep_ms(a);
        gpio_put(led_pin, false);
        sleep_ms(a);
    }
}