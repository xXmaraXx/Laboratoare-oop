#include "BMW.h"

BMW::BMW() :Car("BMW", 70, 8, 90, 110, 70) {

}

BMW::~BMW() {

}

double BMW::timeToFinishRace(double circuitLength, Weather weather) {
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
