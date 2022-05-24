#include "LightConditionSensor.h"

LightConditionSensor::LightConditionSensor()
	: ISensor(SensorType::BrokenLightDetector) {}

bool LightConditionSensor::Check()
{
	return this->Check(false);
}

bool LightConditionSensor::Check(bool isInEmergency)
{
	return this->Check(isInEmergency, 1000);
}

bool LightConditionSensor::Check(bool isInEmergency, unsigned int coefficient)
{
	unsigned short generatedValue = std::rand() % coefficient;
	return isInEmergency ? (generatedValue == 0) : (generatedValue != 0);
}
