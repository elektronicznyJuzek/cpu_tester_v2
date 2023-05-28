#include "cpu_usage.h"

int main()
{
    FILE *file;
    int cpu_number = 0;
    char word[] = "cpu";
    char line[MAX_LENGTH];

    struct cpu_usage cpu[9];

    file = fopen("/proc/stat", "r");
    if (file == NULL)
    {
        printf("Can't open file /proc/stat.\n");
        return 1;
    }

    fseek(file, 0, SEEK_SET);

    read_cpu_usage(file, cpu, 0);
    //test_show(cpu, 0);

    fclose(file);

    return 0;
}