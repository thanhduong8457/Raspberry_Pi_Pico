/**********************************************************************************************
 * Arduino PID Library - Version 1
 * by Brett Beauregard <br3ttb@gmail.com> brettbeauregard.com
 *
 * This Code is licensed under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
 **********************************************************************************************/
#include "PID.h"

PID::PID()
{
	this->Kp = 3.0;
    this->Ki = 2.0;
    this->Kd = 1.0;
    this->mode = "normal";
}

PID::PID(float Kp, float Ki, float Kd)
{
	this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->mode = "normal";
}

PID::PID(float Kp, float Ki, float Kd, std::string mode)
{
	this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->mode = mode;
}

void PID::set_Kp(float Kp)
{
	this->Kp = Kp;
}

void PID::set_Ki(float Ki)
{
	this->Ki = Ki;	
}

void PID::set_Kd(float Kd)
{
	this->Kd = Kd;	
}

void PID::set_mode(std::string mode)
{
	this->mode = mode;
}

int PID::inc_(int a)
{
	return(a + 10);
}

void PID::show_info()
{
	std::cout<<"this is information of PID controler"<<std::endl;
	std::cout<<"Kp: "<<this->Kp<<std::endl;
	std::cout<<"Ki: "<<this->Ki<<std::endl;
	std::cout<<"Kd: "<<this->Kd<<std::endl;
	std::cout<<"mode: "<<this->mode<<std::endl;
}