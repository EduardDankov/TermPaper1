#include "HousingConditionSensor.h"

HousingConditionSensor::HousingConditionSensor()
	: ISensor(SensorType::BrokenHousingDetector) {}

bool HousingConditionSensor::Check()
{
	std::srand(std::time(nullptr));
	unsigned short generatedValue = std::rand() % 10000;
	return generatedValue != 0;
}
