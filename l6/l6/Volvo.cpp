#include "Volvo.h"

Volvo::Volvo() :Car("Volvo", 60, 7, 80, 100, 60) {

}

Volvo::~Volvo() {

}

double Volvo::timeToFinishRace(double circuitLength, Weather weather) {
	double avgSpeed = 0;

	switch (weather) {
	case Weather::Rain:
		avgSpeed = avgSpeedRain;
		break;
	case Weather::Sunny:
		avgSpeed = avgSpeedSunny;
		break;
	case Weather::Snow:
		avgSpeed = avgSpeedSnow;
		break;
	}

	double time = circuitLength / avgSpeed;
	double fuelNeeded = fuelConsumption * circuitLength / 100;
	if (fuelNeeded > fuelCapacity) {
		return -1;
	}
	return time;
}
