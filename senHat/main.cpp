#include "HTS221-driver/HTS221.h"
#include "LPS25H-driver/LPS25H.h"
#include <iostream>
#include<unistd.h>
#include "boost/asio.hpp"
using namespace boost::asio;


int main(int argc, char** argv)
{
    double humH, temH, preL, temL;
    int32_t data[4];
    HTS221 humTem("/dev/i2c-2");
    LPS25H preTem("/dev/i2c-2");
    humTem.powerUp();
    humTem.calibrate();
    preTem.powerUp();
   
    //data[0] = (int32_t)(1000*humTem.getHumidity());
    data[1] = (int32_t)(1000*humTem.getTemperature());
    data[2] = (int32_t)(1000*preTem.getPressure());
    data[3] = (int32_t)(1000*preTem.getTemperature());
	   
io_service io_service;
ip::udp::socket socket(io_service);
ip::udp::endpoint remote_endpoint;

socket.open(ip::udp::v4());

remote_endpoint = ip::udp::endpoint(ip::address::from_string("158.196.195.94"), 9000);

boost::system::error_code err;
	socket.send_to(buffer("Jane Doe", 8), remote_endpoint, 0, err);

while(1){
    //data[0] = (int32_t)(1000*humTem.getHumidity());
    data[1] = (int32_t)(1000*humTem.getTemperature());
    data[2] = (int32_t)(1000*preTem.getPressure());
    data[3] = (int32_t)(1000*preTem.getTemperature());
    socket.send_to(buffer("Jane Doe", 8), remote_endpoint, 0, err);
	unsigned int microsecond = 1000000;
	usleep(3 * microsecond);//sleeps for 3 second
}
	
	
	socket.close();



	}
