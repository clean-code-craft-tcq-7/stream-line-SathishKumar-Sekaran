#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "ADCConverter.h"

TEST_CASE("Get Current value and if Sensor value Is invalid") 
{
    //If value is less than of min value
    float SensorVal =-1;
    int outVal;
    outVal = ADC_Read_Sensor_Value(SensorVal,12,0,10);
    REQUIRE(outVal == ADC_DEFAULT_COUNT_VAL);

    //If value is grater than of max value
    SensorVal = 12;
    outVal = ADC_Read_Sensor_Value(SensorVal,12,0,10);
    REQUIRE(outVal == ADC_DEFAULT_COUNT_VAL);
}

TEST_CASE("Get Current value and if Sensor value Is Valid") 
{
    float SensorVal = 7;
    int outVal;
    outVal = ADC_Read_Sensor_Value(SensorVal,12,0,10);
    REQUIRE(outVal == 3000);
    
    SensorVal = 5;
    outVal = ADC_Read_Sensor_Value(SensorVal,12,0,10);
    REQUIRE(outVal == 2000);
}

TEST_CASE("Get Current value and if Sensor value bit rate and range changed") 
{
    float SensorVal = 7;
    int outVal;
    outVal = ADC_Read_Sensor_Value(SensorVal,10,-15,15);
    REQUIRE(outVal == 3003);
    
    SensorVal = 5;
    outVal = ADC_Read_Sensor_Value(SensorVal,10,-15,15);
    REQUIRE(outVal == 2731);
}

