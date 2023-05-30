#include "proc_stat.h"

int main()
{
    pthread_t reader;
    int rc;

    struct cpu_data *data;

    data = (struct cpu_data *)calloc(1, sizeof(struct cpu_data));

    if (data == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // rc = pthread_create(&reader, NULL, read_cpu_usage, (void *)&data);
    // rc = pthread_create(&reader, NULL, analyze_cpu_usage, (void *)&data);

    printf("adres struktury: %p\n", data);

    while (1)
    {
        rc = pthread_create(&reader, NULL, read_cpu_usage, (void *)data);
        if (!sleep(2))
            break;
    }

    printf("\n");

    for (int i = 0; i < 9; i++)
        printf("user[%d] in main %p = %d\n", i, data->cpu[i].user, data->cpu[i].user);

    for (int i = 0; i < 9; i++)
        printf("nice[%d] in main %p = %d\n", i, data->cpu[i].nice, data->cpu[i].nice);

    for (int i = 0; i < 9; i++)
        printf("system[%d] in main %p = %d\n", i, data->cpu[i].system, data->cpu[i].system);

    for (int i = 0; i < 9; i++)
        printf("idle[%d] in main %p = %d\n", i, data->cpu[i].idle, data->cpu[i].idle);
    
    for (int i = 0; i < 9; i++)
        printf("iowait[%d] in main %p = %d\n", i, data->cpu[i].iowait, data->cpu[i].iowait);
    
    for (int i = 0; i < 9; i++)
        printf("irq[%d] in main %p = %d\n", i, data->cpu[i].irq, data->cpu[i].irq);

    for (int i = 0; i < 9; i++)
        printf("softirq[%d] in main %p = %d\n", i, data->cpu[i].softirq, data->cpu[i].softirq);

    for (int i = 0; i < 9; i++)
        printf("steal[%d] in main %p = %d\n", i, data->cpu[i].steal, data->cpu[i].steal);

    for (int i = 0; i < 9; i++)
        printf("guest[%d] in main %p = %d\n", i, data->cpu[i].guest, data->cpu[i].guest);

    for (int i = 0; i < 9; i++)
        printf("guest_nice[%d] in main %p = %d\n", i, data->cpu[i].guest_nice, data->cpu[i].guest_nice);
    
    free(data);

    return 0;
}