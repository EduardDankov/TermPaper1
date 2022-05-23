#include "SensorHandler.h"
#include "EmergencyEvent.h"
#include "Database.h"

void SensorHandler::CheckHousingCondition()
{
	for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		bool isInNormalCondition;
		EmergencyEvent* EmergencyHousingEvent = Database::GetEmergencyEvent(Activator::Sensor, EventType::BrokenHousing, &(*this->TrafficLights)[i]);

		if (EmergencyHousingEvent != nullptr)
		{
			isInNormalCondition = (*this->TrafficLights)[i].HCSensor.Check(true) | (*this->TrafficLights)[i].HCSensor.Check(true);
		}
		else
		{
			isInNormalCondition = (*this->TrafficLights)[i].HCSensor.Check();
		}

		if (!isInNormalCondition)
		{
			if (EmergencyHousingEvent == nullptr)
			{
				Database::AddEmergencyEvent(Activator::Sensor, EventType::BrokenLight, &(*this->TrafficLights)[i]);
			}
		}
		else
		{
			if (EmergencyHousingEvent != nullptr)
			{
				std::cout << "Housing #" << i << " is not broken, but event is still active. Please, review the event and resync traffic lights." << std::endl;
			}
		}
	}
}

void SensorHandler::CheckLightCondition()
{
	for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		bool isInNormalCondition;
		EmergencyEvent* EmergencyLightEvent = Database::GetEmergencyEvent(Activator::Sensor, EventType::BrokenLight, &(*this->TrafficLights)[i]);

		if (EmergencyLightEvent != nullptr)
		{
			isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check(true) | (*this->TrafficLights)[i].LCSensor.Check(true);
		}
		else
		{
			isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check();
		}

		if (!isInNormalCondition)
		{
			if (EmergencyLightEvent == nullptr)
			{
				Database::AddEmergencyEvent(Activator::Sensor, EventType::BrokenLight, &(*this->TrafficLights)[i]);
			}
		}
		else
		{
			if (EmergencyLightEvent != nullptr)
			{
				std::cout << "Light #" << i << " is not broken, but event is still active. Please, review the event and resync traffic lights." << std::endl;
			}
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
