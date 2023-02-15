#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ReadSensorVal.h"
#include "Sender.h"
#include "testCases_Sender.h"

const FuncPtrTestSenderType sendFunPtr[] =
{
    (FuncPtrTestSenderType) SendToServer,
    (FuncPtrTestSenderType) testSendToServer
};

void GetTx_Sensor_val(float *SensorData,int totalSensorCnt,int totalSensorReadCnt,char *tx_Buffer)
{
    char tempBuff[50];
    int readSensorCnt = 0;
    int currentSensor =0;
    if (totalSensorCnt > currentSensor)
    {
        while(totalSensorCnt > currentSensor)
        {
            if(currentSensor > 0)
            {
                strcat(tx_Buffer," : ");
            }
            strcat(tx_Buffer,Sensorname[currentSensor]);
            currentSensor++;
        }
        strcat(tx_Buffer,"\n");
        while(totalSensorReadCnt > readSensorCnt)
        {
            for(int i=0;i<totalSensorCnt;i++)
            {
                sprintf(tempBuff,"%0.2f",SensorData[(i*(totalSensorReadCnt))+readSensorCnt]);
                strcat(tx_Buffer,tempBuff);
                readSensorCnt++;
                if((i+1<totalSensorCnt))
                {
                    strcat(tx_Buffer," : ");
                    readSensorCnt--;
                }
                else
                {
                    strcat(tx_Buffer,"\n");
                }
            }
        }
    }
}

void SendToServer(char *buf)
{
    float SensorOut[Max_Sensor][50];
    memset(buf,'\0',500);
    Get_Sensor_Readings(MAX_TEMP_RANGE,50,SensorOut[Temparature]);
    Get_Sensor_Readings(MAX_TEMP_RANGE,50,SensorOut[Current]);
    GetTx_Sensor_val(*SensorOut,2,50,buf);
    write(STDOUT_FILENO, buf, strlen(buf));
}