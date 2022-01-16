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

    char buffer[1024];

    int last_position = 0;

    gpio_put(ENABLE, false);

    while (true)
    {
      scanf("%1024s", buffer);
      printf("%s\n", buffer);

      int current_position = std::stoi(buffer);

      if(current_position<0) 
      {
        current_position = 0;
        std::cout<<"value smaller than 0!"<<std::endl;
      }
      else if(current_position>360)
      {
        current_position = 360;
        std::cout<<"value larger than 360!"<<std::endl;
      }

      int step_to_move = current_position - last_position;

      if(step_to_move>0)
      {
        step(false, DIR, STEP, (step_to_move*6400/360));
      }
      else
      {
        step(true, DIR, STEP, -(step_to_move*6400/360));
      }

      std::cout<<"step_to_move = "<<step_to_move<<std::endl;

      last_position = current_position;
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