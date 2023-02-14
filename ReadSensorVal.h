enum
{
    Temparature,
    Current,
    Max_Sensor,
}en_Sensor;

char Sensorname[Max_Sensor][100] = 
{
    "Temparature Sensor",
    "Current Sensor",
};


#define MAX_TEMP_RANGE          50
#define MAX_Current_RANGE       10

void Get_Sensor_Readings(float maxRange,int maxReadings,float* SensorOut);
