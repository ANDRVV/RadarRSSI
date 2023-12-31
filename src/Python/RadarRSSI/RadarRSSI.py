from .libs import *

def GetRFDataFromRadiotap(packetData: bytes, RXAntennaDBI: float) -> RFData:
    RadioTapInfo = ParseRT(packetData)
    if RadioTapInfo.Channel > 0:
        RadioTapInfo.RXAntennaDBI = RXAntennaDBI
        return RadioTapInfo
    raise Exception()

def GetCustomRFData(ReceivedDBM: float, Channel: int, RXAntennaDBI: float) -> RFData:
	return RFData(ReceivedDBM = ReceivedDBM, Channel = Channel, RXAntennaDBI = RXAntennaDBI)

def GetDefaultTransmitterData() -> TransmitterData:
	return TransmitterData(TXAntennaDBI = 3, TXPowerDBM = 20.5)

def GetCustomTransmitterData(TXAntennaDBI: float, TXPowerDBM: float) -> TransmitterData:
	return TransmitterData(TXAntennaDBI = TXAntennaDBI, TXPowerDBM = TXPowerDBM)

def GetAutoDBPathLoss(RxFData: RFData) -> float:
    if RxFData.Channel < 15:
        autoDBPL: float = 0.65 * abs(RxFData.ReceivedDBM) + -12  
        if autoDBPL > 10:
            return autoDBPL
        return 10
    autoDBPL: float = 0.5555555555555556 * abs(RxFData.ReceivedDBM) + -8.222222222222221
    if autoDBPL > 2:
        return autoDBPL
    return 2

def Radiolocate(RxFData: RFData, TXData: TransmitterData, DBPathLoss: float) -> float:
    if DBPathLoss > 0:
        totalPathLoss = DBPathLoss
    elif RxFData.Channel < 15:
        totalPathLoss = 10
    else:
        totalPathLoss = 2
    info: list[float] = []
    info.append(RxFData.RXAntennaDBI)
    info.append(TXData.TXAntennaDBI)
    info.append(TXData.TXPowerDBM)
    info.append(float(RxFData.Channel))
    info.append(RxFData.ReceivedDBM + totalPathLoss)
    return CalculateFriis(info)