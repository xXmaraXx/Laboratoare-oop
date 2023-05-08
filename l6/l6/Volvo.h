#pragma once
#include "Car.h"

class Volvo : public Car {
public:
	Volvo();
	~Volvo();

	virtual double timeToFinishRace(double circuitLength, Weather weather) override;
};