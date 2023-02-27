using System;
using System.Collections.Generic;
using System.Text;

namespace StreamingProject
{
    class BMSReceiver_PrintSensorStatistics
    {
        static Current current = new Current();
        static Temperature temperature = new Temperature();

        public static void BMSReceiver_PrintStatisticsOutput(string ReceiverInput)
        {
            Console.WriteLine(format_ReceiverOutput(ReceiverInput));
        }

        public static string format_ReceiverOutput(string ReceiverInput)
        {
            string current_statistics = string.Concat(current.inputBMSSensor.ToString(), "\n",
                                        "Min: " + current.getMin_fromSensorValues(ReceiverInput).ToString() , ",",
                                        "Max: " + current.getMax_fromSensorValues(ReceiverInput).ToString(), ",",
                                        "Average: " + current.getMovingAverage_fromSensorValues(ReceiverInput).ToString()
                                        );
            string temp_statistics = string.Concat(temperature.inputBMSSensor.ToString(), "\n",
                                        "Min: " + temperature.getMin_fromSensorValues(ReceiverInput).ToString(), ",",
                                        "Max: " + temperature.getMax_fromSensorValues(ReceiverInput).ToString(), ",",
                                        "Average: " + temperature.getMovingAverage_fromSensorValues(ReceiverInput).ToString()
                                        );
            string Receiver_output = string.Concat(temp_statistics, "\n", current_statistics);
            return Receiver_output;
        }
    }
}
