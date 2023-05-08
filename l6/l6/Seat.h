#pragma once
#include "Car.h"

class Seat : public Car {
public:
	Seat();
	~Seat();

	virtual double timeToFinishRace(double circuitLength, Weather weather) override;
};