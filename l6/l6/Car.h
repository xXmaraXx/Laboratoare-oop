#pragma once
#pragma warning(disable : 4996)
#include "Weather.h"
#include <string.h>

class Car {
public:
    Car(const char Name[21], double fuelCapacity, double fuelConsumption, double avgSpeedRain, double avgSpeedSunny, double avgSpeedSnow) : 
        fuelCapacity(fuelCapacity), fuelConsumption(fuelConsumption), 
        avgSpeedRain(avgSpeedRain), avgSpeedSunny(avgSpeedSunny), avgSpeedSnow(avgSpeedSnow) {
        strncpy(this->Name, Name, 21);
    }
    virtual ~Car(){}

    virtual double timeToFinishRace(double circuitLength, Weather weather) = 0;

    virtual const char* getName() const
    {
        return Name;
    }

protected:
    char Name[21];
    double fuelCapacity;
    double fuelConsumption;
    double avgSpeedRain;
    double avgSpeedSunny;
    double avgSpeedSnow;
}; 
