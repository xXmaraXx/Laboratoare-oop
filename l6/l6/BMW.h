#pragma once
#include "Car.h"

class BMW : public Car{
public:
	BMW();
	~BMW();

	virtual double timeToFinishRace(double circuitLength, Weather weather) override;
};