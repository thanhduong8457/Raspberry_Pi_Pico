#include <stdio.h>
#include <iomanip>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "PID.h"
/*##################################################################################*/
const uint led_pin = 25;
int count = 0;
float ref = 1000;
float y = 0;
float temp;
const float conversion = 3.3f / (1 << 12);
/*##################################################################################*/
void blink(int &temp, int delay)
{
    int value = temp % 100;
    if(value < 50) {
        gpio_put(led_pin, true);
        sleep_ms(delay);
    }
    else {
        gpio_put(led_pin, false);
        sleep_ms(delay);
    }
}
/*##################################################################################*/
float set_ref(float duration, int &temp)
{
    int ref = 0;
    if(temp < (duration/2)) {
        ref = 100;
    }
    else if(temp < duration) {
        ref = 0;
    }
    else {
        temp = 0;
    }
    
    return ref;
}
/*##################################################################################*/
void display_temperature(void) {
    uint16_t raw = adc_read();
    float voltage = raw*conversion;
    float temperature = 27 - (voltage - 0.706)/0.001721;
    std::cout<<"temperature: "<<temperature<<std::endl;
}
/*##################################################################################*/
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
    
    //setup PID controller
    PID *pid;
    pid = new PID(8, 3, 5, 0.02, "auto");

    sleep_ms(3000);
    pid->show_info();
    sleep_ms(2000);

    while (true) {
        count++;
        
        ref = set_ref(7000, count);

        temp = pid->compute(ref, y);
        y = y + temp/1000;

        std::cout<<"ref: "<<ref<<"  y: "<<y<<"  ";
        display_temperature();
        
        blink(count, 20);
    }
}