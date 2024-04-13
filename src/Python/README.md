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

    DBPathLoss: float = GetAutoDBPathLoss(RFDATA)
             # Return approximating DB Path Loss
             # (according to some research)

    APPRX_METERS = Radiolocate(RFData, TXData, DBPathLoss)

    print(APPRX_METERS, " meters")
```