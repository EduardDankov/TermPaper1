#include "TrafficLight.h"

TrafficLight::TrafficLight(std::string label, ControlType controlType)
{
	this->Label = label;
	this->Control = controlType;

	this->CurrentLightColor = LightColor::Red;
	this->CurrentMode = Mode::Auto;

	this->HCSensor = HousingConditionSensor();
	this->LCSensor = LightConditionSensor();
	this->PTSensor = PassingTrainSensor();
}
