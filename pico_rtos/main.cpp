#include <stdio.h>
#include <iomanip>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <iostream>

#include "FreeRTOS.h"
#include "task.h"

const uint led_pin = 25;
const float conversion = 3.3f / (1<<12);

void display_temperature(void * pvParams) {   
    uint16_t raw = 0x0;
    while (true) {
        raw = adc_read();
        float voltage = raw*conversion;
        float temperature = 27 - (voltage - 0.706)/0.001721;

        std::cout<<"temperature: "<<temperature<<std::endl;
        vTaskDelay(100);
    }
}

void gpio_display(void * pvParams) {   
    while (true) {
		gpio_put(led_pin, true);
    	vTaskDelay(500);
		gpio_put(led_pin, false);
		vTaskDelay(500);
    }
}

int main() {	
	// Initialize chosen serial port
	stdio_init_all();
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
	
	// Initialize adc
	adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    xTaskCreate(display_temperature, "display_temperature", 256, NULL, 1, NULL);
    xTaskCreate(gpio_display, "gpio_display", 256, NULL, 1, NULL);
    vTaskStartScheduler();
	
    while (true) {
        //
    }
}
