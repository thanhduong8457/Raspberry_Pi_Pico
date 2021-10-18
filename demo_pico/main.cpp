#include <stdio.h>
#include "pico/stdlib.h"
#include "PID.h"

int main() 
{	
	// Initialize chosen serial port
	stdio_init_all();
	
    const uint led_pin = 25;
	int a = 1000;
	int b = 0;
    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
	
	//setup PID controller
	PID pid(7.8, 5.2, 2.3, "auto");
	pid.set_Kp(8.0);
	pid.set_Ki(10.0);
	pid.set_mode("normal");
	
	PID *pid_2;
	
	pid_2 = new PID(1.2,2.3,3.4);
	
	pid_2->show_info();
	
    while (true)
    {
		b++;
        std::cout<<"Hello "<<b<<" times !!!"<<std::endl;
		
		pid.set_Ki(b);
		
		pid.show_info();

        gpio_put(led_pin, true);
        sleep_ms(a);
        gpio_put(led_pin, false);
        sleep_ms(a);
    }
}