#include "proc_stat.h"

void *read_cpu_usage(void *data)
{
    char word[] = "cpu";
    char line[MAX_LENGTH];

    struct cpu_data *arg = (struct cpu_data *)data;

    printf("adres struktury data w funkcji: %p\n", data);
    printf("adres struktury arg w funkcji: %p\n", arg);

    struct proc_stat *cpu_ = NULL;

    cpu_ = (struct proc_stat *)calloc(9, sizeof(struct proc_stat));

    arg->cpu = cpu_;
    arg->cpu_number = 0;
    arg->file = fopen("/proc/stat", "r");

    if (arg->file == NULL)
    {
        printf("Can't open file /proc/stat.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), arg->file))
    {
        printf("%s", line); // Print each line of the file
    }

    fseek(arg->file, 0, SEEK_SET);

    while (fgets(line, sizeof(line), arg->file))
    {
        if (strstr(line, word) != NULL)
        {
            int field_value = 0;
            int field_counter = 1;
            char *token = strtok(line, " "); // Split the line by spaces

            while (token != NULL)
            {
                if (sscanf(token, "%d", &field_value) == 1)
                {
                    switch (field_counter)
                    {
                    case 1:
                        arg->cpu[arg->cpu_number].user = field_value;
                        break;
                    case 2:
                        arg->cpu[arg->cpu_number].nice = field_value;
                        break;
                    case 3:
                        arg->cpu[arg->cpu_number].system = field_value;
                        break;
                    case 4:
                        arg->cpu[arg->cpu_number].idle = field_value;
                        break;
                    case 5:
                        arg->cpu[arg->cpu_number].iowait = field_value;
                        break;
                    case 6:
                        arg->cpu[arg->cpu_number].irq = field_value;
                        break;
                    case 7:
                        arg->cpu[arg->cpu_number].softirq = field_value;
                        break;
                    case 8:
                        arg->cpu[arg->cpu_number].steal = field_value;
                        break;
                    case 9:
                        arg->cpu[arg->cpu_number].guest = field_value;
                        break;
                    case 10:
                        arg->cpu[arg->cpu_number].guest_nice = field_value;
                        break;
                    default:
                        printf("Invalid case value: %d\n", field_counter);
                        break;
                    }
                    field_counter++;
                }
                token = strtok(NULL, " ");
            }
            if (field_counter == 0)
                printf("No integers found at line %d\n", arg->cpu_number);
        }
        arg->cpu_number++;
    }

    //arg->cpu[3].nice = 1234;

    for (int i = 0; i < 9; i++)
        printf("user[%d] in thread %p = %d\n", i, arg->cpu[i].user, arg->cpu[i].user);

    for (int i = 0; i < 9; i++)
        printf("nice[%d] in thread %p = %d\n", i, arg->cpu[i].nice, arg->cpu[i].nice);

    for (int i = 0; i < 9; i++)
        printf("system[%d] in thread %p = %d\n", i, arg->cpu[i].system, arg->cpu[i].system);

    for (int i = 0; i < 9; i++)
        printf("idle[%d] in thread %p = %d\n", i, arg->cpu[i].idle, arg->cpu[i].idle);

    for (int i = 0; i < 9; i++)
        printf("iowait[%d] in thread %p = %d\n", i, arg->cpu[i].iowait, arg->cpu[i].iowait);

    for (int i = 0; i < 9; i++)
        printf("irq[%d] in thread %p = %d\n", i, arg->cpu[i].irq, arg->cpu[i].irq);

    for (int i = 0; i < 9; i++)
        printf("softirq[%d] in thread %p = %d\n", i, arg->cpu[i].softirq, arg->cpu[i].softirq);

    for (int i = 0; i < 9; i++)
        printf("steal[%d] in thread %p = %d\n", i, arg->cpu[i].steal, arg->cpu[i].steal);

    for (int i = 0; i < 9; i++)
        printf("guest[%d] in thread %p = %d\n", i, arg->cpu[i].guest, arg->cpu[i].guest);

    for (int i = 0; i < 9; i++)
        printf("guest_nice[%d] in thread %p = %d\n", i, arg->cpu[i].guest_nice, arg->cpu[i].guest_nice);
    // printf("idle[7] in thread = %d\n", arg->cpu[9].idle);

    free(cpu_);
    fclose(arg->file);
    pthread_exit(NULL);
}

void *analyze_cpu_usage(void *data)
{
    pthread_exit(NULL);
}

void *check_data(void *data)
{
    pthread_exit(NULL);
}