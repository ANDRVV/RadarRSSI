#pragma once

#include <stdint.h>

typedef struct {
    double receivedDBM;
    int channel;
    double rxAntennaDBI;
} RFData;

RFData parseRT(uint8_t * bytes) {
    // coming soon...
}