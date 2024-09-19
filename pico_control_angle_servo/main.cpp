#include "pico/stdlib.h"
#include "hardware/pwm.h"

// #define PWM_PIN 16 // GPIO 16 (GP16) for PWM output

// void pwm_init() {
//     gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    
//     // Set PWM frequency to 50Hz (20ms period)
//     pwm_set_wrap(pwm_gpio_to_slice_num(PWM_PIN), 20000);

//     // Set PWM duty cycle range (0-65535)
//     pwm_set_chan_level(pwm_gpio_to_slice_num(PWM_PIN), pwm_gpio_to_channel(PWM_PIN), 0);
//     pwm_set_enabled(pwm_gpio_to_slice_num(PWM_PIN), true);
// }

// // Set servo angle (0 to 180 degrees)
// void set_servo_angle(float angle) {
//     // Calculate pulse width (500 to 2500 microseconds) from angle
//     uint16_t pulse_width = 500 + (angle * (2000.0/180.0));

//     // Convert pulse width to PWM duty cycle (0-65535)
//     uint16_t duty_cycle = pulse_width * 65535 / 20000;

//     // Update PWM duty cycle
//     pwm_set_chan_level(pwm_gpio_to_slice_num(PWM_PIN), pwm_gpio_to_channel(PWM_PIN), duty_cycle);
// }

// int main() {
//     stdio_init_all();
//     pwm_init();

//     while (1) {
//         // Move servo to 0 degree position
//         set_servo_angle(0);
//         sleep_ms(1000); // Wait for 1 second

//         // Move servo to 90 degree position
//         set_servo_angle(90);
//         sleep_ms(1000); // Wait for 1 second

//         // Move servo to 180 degree position
//         set_servo_angle(180);
//         sleep_ms(1000); // Wait for 1 second
//     }

//     return 0;
// }

int main() {
    /// \tag::setup_pwm[]

    // Tell GPIO 0 and 1 they are allocated to the PWM
    gpio_set_function(0, GPIO_FUNC_PWM);
    gpio_set_function(1, GPIO_FUNC_PWM);

    // Find out which PWM slice is connected to GPIO 0 (it's slice 0)
    uint slice_num = pwm_gpio_to_slice_num(0);

    // Set period of 4 cycles (0 to 3 inclusive)
    pwm_set_wrap(slice_num, 3);
    // Set channel A output high for one cycle before dropping
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 1);
    // Set initial B output high for three cycles before dropping
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 3);
    // Set the PWM running
    pwm_set_enabled(slice_num, true);
    /// \end::setup_pwm[]

    // Note we could also use pwm_set_gpio_level(gpio, x) which looks up the
    // correct slice and channel for a given GPIO.
}

