#include "PassingTrainSensor.h"

PassingTrainSensor::PassingTrainSensor()
	: ISensor(SensorType::PassingTrainDetector) {}

bool PassingTrainSensor::Check()
{
	return false;
}
