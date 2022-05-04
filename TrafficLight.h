#pragma once
#include <string>

class TrafficLight
{
private:
	const static enum Mode
	{
		Automatic,
		Manual,
		Emergency
	};

	const static enum ControlType 
	{
		Automatic,
		Semiautomatic
	};

	const static enum LightColor
	{
		None,
		Red,
		Yellow,
		Green,
		Blue,
		MoonWhite
	};

	const std::string Label;
	const ControlType Control;

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

