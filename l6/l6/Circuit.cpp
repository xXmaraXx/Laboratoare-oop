#include "Circuit.h"
#include <algorithm>
#include <iostream>
#include <vector>

Circuit::Circuit() :length(0), weather(Weather::Rain) {

}

Circuit::~Circuit() {
	for (auto car : cars) {
		delete car;
	}
}


void Circuit::SetLength(double length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	cars.push_back(car);
}

void Circuit::Race()
{
	for (auto car : cars) {
		double time = car->timeToFinishRace(length, weather);
		finishTimes.push_back(std::make_pair(time, car));
	}
	std::sort(finishTimes.begin(), finishTimes.end());
}

void Circuit::ShowFinalRanks()
{
	std::cout << "Final Ranks: "<<"\n";
	for (int i = 0; i < finishTimes.size(); i++) {
		if(finishTimes[i].first!=-1)
			std::cout << finishTimes[i].second->getName() << " finished in: " << finishTimes[i].first << " seconds" << "\n";
	}
	for (int i = 0; i < finishTimes.size(); i++) {
		if(finishTimes[i].first==-1)
			std::cout << finishTimes[i].second->getName() << " did not finish" << "\n";

	}
}

void Circuit::ShowWhoDidNotFinish()
{
	std::cout << "Cars that did not finish: " << "\n";
	for (int i = 0; i < finishTimes.size(); i++)
		if (finishTimes[i].first == -1)
			std::cout << finishTimes[i].second->getName() << "\n";
}

