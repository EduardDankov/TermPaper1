#pragma once
#include "ISensor.h"

#include <cstdlib>
#include <ctime>

class LightConditionSensor :
    public ISensor
{
public:
    LightConditionSensor();

    /* Check
    * Returns true if the lights are in normal condition, false - if some of them are broken
    * The lights break on average every 10 000 checks after fixing
    */
    bool Check() override;
    bool Check(bool);
};

