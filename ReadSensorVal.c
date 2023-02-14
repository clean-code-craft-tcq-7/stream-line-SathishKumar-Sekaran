#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReadSensorVal.h"

void Get_Sensor_Readings(float maxRange,int maxReadings,float* SensorOut)
{
    for(int loopCnt=0;loopCnt<maxReadings;loopCnt++)
    {
        SensorOut[loopCnt] = ((float)rand()/(float)(RAND_MAX)) * maxRange;
    }
}