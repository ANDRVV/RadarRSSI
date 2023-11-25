#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"
#include "cmath.h"

#pragma once

double calculateFriis(double info[], int infoSize) {
    double numerator = prod(info, infoSize - 2) * pow(299792458, 2);
    double semiDenominator = 4 * PI * getLinearFrequency((int)info[infoSize - 2]);
    double meters = 0.1;
    while (1) {
        if (10 * log10(numerator / pow(semiDenominator * meters, 2)) < info[infoSize - 1]) {
            if (meters > 0.1) {
                char strMeters[20];
                sprintf(strMeters, "%.1f", meters - 0.1);
                return toF64(strMeters);
            }
            char strMeters[20];
            sprintf(strMeters, "%.1f", meters);
            return toF64(strMeters);
        }
        meters += 0.1;
    }
}