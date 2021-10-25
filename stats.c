#include "stats.h"

Struct Stats{
    float average;
    float min;
    float max;
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
