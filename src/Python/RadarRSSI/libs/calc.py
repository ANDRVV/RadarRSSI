import math
from .utils import GetLinearFrequency

def CalculateFriis(info: [float]) -> float:
    numerator: float = math.prod(info[:len(info) - 2]) * 299792458 ** 2
    semiDenominator: float = 4 * math.pi * GetLinearFrequency(int(info[len(info) - 2]))
    meters: float = 0.1
    while True:
        if 10 * math.log10(numerator / math.pow(semiDenominator * meters, 2)) < info[len(info) - 1]:
            if meters > 0.1:
                return float(round(meters - 0.1, 1))
            return float(round(meters, 1))
        meters += 0.1