#include <stdio.h>
#include <iomanip>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <iostream>

const uint led_pin = 25;
const float conversion = 3.3f / (1<<12);

void display_temperature(void);

int main() 
{	
	// Initialize chosen serial port
	stdio_init_all();
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
	
	// Initialize adc
	adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
	
    while (true)
    {
		display_temperature();

		gpio_put(led_pin, true);
    	sleep_ms(100);
		gpio_put(led_pin, false);
		sleep_ms(100);
    }
}

void display_temperature(void)
{
    uint16_t raw = adc_read();
    float voltage = raw*conversion;
    float temperature = 27 - (voltage - 0.706)/0.001721;

    std::cout<<"temperature: "<<temperature<<std::endl;
}
