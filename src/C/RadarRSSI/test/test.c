#include "..\RadarRSSI.h"

int main() {
    RFData RFDATA = getCustomRFData(-22, 1, 5); 
    TransmitterData TXData = getDefaultTransmitterData();
        
    double DBPathLoss = getAutoDBPathLoss(RFDATA);
                
    double APPRX_METERS = radiolocate(RFDATA, TXData, DBPathLoss);

    printf("%.1f meters", APPRX_METERS);
    return 0;
}