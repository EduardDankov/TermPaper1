#pragma once
#include "ISensor.h"

#include <cstdlib>
#include <ctime>

class HousingConditionSensor :
    public ISensor
{
public:
    HousingConditionSensor();

    /* Check
    * Returns true if the housing is in normal condition, false - if it is broken
    * The housing breaks on average every 1 000 checks after fixing
    */
    bool Check() override;
    bool Check(bool);
    bool Check(bool, unsigned int);
};

