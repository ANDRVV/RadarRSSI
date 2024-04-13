#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"
#include "cmath.h"

#pragma once

double calculateFriis(double info[], int infoSize) {
    double numerator = sqrt((prod(info, infoSize - 2) * pow(299792458, 2)) / pow(10, (float)info[4] / 10));
    double denominator = 4 * PI * getLinearFrequency((int)info[infoSize - 2]);
    char strMeters[20];
    sprintf(strMeters, "%.1f", numerator / denominator);
    return toF64(strMeters);
}