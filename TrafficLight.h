#pragma once
#include <string>

#include "HousingConditionSensor.h"
#include "LightConditionSensor.h"
#include "PassingTrainSensor.h"

enum class Mode
{
	Auto,
	Manual,
	Emergency
};

enum class ControlType
{
	Automatic,
	Semiautomatic
};

enum class LightColor
{
	None,
	Red,
	Yellow,
	Green,
	Blue,
	MoonWhite
}; 

class TrafficLight
{
private:
	std::string Label;
	ControlType Control;

	Mode CurrentMode;
	LightColor CurrentLightColor;

	HousingConditionSensor HCSensor;
	LightConditionSensor LCSensor;
	PassingTrainSensor PTSensor;

public:
	TrafficLight(std::string, ControlType);

	std::string GetLabel() { return this->Label; }
	ControlType GetControlType() { return this->Control; }
	Mode GetCurrentMode() { return this->CurrentMode; }
	LightColor GetCurrentLightColor() { return this->CurrentLightColor; }

	void SetMode(Mode mode)	{ this->CurrentMode = mode;	}
	void SetLightColor(LightColor lightColor) {	this->CurrentLightColor = lightColor; }
};

