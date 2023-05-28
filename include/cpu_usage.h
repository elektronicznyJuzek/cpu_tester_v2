#include <string.h>

#define MAX_NUMBERS 100
#define MAX_LENGTH 100

struct cpu_usage {
    int user;
    int nice;
    int system;
    int idle;
    int iowait;
    int irq;
    int softirq;
    int steal;
    int guest;
    int guest_nice;
};