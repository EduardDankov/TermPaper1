#pragma once
#include <iostream>
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

	// Task 6: Change some traffic light's mode
	static void ChangeTLMode();
	// Task 7: Change some traffic light's light
	static void ChangeTLLight();
	// Task 10: Stop all trains (red light)
	static void StopTheLine();

	static Mode GetModeByIdFromCin();
	static LightColor GetLightByIdFromCin();

	std::string GetLabel() { return this->Label; }
	ControlType GetControlType() { return this->Control; }
	Mode GetMode() { return this->CurrentMode; }
	LightColor GetLightColor() { return this->CurrentLightColor; }

	void SetMode(Mode mode)	{ this->CurrentMode = mode;	}
	void SetLightColor(LightColor lightColor) {	this->CurrentLightColor = lightColor; }
};

