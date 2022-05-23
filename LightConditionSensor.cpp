#include "LightConditionSensor.h"

LightConditionSensor::LightConditionSensor()
	: ISensor(SensorType::BrokenLightDetector) {}

bool LightConditionSensor::Check()
{
	return this->Check(false);
}

bool LightConditionSensor::Check(bool isInEmergency)
{
	unsigned short generatedValue = std::rand() % 10000;
	return isInEmergency ? (generatedValue == 0) : (generatedValue != 0);
}
