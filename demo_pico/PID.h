#ifndef __PID_H__
#define __PID_H__
#include <iostream>
#include <string>
class PID
{
private:
    float Kp;
    float Ki;
    float Kd;
    std::string mode;
public:
    PID();
    PID(float, float, float);
    PID(float, float, float, std::string);
    void set_Kp(float);
    void set_Ki(float);
    void set_Kd(float);
	int inc_(int);
    void set_mode(std::string);
	void show_info();
};
#endif//__PID_H__