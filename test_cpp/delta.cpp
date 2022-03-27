#include <iostream>
#include <map>
#include "main.h"

double x0, y0, z0, x, y, z;

void path_linear_speed(double xo,double yo,double zo,double xf,double yf,double zf);
void ls_v_a_total(double results, double results_1, double call_vmax_2,double call_amax_2,double call_pas1_2,double call_pas2_2);

void system_linear(double xo,double yo,double zo,double xf,double yf,double zf);

int main()
{
    // End and start point rotation
    //path_linear_speed(x0, y0, z0, x, y, z);

    // Trapezoidal velocity profile

    double p1 = sqrt((x-x0)*(x-x0) + (y-y0)*(y-y0) + (z-z0)*(z-z0));
    int call_vmax_2 = 2000;
    int call_amax_2 = 40000;

    ls_v_a_total(0, p1, call_vmax_2, call_amax_2, 50, 150);

    // Reverse rotation end point, start point and trajectory #######
    path_linear_speed_inv(results_2[1], results_2[2],results_2[3], results_2[4],results_2[5])

    // Save in Matrix Path Cartesian space XYZ
    res_1 = [results_4[0],results_4[1], results_4[4], results_4[7],results_4[2], results_4[5], results_4[8],results_4[3], results_4[6], results_4[9]]

    // Inverse kinematics
    res_2 = inverse_m(res_1[1], res_1[4], res_1[7]);

    return 0;
}
