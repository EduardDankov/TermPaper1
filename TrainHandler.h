#pragma once
#include <vector>

#include "Train.h"

class TrainHandler
{
private:
	std::vector<Train>* Trains;

	void Move();

public:
	TrainHandler(std::vector<Train>*);

	void Init();
	void CheckTrainsPosition();
};

