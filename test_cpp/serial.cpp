#include <iostream>
#include <SerialStream.h>

using namespace LibSerial;
using namespace std;

int main(int argc, char** argv) 
{
    SerialStream serial;
    //serial.Open("/dev/ttyUSB0");
    serial.Open("COM0");
    serial.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
    serial.SetBaudRate(SerialStreamBuf::DEFAULT_BAUD);
    serial.SetNumOfStopBits(1);
    serial.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);

    if(serial.good())
    {
        cout << "SUCCESSFUL: serial port opened at: /dev/ttyUSB0" << endl;
        usleep(5000);
    }
    else
    {
        cout << "ERROR: Could not open serial port, check and try again." << endl;
        return 0;
    }

    std::string str= "ver\r"; //command to get version of firmware
    const char* data = str.data();
    serial.write(data, sizeof data);
    return 0;
}