#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ReadSensorVal.h"
#include "Sender.h"
#include "testCases_Sender.h"

void testSendToServer(char* buf,char* checkBuff)
{
    float SensorOut[Max_Sensor][50];
    Get_Sensor_Readings(MAX_TEMP_RANGE,50,SensorOut[Temparature]);
    Get_Sensor_Readings(MAX_TEMP_RANGE,50,SensorOut[Current]);
    GetTx_Sensor_val(*SensorOut,2,50,buf);
    testGetStringOut(SensorOut[Temparature],SensorOut[Current],checkBuff,50);
}

void testGetStringOut(float *sensor1,float *sensor2,char *buff,int sensorReadcnt)
{
    strcat(buff,"Temparature Sensor : Current Sensor\n");
    int i =0;
    char tempBuf[50];
    while(i<sensorReadcnt)
    {
        memset(tempBuf,'\0',50);
        sprintf(tempBuf,"%0.2f : %0.2f\n",sensor1[i],sensor2[i]);
        strcat(buff,tempBuf);
    }
}

void testCases_Sender()
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
        GetTx_Sensor_val(*SensorData,2,1,buff);
        assert(strcmp(buff,"Temparature Sensor : Current Sensor\n20.50 : 7.50\n") == 0);
    }
    //totally 8 data's get 2 different sensors
    {
        char buff[100];
        memset(buff,'\0',100);
        float SensorData[2][4] ={{20.5,14,28.9,36.7},{5.7,8.9,4.2,6.3}};
        GetTx_Sensor_val(*SensorData,2,4,buff);
        assert(strcmp(buff,"Temparature Sensor : Current Sensor\n20.50 : 5.70\n14.00 : 8.90\n28.90 : 4.20\n36.70 : 6.30\n") == 0);
    }
    {
        char buff[500];
        char checkBuff[500];
        memset(buff,'\0',500);
        memset(checkBuff,'\0',500);
        ((Func2PtrSenderType)(*(sendFunPtr[1])))(buff,checkBuff);
        assert(strcmp(buff,checkBuff) == 0);
    }
}