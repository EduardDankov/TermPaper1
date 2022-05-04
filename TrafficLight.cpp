#include "TrafficLight.h"

/* Constructors */
TrafficLight::TrafficLight(std::string label, ControlType controlType)
{
	this->Label = label;
	this->Control = controlType;

	this->CurrentLightColor = LightColor::Red;
	this->CurrentMode = Mode::Auto;
}

/* Getters */
std::string TrafficLight::GetLabel()
{
	return this->Label;
}

ControlType TrafficLight::GetControlType()
{
	return this->Control;
}

Mode TrafficLight::GetCurrentMode()
{
	return this->CurrentMode;
}

LightColor TrafficLight::GetCurrentLightColor()
{
	return this->CurrentLightColor;
}

/* Setters */
void TrafficLight::SetMode(Mode mode)
{
	this->CurrentMode = mode;
}

void TrafficLight::SetLightColor(LightColor lightColor)
{
	this->CurrentLightColor = lightColor;
}