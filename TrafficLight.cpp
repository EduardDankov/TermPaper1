#include "TrafficLight.h"
#include "Database.h"

TrafficLight::TrafficLight(std::string label, ControlType controlType)
{
	this->Label = label;
	this->Control = controlType;

	this->CurrentLightColor = LightColor::None;
	this->CurrentMode = Mode::Auto;

	this->HCSensor = HousingConditionSensor();
	this->LCSensor = LightConditionSensor();
	this->PTSensor = PassingTrainSensor();
}

Mode TrafficLight::GetModeByIdFromCin()
{
	unsigned short modeId;

	do
	{
		std::cout << "0. Auto\n1. Manual\n2. Emergency\nChoose the mode: ";
		std::cin >> modeId;
		std::cin.clear();

		if (modeId >= 0 && modeId <= 2)
		{
			return (Mode)(modeId);
		}
	} while (true);
}

LightColor TrafficLight::GetLightByIdFromCin()
{
	unsigned short lightId;

	do
	{
		std::cout << "0. None\n1. Red\n2. Yellow\n3. Green\n4. Blue\n5. MoonWhite\nChoose the light: ";
		std::cin >> lightId;
		std::cin.clear();

		if (lightId >= 0 && lightId <= 5)
		{
			return (LightColor)(lightId);
		}
	} while (true);
}

void TrafficLight::ShowLightInEmergencyLabels()
{
	std::vector<TrafficLight>* trafficLights = Database::GetTrafficLights();
	for (int i = 0; i < (*trafficLights).size(); i++)
	{
		if ((*trafficLights)[i].GetMode() == Mode::Emergency)
		{
			std::cout
				<< "Traffic light "
				<< (*trafficLights)[i].GetLabel()
				<< " is in emergency mode."
				<< std::endl;
		}
	}
}

void TrafficLight::ShowLightInManualLabels()
{
	std::vector<TrafficLight>* trafficLights = Database::GetTrafficLights();
	for (int i = 0; i < (*trafficLights).size(); i++)
	{
		if ((*trafficLights)[i].GetMode() == Mode::Manual)
		{
			std::cout
				<< "Traffic light "
				<< (*trafficLights)[i].GetLabel()
				<< " is in manual mode."
				<< std::endl;
		}
	}
}

void TrafficLight::ChangeTLMode()
{
	TrafficLight* trafficLight = Database::GetTrafficLightByLabelFromCin();
	std::cout << "TL found. Current mode: " << (int)((*trafficLight).GetMode()) << std::endl;
	Mode mode = GetModeByIdFromCin();

	(*trafficLight).SetMode(mode);
	std::cout << "Done. Mode changed to " << (int)((*trafficLight).GetMode()) << std::endl;
}

void TrafficLight::ChangeTLLight()
{
	TrafficLight* trafficLight = Database::GetTrafficLightByLabelFromCin();
	std::cout << "TL found. Current light: " << (int)((*trafficLight).GetLightColor()) << std::endl;
	LightColor light = GetLightByIdFromCin();

	(*trafficLight).SetLightColor(light);
	std::cout << "Done. Light changed to " << (int)((*trafficLight).GetLightColor()) << std::endl;
}

void TrafficLight::StopTheLine()
{
	std::vector<TrafficLight>* trafficLights = Database::GetTrafficLights();
	for (int i = 0; i < (*trafficLights).size(); i++)
	{
		(*trafficLights)[i].SetLightColor(LightColor::Red);
	}
	std::cout << "Done. All TL switched to red light." << std::endl;
}
