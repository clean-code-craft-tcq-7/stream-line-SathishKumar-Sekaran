#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Sender.h"
#include "ReadSensorVal.h"
#include "testCases_Sender.h"

void testSendToServer(char* buf);
const FuncPtrTestSenderType sendFunPtr[] =
{
    SendToServer,
    testSendToServer
};

void testSendToServer(char* buf)
{
    float SensorOut[Max_Sensor][50];
    char buf[500];
    memset(buf,'\0',100);
    Get_Sensor_Readings(MAX_TEMP_RANGE,50,SensorOut[Temparature]);
    Get_Sensor_Readings(MAX_TEMP_RANGE,50,SensorOut[Current]);
    Send_Sensor_val(SensorOut,2,50,buf);
}

int main()
{
    testCases_Sender();
    return 0;
}