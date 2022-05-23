#include "HousingConditionSensor.h"

HousingConditionSensor::HousingConditionSensor()
	: ISensor(SensorType::BrokenHousingDetector) {}


bool HousingConditionSensor::Check()
{
	return this->Check(false);
}

bool HousingConditionSensor::Check(bool isInEmergency)
{
	return this->Check(isInEmergency, 10000);
}

bool HousingConditionSensor::Check(bool isInEmergency, unsigned int coefficient)
{
	unsigned short generatedValue = std::rand() % coefficient;
	return isInEmergency ? (generatedValue == 0) : (generatedValue != 0);
}
