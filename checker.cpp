#include <iostream>
#include <vector>
#include "checker.hpp"
#include "checkertest.hpp"

BMS::Languages BMS::prefferedlanguage = BMS::Languages::English;
bool BMS::isBatteryOkay(BMS::compositeValidator* CompositeValidators)
{
   return CompositeValidators->isParamOkay();
}        
int main()
{
    BMS::compositeValidator* validators = new BMS::compositeValidator();
    
    //Checking language support
    BMS::prefferedlanguage = BMS::Languages::English;
    validators->add(new BMS::TemperatureValidator(25.0f));
    validators->add(new BMS::SocValidator(30.0f));
    validators->add(new BMS::RocValidator(0.5));
    isBatteryOkay(validators);
    validators->display();
   
    BMS::prefferedlanguage = BMS::Languages::German;
    validators->setValue(BMS::ParameterCheck::TEMPERTURE, 3);
    validators->setValue(BMS::ParameterCheck::CHARGERATE, 0.7f);
    validators->setValue(BMS::ParameterCheck::STATEOFCHARGE, 30);
    isBatteryOkay(validators);
    validators->display();

    testBMS(validators); // to check whether battery is okay
   
    return 0;
}
