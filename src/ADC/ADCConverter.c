#include <stdio.h>
#include "ADCConverter.h"

int PowerOf2(int bitRate)
{
    int returnVal = 1;
    while(bitRate > 0)
    {
        returnVal *=2;
        bitRate--;
    }
    return returnVal;
}

int ADC_Read_Sensor_Value(float SersorVal,int bitRate,int minValue,int maxValue)
{
    int Max_differentVal_Amps = maxValue - minValue;
    int outVal = ADC_DEFAULT_COUNT_VAL;
    int TotalCnt = 0;
    //Get Max count value depands on adc bit rate
    TotalCnt = PowerOf2(bitRate);
    if((SersorVal<(float)maxValue) && (SersorVal>(float)minValue))
    {
        outVal = (float)(SersorVal/(float)Max_differentVal_Amps)*(float)TotalCnt;
    }
    return outVal;
}