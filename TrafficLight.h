#pragma once
#include <string>

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

public:
	/* Constructors */
	TrafficLight(std::string, ControlType);

	/* Getters */
	std::string GetLabel();
	ControlType GetControlType();
	Mode GetCurrentMode();
	LightColor GetCurrentLightColor();

	/* Setters */
	void SetMode(Mode);
	void SetLightColor(LightColor);
};

