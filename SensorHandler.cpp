#include "SensorHandler.h"
#include "EmergencyEvent.h"
#include "Database.h"

void SensorHandler::CheckHousingCondition()
{
	for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		bool isInNormalCondition;
		EmergencyEvent* emergencyHousingEvent = Database::GetEmergencyEvent(Activator::Sensor, EventType::BrokenHousing, &(*this->TrafficLights)[i]);
		if (emergencyHousingEvent != nullptr) emergencyHousingEvent = Database::GetEmergencyEvent(Activator::Dispatcher, EventType::BrokenHousing, &(*this->TrafficLights)[i]);

		if (emergencyHousingEvent != nullptr)
		{
			isInNormalCondition = (*this->TrafficLights)[i].HCSensor.Check(true) | (*this->TrafficLights)[i].HCSensor.Check(true);
		}
		else
		{
			isInNormalCondition = (*this->TrafficLights)[i].HCSensor.Check();
		}

		if (!isInNormalCondition)
		{
			if (emergencyHousingEvent == nullptr)
			{
				Database::AddEmergencyEvent(Activator::Sensor, EventType::BrokenLight, &(*this->TrafficLights)[i]);
			}
		}
		else
		{
			if (emergencyHousingEvent != nullptr)
			{
				emergencyHousingEvent->SetStatus(Status::Solved);
				std::cout << "Emergency event #" << i << " has been solved. Please, update events and resync traffic lights." << std::endl;
			}
		}
	}
}

void SensorHandler::CheckLightCondition()
{
	for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		bool isInNormalCondition;
		EmergencyEvent* emergencyLightEvent = Database::GetEmergencyEvent(Activator::Sensor, EventType::BrokenLight, &(*this->TrafficLights)[i]);
		if (emergencyLightEvent != nullptr) emergencyLightEvent = Database::GetEmergencyEvent(Activator::Dispatcher, EventType::BrokenHousing, &(*this->TrafficLights)[i]);

		if (emergencyLightEvent != nullptr)
		{
			isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check(true) | (*this->TrafficLights)[i].LCSensor.Check(true);
		}
		else
		{
			isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check();
		}

		if (!isInNormalCondition)
		{
			if (emergencyLightEvent == nullptr)
			{
				Database::AddEmergencyEvent(Activator::Sensor, EventType::BrokenLight, &(*this->TrafficLights)[i]);
			}
		}
		else
		{
			if (emergencyLightEvent != nullptr)
			{
				emergencyLightEvent->SetStatus(Status::Solved);
				std::cout << "Emergency event #" << i << " has been solved. Please, update events and resync traffic lights." << std::endl;
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
