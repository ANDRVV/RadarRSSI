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
	return TransmitterData(TXAntennaDBI = 4, TXPowerDBM = 17.5)

def GetCustomTransmitterData(TXAntennaDBI: float, TXPowerDBM: float) -> TransmitterData:
	return TransmitterData(TXAntennaDBI = TXAntennaDBI, TXPowerDBM = TXPowerDBM)

def GetAutoDBPathLoss(RxFData: RFData) -> float:
    if RxFData.ReceivedDBM > -8:
        return 0
    if RxFData.Channel < 15:
        return 0.65 * (-RxFData.ReceivedDBM) - 12  
    return 0.55 * (-RxFData.ReceivedDBM) - 8.22
    

def Radiolocate(RxFData: RFData, TXData: TransmitterData, DBPathLoss: float) -> float:
    info: list[float] = []
    info.append(RxFData.RXAntennaDBI)
    info.append(TXData.TXAntennaDBI)
    info.append(TXData.TXPowerDBM)
    info.append(float(RxFData.Channel))
    info.append(RxFData.ReceivedDBM - DBPathLoss)
    return CalculateFriis(info)