#pragma once
#include <vector>

#include "TrafficLight.h"
#include "Train.h"

class SensorHandler
{
private:
	std::vector<TrafficLight>* TrafficLights;

	void CheckHousingCondition();
	void CheckLightCondition();
	void CheckPassingTrains();

public:
	SensorHandler(std::vector<TrafficLight>*);

	void Init();
};

