using System;
using System.Collections.Generic;
using System.Text;
using static StreamingProject.BMS_SensorParams;

namespace StreamingProject
{
    class Temperature : BMS
    {
        public Temperature()
        {
            this.inputBMSSensor = BMS_KeyParams.Temperature;
        }
        public Temperature(string SenderOutput)
        {
            this.inputBMSSensor = BMS_KeyParams.Current;
        }
    }
}
