<div align="center" style="display:grid;place-items:center;">
<p>
    <img src="https://github.com/ANDRVV/RadarRSSI/blob/main/images/RadarRSSI-logo.png?raw=true" width=425.5 height=202.5 alt="Gapcast logo">
</p>

[Ask me](mailto:vaccaro.andrea45@gmail.com) | [Features](https://github.com/ANDRVV/RadarRSSI#features)

</div>
<p align="center"><strong>RadarRSSI</strong> is an IEEE 802.11 Radar library based on RSSI information 📶</p>

<h1 align="center">How it works and what RadarRSSI is</h1>

<p align="center"><strong>RadarRSSI is a radiolocation tool</strong> based on <i>RSSI</i> (Received Signal Strength Indicator).</p>

<p>This tool uses the first Friis equation to calculate its approximate meters. Among the information that must be entered to make the calculation are:</p>

<div align="left" style="display:grid;place-items:center;">
    <ol>
        <li><strong>TX Antenna</strong> dBi</li>
        <li><strong>TX Power</strong> dBm</li>
        <li><strong>RX Antenna</strong> dBi</li>
        <li><strong>RX Received Power</strong> dBm</li>
        <li><strong>Path Loss</strong> dB</li>
        <li><strong>Channel</strong></li>
    </ol>
</div>

<h2 align="center">Path Loss</h2>

<p align="center">If you do not enter the path loss in the calculation, it will be by default <strong>10 dB for the 2.4</strong> Ghz band, and <strong>2 dB for the 5 Ghz</strong>. If you do not even want to assign the default path loss, just enter 0.001 dB, which will be negligible and no changes will be made in the calculation.</p>

<h2 align="center">Auto-DBPathLoss</h2>

<p>This library has an Auto-DBPathLoss system where the Path Loss is chosen via an algorithm, it was created through research and has been tested many times with excellent results. To use this feature just check the docs and use the Auto-DBPathLoss function appropriately.</p>

<h1 align="center">Programming languages</h1>

<p align="center">RadarRSSI was written in the following languages and can be used as a library:</p>

<div align="left" style="display:grid;place-items:center;">
    <ul>
        <li>Golang [<a href="https://github.com/ANDRVV/RadarRSSI/tree/main/src/Go">Check docs</a>]</li>
        <li>Python [<a href="https://github.com/ANDRVV/RadarRSSI/tree/main/src/Python">Check docs</a>]</li>
        <li>C++ [Coming soon...]</li>
        <li>C [Coming soon...]</li>
    </ul>
</div>
