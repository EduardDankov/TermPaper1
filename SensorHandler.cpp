#include "SensorHandler.h"

void SensorHandler::CheckHousingCondition()
{
	for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		bool isInNormalCondition;
		if ((*this->TrafficLights)[i].GetMode() == Mode::Emergency)
		{
			isInNormalCondition = (*this->TrafficLights)[i].HCSensor.Check(true) | (*this->TrafficLights)[i].HCSensor.Check(true);
		}
		else 
		{
			isInNormalCondition = (*this->TrafficLights)[i].HCSensor.Check();
		}

		if (!isInNormalCondition)
		{
			std::cout << "Housing #" << i << " is broken." << std::endl;
			(*this->TrafficLights)[i].SetLightColor(LightColor::None);
			(*this->TrafficLights)[i].SetMode(Mode::Emergency);
		}
		else if ((*this->TrafficLights)[i].GetMode() == Mode::Emergency)
		{
			std::cout << "Housing #" << i << " is not broken, but TL is in Emergency mode." << std::endl;
		}
	}
}

void SensorHandler::CheckLightCondition()
{
	for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		bool isInNormalCondition;
		if ((*this->TrafficLights)[i].GetMode() == Mode::Emergency)
		{
			isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check(true) | (*this->TrafficLights)[i].LCSensor.Check(true);
		}
		else
		{
			isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check();
		}

		if (!isInNormalCondition)
		{
			std::cout << "Light #" << i << " is broken." << std::endl;
			(*this->TrafficLights)[i].SetLightColor(LightColor::None);
			(*this->TrafficLights)[i].SetMode(Mode::Emergency);
		}
		else if ((*this->TrafficLights)[i].GetMode() == Mode::Emergency)
		{
			std::cout << "Light #" << i << " is not broken, but TL is in Emergency mode." << std::endl;
		}
	}
}

void SensorHandler::CheckPassingTrains()
{
	/*for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		if (!(*this->TrafficLights)[i].PTSensor.Check())
		{
			std::cout << "Light #" << i << " is broken." << std::endl;
			(*this->TrafficLights)[i].SetLightColor(LightColor::None);
			(*this->TrafficLights)[i].SetMode(Mode::Emergency);
		}
	}*/
}

SensorHandler::SensorHandler(std::vector<TrafficLight>* trafficLights)
{
	this->TrafficLights = trafficLights;
}

void SensorHandler::Init()
{
	this->CheckHousingCondition();
	this->CheckLightCondition();
	this->CheckPassingTrains();
}
