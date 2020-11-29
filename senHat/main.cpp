#include "HTS221-driver/HTS221.h"
#include "LPS25H-driver/LPS25H.h"
#include <iostream>
#include <vector>
#include <queue>


int main(int argc, char** argv)
{
    double humH, temH, preL, temL;
    std::tuple<int, int, int, int> data;
    HTS221 humTem("/dev/i2c-2");
    LPS25H preTem("/dev/i2c-2");
    humTem.powerUp();
    humTem.calibrate();
    preTem.powerUp();
   
    humH = humTem.getHumidity();
    temH = humTem.getTemperature();
    preL = preTem.getPressure();
    temL = preTem.getTemperature();
    data= std::make_tuple(humTem.getHumidity(),
                            humTem.getTemperature(),
                            preTem.getPressure(),
                            preTem.getTemperature());
    return 0;
}
