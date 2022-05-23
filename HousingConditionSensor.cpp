#include "HousingConditionSensor.h"

HousingConditionSensor::HousingConditionSensor()
	: ISensor(SensorType::BrokenHousingDetector) {}


bool HousingConditionSensor::Check()
{
	return this->Check(false);
}

bool HousingConditionSensor::Check(bool isInEmergency)
{
	unsigned short generatedValue = std::rand() % 10000;
	return isInEmergency ? (generatedValue == 0) : (generatedValue != 0);
}
