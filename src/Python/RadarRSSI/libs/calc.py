import math
from .utils import GetLinearFrequency

def CalculateFriis(info: [float]) -> float: # type: ignore
    numerator: float = math.sqrt((math.prod(info[:len(info) - 2]) * 299792458 ** 2) / (10 ** (info[len(info) - 1] / 10)))
    denominator: float = 4 * math.pi * GetLinearFrequency(int(info[len(info) - 2]))
    return float(round(numerator / denominator, 1))
       