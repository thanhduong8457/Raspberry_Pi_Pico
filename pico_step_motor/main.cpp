#include <stdio.h>
#include <iomanip>
#include "pico/stdlib.h"
#include <iostream>
#include <string.h>

#define ENABLE  19
#define DIR     20
#define STEP    21
#define LED_PIN 25

int delayTime = 30;
int steps = 6400;

void step(bool dir, int dirPin, int stepperPin, int steps);
void main_init(void);

int main() 
{	
    main_init();

    gpio_put(ENABLE, false);

    while (true)
    {
        step(false, DIR, STEP, steps);
        gpio_put(LED_PIN, false);
        sleep_ms(1000);
        step(true, DIR, STEP, steps);
        gpio_put(LED_PIN, true);
        sleep_ms(1000);
    }
}

void main_init(void)
{
    // Initialize chosen serial port
	stdio_init_all();
    gpio_init(ENABLE);
    gpio_set_dir(ENABLE, GPIO_OUT);
    gpio_init(DIR);
    gpio_set_dir(DIR, GPIO_OUT);
    gpio_init(STEP);
    gpio_set_dir(STEP, GPIO_OUT);
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void step(bool dir, int dirPin, int stepperPin, int steps)
{
  gpio_put(dirPin, dir);
  sleep_ms(100);
  for (int i = 0; i< steps; i++)
  {
    gpio_put(stepperPin, true);
    sleep_us(delayTime);
    gpio_put(stepperPin, false);
    sleep_us(delayTime);
  }
}