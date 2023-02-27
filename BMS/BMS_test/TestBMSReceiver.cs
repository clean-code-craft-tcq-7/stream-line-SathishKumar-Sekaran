using Moq;
using System;
using System.Text;
using Xunit;
using static StreamingProject.BMSReceiver_PrintSensorStatistics;

namespace StreamingProject
{
    public class TestBMSReceiver
    {
        static Current Current = new Current();
        static Temperature temperature = new Temperature();

        string RxInput = "Temperature Sensor : Current Sensor\n42.01 : 26.30\n19.72 : 4.30\n47.47 : 45.55\n9.88 : 17.44\n16.76 : 3.21\n38.41 : 1.00";
        
        [Fact]
        public void getSensorsOutput_ReadParameters()
        {
            var actualResult = temperature.get_Receiver_Input(RxInput);
            Assert.Equal(new double[] { 42.01, 19.72, 47.47, 9.88, 16.76, 38.41 }, actualResult);

            actualResult = Current.get_Receiver_Input(RxInput);
            Assert.Equal(new double[] { 26.3, 4.3, 45.55, 17.44, 3.21, 1 }, actualResult);
        }

        [Fact]
        public void getSensorsOutput_MinReading()
        {
            var actualResult = temperature.getMin_fromSensorValues(RxInput);
            Assert.Equal(9.88, actualResult);

            actualResult = Current.getMin_fromSensorValues(RxInput);
            Assert.Equal(1, actualResult);
        }

        [Fact]
        public void getSensorsOutput_MaxReading()
        {
            var actualResult = temperature.getMax_fromSensorValues(RxInput);
            Assert.Equal(47.47, actualResult);

            actualResult = Current.getMax_fromSensorValues(RxInput);
            Assert.Equal(45.55, actualResult);
        }

        [Fact]
        public void getSensorsOutput_SimpleMovingAverageReading()
        {
            var actualResult = temperature.getMovingAverage_fromSensorValues(RxInput);
            Assert.Equal(26.448, actualResult);

            actualResult = Current.getMovingAverage_fromSensorValues(RxInput);
            Assert.Equal(14.299999999999997, actualResult);
        }

        [Fact]
        public void Test_PrintBMSReceiverStatistics()
        {
            BMSReceiver_PrintStatisticsOutput(RxInput);

            //Arrange
            var moq = new Mock<BMS.IBMS_BMSReceiver_StatisticsOutput>();
            moq.Setup(mk => mk.BMSReceiver_PrintStatisticsOutput(RxInput)).Verifiable();

        }

    }

}
