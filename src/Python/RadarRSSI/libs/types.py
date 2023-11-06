from dataclasses import dataclass

@dataclass
class RFData:
    ReceivedDBM: float
    Channel: int
    RXAntennaDBI: float

@dataclass
class TransmitterData:
    TXAntennaDBI: float
    TXPowerDBM: float
    