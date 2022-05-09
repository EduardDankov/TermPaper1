#pragma once
#include "ISensor.h"

class PassingTrainSensor :
    public ISensor
{
public:
    PassingTrainSensor();

    /* Check
    * Returns true if there is a train near the traffic light, false - if not
    */
    bool Check() override;
};

