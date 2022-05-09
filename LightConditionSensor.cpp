#include "LightConditionSensor.h"

LightConditionSensor::LightConditionSensor()
	: ISensor(SensorType::BrokenLightDetector) {}

bool LightConditionSensor::Check()
{
	std::srand(std::time(nullptr));
	unsigned short generatedValue = std::rand() % 10000;
	return generatedValue != 0;
}
