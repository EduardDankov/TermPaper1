#include "TrainHandler.h"

#include <iostream>

#include "Database.h"

TrainHandler::TrainHandler(std::vector<Train>* trains)
{
	this->Trains = trains;
}

void TrainHandler::Move()
{
	for (int i = 0; i < (*this->Trains).size(); i++)
	{
		(*this->Trains)[i].Move();
	}
}

void TrainHandler::Init()
{
	this->Move();
}

void TrainHandler::CheckTrainsPosition()
{
	std::cout << "\n ====== INFORMATION ====== " << std::endl;
	for (int i = 0; i < (*this->Trains).size(); i++)
	{
		std::cout
			<< " Train #" << (*this->Trains)[i].GetNumber()
			<< " - TL "
			<< (*Database::GetTrafficLights())[(*this->Trains)[i].GetCurrentTLId()].GetLabel()
			<< " [" << (*this->Trains)[i].GetCurrentTLId() << "]"
			<< std::endl;
	}
	std::cout << " ========================= " << std::endl;
}
