#pragma once

#include <stdio.h>

double getLinearFrequency(int channel) {
    int freq = 0;
    if (channel < 14) {
        freq = ((channel - 1) * 5) + 2412;
    } else if (channel == 14) {
        freq = 2484;
    } else if (channel < 174) {
        freq = ((channel - 7) * 5) + 5035;
    }
    return (double)freq * 1e6;
}

int getChannel(int frequency) {
    int channel = 0;
    if (frequency < 2473) {
        channel = ((frequency - 2412) / 5) + 1;
    } else if (frequency == 2484) {
        channel = 14;
    } else if (frequency > 5034 && frequency < 5866) {
        channel = ((frequency - 5035) / 5) + 7;
    }
    return channel;
}

double prod(double nums[], int size) {
    double prod = 1;
    for (int i = 0; i < size; i++) {
        prod *= nums[i];
    }
    return prod;
}