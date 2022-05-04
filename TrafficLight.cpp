#include "TrafficLight.h"

/* Constructors */
TrafficLight::TrafficLight(std::string label, ControlType controlType) : Label(label), Control(controlType) {}

/* Getters */
TrafficLight::ControlType TrafficLight::GetControlType()
{
	return this->Control;
}

TrafficLight::Mode TrafficLight::GetCurrentMode()
{
	return this->CurrentMode;
}

TrafficLight::LightColor TrafficLight::GetCurrentLightColor()
{
	return this->CurrentLightColor;
}

/* Setters */
void TrafficLight::SetMode(TrafficLight::Mode mode)
{
	this->CurrentMode = mode;
}

void TrafficLight::SetLightColor(TrafficLight::LightColor lightColor)
{
	this->CurrentLightColor = lightColor;
}