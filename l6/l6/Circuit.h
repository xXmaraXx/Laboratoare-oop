#pragma once
#include <vector>
#include "Car.h"

class Circuit {
public:
    Circuit();
    virtual ~Circuit();

    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
    std::vector<std::pair<double, Car*>> finishTimes;

private:
    double length;
    Weather weather;
    std::vector<Car*> cars;
};