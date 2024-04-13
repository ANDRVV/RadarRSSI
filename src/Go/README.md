<h1 align="center">RadarRSSI (Go Version)</h1>

<h3>Example</h3>

```go
    package main

    import (
        "fmt"
        "RadarRSSI"
    )

    func main() {
        RFDATA := RadarRSSI.GetCustomRFData(-20, 1, 5)
                  /*
                  Insert received dBm, channel & rx/your dBi antenna.
                  */ 
        // or
        var Packet []byte = ...
        RFDATA, err := RadarRSSI.GetRFDataFromRadiotap(Packet)
                    /*
                    Insert full packet or RadioTap layer (bytes).
                    If the packet isn't valid return error.
                    */
        if err != nil {
            fmt.Println("Invalid packet!")
            return
        }

        TXData := RadarRSSI.GetDefaultTransmitterData()
                  /*
                  GetDefaultTransmitterData() return
                  TX Antenna: 3    dBi
                  TX Power  : 20.5 dBm
                  */
        // or
        TXData := RadarRSSI.GetCustomTransmitterData(4, 23)
                  /*
                  Insert custom TX Antenna dBi
                  & TX Power dBm
                  */
        var DBPathLoss float64 = RadarRSSI.GetAutoDBPathLoss(RFDATA)
                  /*
                  Return approximating DB Path Loss
                  (according to some research)
                  */

        APPRX_METERS = RadarRSSI.Radiolocate(RFData, TXData, DBPathLoss)

        fmt.Println(APPRX_METERS, " meters")
    }
```