#pragma once
#include "Car.h"

class Fiat : public Car {
public:
	Fiat();
	~Fiat();

	virtual double timeToFinishRace(double circuitLength, Weather weather) override;
};