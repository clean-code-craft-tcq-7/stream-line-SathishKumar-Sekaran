using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static StreamingProject.BMS_SensorParams;
namespace StreamingProject
{
    partial class BMS
    {
        public BMS_KeyParams inputBMSSensor;
        public const int noOfReadings = 50;
        public const int movingAverageSampleCount = 5;
        public void setInputSensor(BMS_KeyParams sensorName)
        {
            this.inputBMSSensor = sensorName;
        }

        public List<double> get_Receiver_Input(string SenderOutput)
        {
            //var input = "Temperature Sensor : Current Sensor\n42.01 : 26.30\n19.72 : 4.30\n47.47 : 45.55";
            var receiverInput_array = SenderOutput.Split("\n");
            List<double> sensor_values = new List<double>();
            var sensorName_indexInReceiverInput = receiverInput_array[0].Split(" :").ToList().IndexOf(receiverInput_array[0].Split(" :").ToList().Find(x => x.Contains(inputBMSSensor.ToString())));

            for (int i = 1; i <= receiverInput_array.Length - 1; i++) //ignoring the sensor names - 0th index of array
            {
                sensor_values.Add(double.Parse(receiverInput_array[i].Split(" :")[sensorName_indexInReceiverInput]));
            }
            return sensor_values;
            
        }

        public double getMin_fromSensorValues(string SensorOutput)
        {
            return get_Receiver_Input(SensorOutput).Min();
        }

        public double getMax_fromSensorValues(string SensorOutput)
        {
            return get_Receiver_Input(SensorOutput).Max();
        }

        public double getMovingAverage_fromSensorValues(string SensorOutput)
        {
            return get_Receiver_Input(SensorOutput).TakeLast(movingAverageSampleCount).Average();
        }

    }
}
