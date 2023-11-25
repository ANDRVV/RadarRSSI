#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double toF64(const char *strmeters) {
    return strtod(strmeters, NULL);
}