def GetLinearFrequency(channel: int) -> float:
	freq: float
	if channel < 14:
		freq = ((channel - 1) * 5) + 2412
	elif channel == 14:
		freq = 2484
	elif channel < 174:
		freq = ((channel - 7) * 5) + 5035
	return float(freq) * 1e6

def GetChannel(frequency: int) -> int:
	channel: int
	if frequency < 2473:
		channel = ((frequency - 2412) / 5) + 1
	elif frequency == 2484:
		channel = 14
	elif frequency > 5034 and frequency < 5866:
		channel = ((frequency - 5035) / 5) + 7
	return channel