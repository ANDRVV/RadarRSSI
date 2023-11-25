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
	return (TransmitterData){.txPowerDBM = 20.5, .txAntennaDBI = 3};
}

TransmitterData getCustomTransmitterData(double txAntennaDBI, double txPowerDBM) {
	return (TransmitterData){.txPowerDBM = txPowerDBM, .txAntennaDBI = txAntennaDBI};
}

double getAutoDBPathLoss(RFData RxFData) {
	if (RxFData.channel < 15) {
    	double autoDBPL = 0.65 * abs(RxFData.receivedDBM) + -12;  
		if (autoDBPL > 10) {
			return autoDBPL;
		}
		return 10;
	}
	double autoDBPL = 0.5555555555555556 * abs(RxFData.receivedDBM) + -8.222222222222221; 
	if (autoDBPL > 2) {
		return autoDBPL;
	}
	return 2;
}

double radiolocate(RFData RxFData, TransmitterData TXData, double DBPathLoss) {
	double totalPathLoss = DBPathLoss > 0 ? DBPathLoss : (RxFData.channel < 15 ? 10.0 : 2.0);
	double info[5]; 
	info[0] = RxFData.rxAntennaDBI;
	info[1] = TXData.txAntennaDBI;
	info[2] = TXData.txPowerDBM;
	info[3] = (double)RxFData.channel;
	info[4] = RxFData.receivedDBM + totalPathLoss;
	return calculateFriis(info, 5);
}