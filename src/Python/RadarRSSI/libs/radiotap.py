from .types import RFData
from .utils import GetChannel
from scapy.layers.dot11 import RadioTap, Packet

def ParseRT(RadioTapData: bytes) -> RFData:
    packet: Packet = RadioTap(_pkt = RadioTapData)
    return RFData(ReceivedDBM = packet[RadioTap].dBm_AntSignal, Channel = GetChannel(packet[RadioTap].ChannelFrequency), RXAntennaDBI = -1)
    