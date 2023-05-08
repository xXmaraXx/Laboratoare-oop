#include "Seat.h"

Seat::Seat() :Car("Seat", 4, 6, 70, 90, 50) {

}

Seat::~Seat() {

}

double Seat::timeToFinishRace(double circuitLength, Weather weather) {
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
