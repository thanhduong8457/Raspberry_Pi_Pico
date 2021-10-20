#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <iostream>
#include <iomanip>

/*##################################################################################*/
const float conversion = 3.3f / (1<<12);
int temp = 0;
const uint led_pin = 25;
float buffer[10];
int a = 10;
/*##################################################################################*/
void blink_led(int &temp, int a)
{
        if(temp<100)
    {
        gpio_put(led_pin, true);
        sleep_ms(a);
    }
    else if(temp < 200)
    {
        gpio_put(led_pin, false);
        sleep_ms(a);
    }
    else
    {
        temp = 0;
    }
}
/*##################################################################################*/
void display_temperature(void)
{
    uint16_t raw = adc_read();
    float voltage = raw*conversion;
    float temperature = 27 - (voltage - 0.706)/0.001721;

    buffer[0] = temperature;
		
    for(int i=9 ; i > 0; i-- )
    {
        buffer[i] = buffer[i-1];
    }

    float temp_2 = 0;
    for(int i = 0; i<10; i++)
    {
        temp_2 += buffer[i];
        std::cout<<buffer[i]<<"  ";
    }

    std::cout<<"temperature: "<<std::setprecision(2)<<std::fixed<<temp_2/10<<std::endl;
}
/*##################################################################################*/
int main(void)
{
    stdio_init_all();
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
	
    while(true)
    {
        temp++;
        display_temperature();
        blink_led(temp, a);
    }
}