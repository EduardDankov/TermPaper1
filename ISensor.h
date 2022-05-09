#pragma once
#include "TrafficLight.h"

enum class SensorType
{
	BrokenHousingDetector,
	BrokenLightDetector,
	PassingTrainDetector,
};

class ISensor
{
private:

protected:
	SensorType Type;

	ISensor(SensorType);

public:
	SensorType GetType() { return this->Type; }
	
	virtual bool Check() = 0;
};

