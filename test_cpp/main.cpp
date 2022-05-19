#include <iostream>
#include<string>
#include <map>

using namespace std;

enum{
    circle = 1,
    square,
    triangle
};

float round(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

int main()
{
  double theta_1 = 123.456;
  double theta_2 = 123.456;
  double theta_3 = 123.456;

  int gripper = 1;

  string data = "{\"theta1\":\"" + to_string((int)(theta_1*100)) +
                    "\",\"theta2\":\"" + to_string(theta_2) +
                    "\",\"theta3\":\"" + to_string(theta_3) + "\",\"gripper\":\"" + to_string(gripper) + "\"}\n";


  cout<<data<<endl;

  return 0;
}