#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sender.h"
void testCases_Sender(void)
{
    //No Sensor Data
    {
        float SensorData[10];
        char buff[100];
        memset(buff,'\0',100);
        GetTx_Sensor_val(SensorData,0,0,buff);
        assert(strcmp(buff,"") == 0);
    }
    //One data get from One sensor
    {
        char buff[100];
        memset(buff,'\0',100);
        float SensorData[1] ={20.5};
        GetTx_Sensor_val(SensorData,1,1,buff);
        assert(strcmp(buff,"Temparature Sensor\n20.50\n") == 0);
    }
    //4 data's get from 1  sensor
    {
        char buff[100];
        memset(buff,'\0',100);
        float SensorData[] ={20.5,14,38.7,40.2};
        GetTx_Sensor_val(SensorData,1,4,buff);
        assert(strcmp(buff,"Temparature Sensor\n20.50\n14.00\n38.70\n40.20\n") == 0);
    }
    //2 data get 2 different sensors
    {
        char buff[100];
        memset(buff,'\0',100);
        float SensorData[2][1] ={{20.5},{7.5}};
        GetTx_Sensor_val(SensorData,2,1,buff);
        assert(strcmp(buff,"Temparature Sensor : Current Sensor\n20.50 : 7.50\n") == 0);
    }
    //totally 8 data's get 2 different sensors
    {
        char buff[100];
        memset(buff,'\0',100);
        float SensorData[2][4] ={{20.5,14,28.9,36.7},{5.7,8.9,4.2,6.3}};
        GetTx_Sensor_val(SensorData,2,4,buff);
        assert(strcmp(buff,"Temparature Sensor : Current Sensor\n20.50 : 5.70\n14.00 : 8.90\n28.90 : 4.20\n36.70 : 6.30\n") == 0);
    }
}