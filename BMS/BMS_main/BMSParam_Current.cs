using System;
using System.Collections.Generic;
using System.Text;
using static StreamingProject.BMS_SensorParams;

namespace StreamingProject
{

    class Current : BMS
    {
        public Current()
        {
            this.inputBMSSensor = BMS_KeyParams.Current;
        }
        public Current(string SenderOutput)
        {
            this.inputBMSSensor = BMS_KeyParams.Current;
            //this.ReceiverInput = get_Receiver_Input(SenderOutput);
        }
    }
}
