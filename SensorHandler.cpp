#include "SensorHandler.h"
#include "EmergencyEvent.h"
#include "Database.h"

void SensorHandler::CheckHousingCondition()
{
	for (int i = 0; i < (*this->TrafficLights).size(); i++)
	{
		bool isInNormalCondition;
		EmergencyEvent* emergencyHousingEvent = Database::GetEmergencyEvent(Activator::Sensor, EventType::BrokenHousing, &(*this->TrafficLights)[i]);
		if (emergencyHousingEvent == nullptr) emergencyHousingEvent = Database::GetEmergencyEvent(Activator::Dispatcher, EventType::BrokenHousing, &(*this->TrafficLights)[i]);

		if (emergencyHousingEvent != nullptr)
		{
			if (emergencyHousingEvent->GetStatus() == Status::SpecialService)
			{
				isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check(true, 5);
			}
			else
			{
				isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check(true, 1000);
			}
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
		if (emergencyLightEvent == nullptr) emergencyLightEvent = Database::GetEmergencyEvent(Activator::Dispatcher, EventType::BrokenHousing, &(*this->TrafficLights)[i]);

		if (emergencyLightEvent != nullptr)
		{
			if (emergencyLightEvent->GetStatus() == Status::SpecialService)
			{
				isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check(true, 5);
			}
			else
			{
				isInNormalCondition = (*this->TrafficLights)[i].LCSensor.Check(true, 1000);
			}
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
	Database::TH.CheckTrainsPosition();
}

SensorHandler::SensorHandler(std::vector<TrafficLight>* trafficLights)
{
	this->TrafficLights = trafficLights;
}

void SensorHandler::Init()
{
	std::srand(std::time(nullptr));

	this->CheckHousingCondition();
	this->CheckLightCondition();
	this->CheckPassingTrains();
}
