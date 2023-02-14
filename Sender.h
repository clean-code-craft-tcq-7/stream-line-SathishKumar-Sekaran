typedef void (*FuncPtrTestSenderType) (void);

typedef int (*Func2PtrSenderType)(char*);

void SendToServer(void);
void GetTx_Sensor_val(float *SensorData,int totalSensorCnt,int totalSensorReadCnt,char *tx_Buffer)