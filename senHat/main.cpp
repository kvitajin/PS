#include "HTS221-driver/HTS221.h"
#include "LPS25H-driver/LPS25H.h"
#include <iostream>
#include<unistd.h>
#include "boost/asio.hpp"
#include <ctime>



using namespace boost::asio;


int main(int argc, char** argv)
{
    int32_t data[9];
    int32_t time;
    std::string ip;
    
    HTS221 humTem("/dev/i2c-2");
    LPS25H preTem("/dev/i2c-2");
    humTem.powerUp();
    humTem.calibrate();
    preTem.powerUp();
   for( int i =0; i < argc-1; ++i){
	ip+=argv[i];
   }
	   std::cout<<ip<<std::endl;
    boost::system::error_code err;
   // boost::asio::ip::address::from_string( ip, err );  
    //if ( err )
//	std::cerr << err.message( ) << std::endl;
io_service io_service;
ip::udp::socket socket(io_service);
ip::udp::endpoint remote_endpoint;

socket.open(ip::udp::v4());

remote_endpoint = ip::udp::endpoint(ip::address::from_string(ip), 9000);


while(1){

    try{	
        data[0] = (int32_t)std::time(0);
        data[1] = 221;
        data[2] = (int32_t)(1000*humTem.getTemperature());
        data[3] = 221;
        data[4] = (int32_t)(1000*humTem.getHumidity());
        data[5] = 25;
        data[6] = (int32_t)(1000*preTem.getTemperature());
        data[7] = 25;
        data[8] = (int32_t)(1000*preTem.getPressure());

        socket.send_to(buffer(data, sizeof(int32_t)*9), remote_endpoint, 0, err);
    }

    catch(const std::runtime_error& re){
    	std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch(...){
        std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
    }
	   
   sleep(5);
   

}
	
	
	socket.close();


	}
