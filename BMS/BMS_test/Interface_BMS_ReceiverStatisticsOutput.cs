using System;
using System.Collections.Generic;
using System.Text;

namespace StreamingProject
{
    partial class BMS
    {

        public interface IBMS_BMSReceiver_StatisticsOutput
        {
            void BMSReceiver_PrintStatisticsOutput(string RxInput);

        }

    }
}
