#include "HTS221-driver/HTS221.h"
#include "LPS25H-driver/LPS25H.h"
#include <iostream>

int main(int argc, char** argv)
{
    double humH, temH, preL, temL;

    HTS221 humTem("/dev/i2c-2");
    LPS25H preTem("/dev/i2c-2");
    humTem.powerUp();
    humTem.calibrate();
    preTem.powerUp();
   
    humH = humTem.getHumidity();
    temH = humTem.getTemperature();
    preL = preTem.getPressure();
    temL = preTem.getTemperature();
    
    std::cout<< humH << " " << temH <<" " << preL << " " << temL<<std::endl;	
    return 0;
}
