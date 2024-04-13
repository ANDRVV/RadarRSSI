<h1 align="center">RadarRSSI (C Version)</h1>

<h3>Example</h3>

```C
    #include "RadarRSSI\RadarRSSI.h"

    int main() {
        RFData RFDATA = getCustomRFData(-20, 1, 5);
                  /*
                  Insert received dBm, channel & rx/your dBi antenna.
                  */ 
        // or
        TransmitterData TXData = getDefaultTransmitterData();
                  /*
                  GetDefaultTransmitterData() return
                  TX Antenna: 3    dBi
                  TX Power  : 20.5 dBm
                  */
        // or
        TransmitterData TXData = getCustomTransmitterData(4, 23);
                  /*
                  Insert custom TX Antenna dBi
                  & TX Power dBm
                  */
        double DBPathLoss = getAutoDBPathLoss(RFDATA);
                  /*
                  Return approximating DB Path Loss
                  (according to some research)
                  */

        double APPRX_METERS = radiolocate(RFData, TXData, DBPathLoss);

        printf("%.1f meters", APPRX_METERS);

        return 0;
    }
```