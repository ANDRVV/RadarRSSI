<h1 align="center">RadarRSSI (Python Version)</h1>

<h3>Example</h3>

```python
    from RadarRSSI import *
    import sys

    RFDATA = GetCustomRFData(-20, 1, 5)
             # Insert received dBm, channel & rx/your dBi
             # antenna.
    # or
    Packet: bytes = ...
    try:
        RFDATA = GetRFDataFromRadiotap(Packet)
                 # Insert full packet or RadioTap layer (bytes).
                 # If the packet isn't valid return error.
    except:
        print("Invalid packet!")
        sys.exit(1)

    TXData = GetDefaultTransmitterData()
             # GetDefaultTransmitterData() return
             # TX Antenna: 3    dBi
             # TX Power  : 20.5 dBm
    # or
    TXData = GetCustomTransmitterData(4, 23)
             # Insert custom TX Antenna dBi
             # & TX Power dBm

    DBPathLoss: float = 14
             # Insert dB Path Loss
    # or
    DBPathLoss: float = 0
             # If you don't want insert dB Path Loss,
             # putting zero, the default path loss is
             # 10 dB for 2.4 Ghz & 2 dB for 5 Ghz
    # or
    var DBPathLoss float = 0.001
             # If you don't even want to enter the 
             # default path loss, add 0.001 dB.

    APPRX_METERS = Radiolocate(RFData, TXData, DBPathLoss)

    print(APPRX_METERS, " meters")
```