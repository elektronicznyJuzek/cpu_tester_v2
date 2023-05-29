#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUMBERS 100
#define MAX_LENGTH 100

struct proc_stat {
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

struct cpu_data {
    FILE *file;
    struct proc_stat *cpu;
    int cpu_number;
};


void *read_cpu_usage(void *data);

void *analyze_cpu_usage(void *data);

void test_show(struct proc_stat cpu[], int cpu_number);
