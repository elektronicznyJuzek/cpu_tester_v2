#include <stdio.h>
#include "cpu_usage.h"

void *read_cpu_usage(FILE *file, struct cpu_usage cpu[], int cpu_number)
{
    char word[] = "cpu";
    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, word) != NULL)
        {
            // printf("CPU%d: %s", cpu_number - 1, line);

            int field_value = 0;
            int field_counter = 1;
            char *token = strtok(line, " "); // Split the line by spaces

            while (token != NULL)
            {
                if (sscanf(token, "%d", &field_value) == 1)
                {
                    // printf("Found at line %d: count%d: %d\n", cpu_number, field_counter, field_value);

                    switch (field_counter)
                    {
                    case 1:
                        cpu[cpu_number].user = field_value;
                        // printf("user: %d\n", cpu[cpu_number].user);
                        break;
                    case 2:
                        cpu[cpu_number].nice = field_value;
                        // printf("nice: %d\n", cpu[cpu_number].nice);
                        break;
                    case 3:
                        cpu[cpu_number].system = field_value;
                        // printf("system: %d\n", cpu[cpu_number].system);
                        break;
                    case 4:
                        cpu[cpu_number].idle = field_value;
                        // printf("idle: %d\n", cpu[cpu_number].idle);
                        break;
                    case 5:
                        cpu[cpu_number].iowait = field_value;
                        // printf("iowait: %d\n", cpu[cpu_number].iowait);
                        break;
                    case 6:
                        cpu[cpu_number].irq = field_value;
                        // printf("irq: %d\n", cpu[cpu_number].irq);
                        break;
                    case 7:
                        cpu[cpu_number].softirq = field_value;
                        // printf("softirq: %d\n", cpu[cpu_number].softirq);
                        break;
                    case 8:
                        cpu[cpu_number].steal = field_value;
                        // printf("steal: %d\n", cpu[1].steal);
                        break;
                    case 9:
                        cpu[cpu_number].guest = field_value;
                        // printf("guest: %d\n", cpu[cpu_number].guest);
                        break;
                    case 10:
                        cpu[cpu_number].guest_nice = field_value;
                        // printf("guest_nice: %d\n", cpu[cpu_number].guest_nice);
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
                printf("No integers found at line %d\n", cpu_number);
        }
        cpu_number++;
    }
}