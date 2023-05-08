#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
	RangeRover();
	~RangeRover();

	virtual double timeToFinishRace(double circuitLength, Weather weather) override;
};