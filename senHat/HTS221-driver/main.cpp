#include "HTS221.h"
#include <iostream>

int main(int argc, char** argv)
{
    double humidity, temperature;

    HTS221 sensor("/dev/i2c-2");
    sensor.powerUp();
    sensor.calibrate();

    humidity = sensor.getHumidity();
    std::cout << "Humidity: " << humidity << " % RH" << std::endl;

    temperature = sensor.getTemperature();
    std::cout << "Temperature: " << temperature << " °C" << std::endl;

    return 0;
	}
