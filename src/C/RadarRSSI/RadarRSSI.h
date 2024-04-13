#include "libs\calc.h"
#include "libs\utils.h"
#include "libs\radiotap.h"
#include <math.h>
#include <stdint.h>

typedef struct {
    double receivedDBM;
    int channel;
    double rxAntennaDBI;
} RFData;

typedef struct {
    double txPowerDBM;
    double txAntennaDBI;
} TransmitterData;

RFData getRFDataFromRadiotap(uint8_t * packetData, double rxAntennaDBI) {
	/*RFData RadioTapInfo = parseRT(packetData);
	if (RadioTapInfo.channel > 0) {
		RadioTapInfo.receivedDBM = rxAntennaDBI;
		return RadioTapInfo;
	}
	return (RFData){};*/
}

RFData getCustomRFData(double receivedDBM, int channel, double rxAntennaDBI) {
	return (RFData){.receivedDBM = receivedDBM, .channel = channel, .rxAntennaDBI = rxAntennaDBI};
}

TransmitterData getDefaultTransmitterData() {
	return (TransmitterData){.txPowerDBM = 17.5, .txAntennaDBI = 4};
}

TransmitterData getCustomTransmitterData(double txAntennaDBI, double txPowerDBM) {
	return (TransmitterData){.txPowerDBM = txPowerDBM, .txAntennaDBI = txAntennaDBI};
}

double getAutoDBPathLoss(RFData RxFData) {
	if (RxFData.receivedDBM > -8) {
		return 0;
	} else {
		if (RxFData.channel < 15) {
			return 0.65 * (-RxFData.receivedDBM) - 12;  
		}
		return 0.55 * (-RxFData.receivedDBM) - 8.22; 
	}
}

double radiolocate(RFData RxFData, TransmitterData TXData, double DBPathLoss) {
	double info[5]; 
	info[0] = RxFData.rxAntennaDBI;
	info[1] = TXData.txAntennaDBI;
	info[2] = TXData.txPowerDBM;
	info[3] = (double)RxFData.channel;
	info[4] = RxFData.receivedDBM - DBPathLoss;
	return calculateFriis(info, 5);
}