#include <stdio.h>
#include <string.h>
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

    // while ((ch = fgetc(file)) != EOF)
    // {
    //     printf("%c", ch);
    // }

    fseek(file, 0, SEEK_SET);
    //printf("\n");

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, word) != NULL)
        {
            //printf("CPU%d: %s", cpu_number - 1, line);

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
                        //printf("user: %d\n", cpu[cpu_number].user);
                        break;
                    case 2:
                        cpu[cpu_number].nice = field_value;
                        //printf("nice: %d\n", cpu[cpu_number].nice);
                        break;
                    case 3:
                        cpu[cpu_number].system = field_value;
                        //printf("system: %d\n", cpu[cpu_number].system);
                        break;
                    case 4:
                        cpu[cpu_number].idle = field_value;
                        //printf("idle: %d\n", cpu[cpu_number].idle);
                        break;
                    case 5:
                        cpu[cpu_number].iowait = field_value;
                        //printf("iowait: %d\n", cpu[cpu_number].iowait);
                        break;
                    case 6:
                        cpu[cpu_number].irq = field_value;
                        //printf("irq: %d\n", cpu[cpu_number].irq);
                        break;
                    case 7:
                        cpu[cpu_number].softirq = field_value;
                        //printf("softirq: %d\n", cpu[cpu_number].softirq);
                        break;
                    case 8:
                        cpu[cpu_number].steal = field_value;
                        //printf("steal: %d\n", cpu[1].steal);
                        break;
                    case 9:
                        cpu[cpu_number].guest = field_value;
                        //printf("guest: %d\n", cpu[cpu_number].guest);
                        break;
                    case 10:
                        cpu[cpu_number].guest_nice = field_value;
                        //printf("guest_nice: %d\n", cpu[cpu_number].guest_nice);
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

    if (cpu[0].user == cpu[1].user + cpu[2].user + cpu[3].user + cpu[4].user + cpu[5].user + cpu[6].user + cpu[7].user + cpu[8].user)
        printf("User works\n");
    else
        printf("User not work: %d != %d\n", cpu[0].user, cpu[1].user + cpu[2].user + cpu[3].user + cpu[4].user + cpu[5].user + cpu[6].user + cpu[7].user + cpu[8].user);

    if (cpu[0].nice == cpu[1].nice + cpu[2].nice + cpu[3].nice + cpu[4].nice + cpu[5].nice + cpu[6].nice + cpu[7].nice + cpu[8].nice)
        printf("Nice works\n");
    else
        printf("Nice not work: %d != %d\n", cpu[0].nice, cpu[1].nice + cpu[2].nice + cpu[3].nice + cpu[4].nice + cpu[5].nice + cpu[6].nice + cpu[7].nice + cpu[8].nice);

    if (cpu[0].system == cpu[1].system + cpu[2].system + cpu[3].system + cpu[4].system + cpu[5].system + cpu[6].system + cpu[7].system + cpu[8].system)
        printf("System works\n");
    else
        printf("System not work: %d != %d\n", cpu[0].system, cpu[1].system + cpu[2].system + cpu[3].system + cpu[4].system + cpu[5].system + cpu[6].system + cpu[7].system + cpu[8].system);

    if (cpu[0].idle == cpu[1].idle + cpu[2].idle + cpu[3].idle + cpu[4].idle + cpu[5].idle + cpu[6].idle + cpu[7].idle + cpu[8].idle)
        printf("Idle works\n");
    else
        printf("Idle not work: %d != %d\n", cpu[0].idle, cpu[1].idle + cpu[2].idle + cpu[3].idle + cpu[4].idle + cpu[5].idle + cpu[6].idle + cpu[7].idle + cpu[8].idle);

    if (cpu[0].iowait == cpu[1].iowait + cpu[2].iowait + cpu[3].iowait + cpu[4].iowait + cpu[5].iowait + cpu[6].iowait + cpu[7].iowait + cpu[8].iowait)
        printf("Iowait works\n");
    else
        printf("Iowait not work: %d != %d\n", cpu[0].iowait, cpu[1].iowait + cpu[2].iowait + cpu[3].iowait + cpu[4].iowait + cpu[5].iowait + cpu[6].iowait + cpu[7].iowait + cpu[8].iowait);

    if (cpu[0].irq == cpu[1].irq + cpu[2].irq + cpu[3].irq + cpu[4].irq + cpu[5].irq + cpu[6].irq + cpu[7].irq + cpu[8].irq)
        printf("IRQ works\n");
    else
        printf("IRQ not work: %d != %d\n", cpu[0].irq, cpu[1].irq + cpu[2].irq + cpu[3].irq + cpu[4].irq + cpu[5].irq + cpu[6].irq + cpu[7].irq + cpu[8].irq);

    if (cpu[0].softirq == cpu[1].softirq + cpu[2].softirq + cpu[3].softirq + cpu[4].softirq + cpu[5].softirq + cpu[6].softirq + cpu[7].softirq + cpu[8].softirq)
        printf("SoftIRQ works\n");
    else
        printf("SoftIRQ not work: %d != %d\n", cpu[0].softirq, cpu[1].softirq + cpu[2].softirq + cpu[3].softirq + cpu[4].softirq + cpu[5].softirq + cpu[6].softirq + cpu[7].softirq + cpu[8].softirq);

    if (cpu[0].steal == cpu[1].steal + cpu[2].steal + cpu[3].steal + cpu[4].steal + cpu[5].steal + cpu[6].steal + cpu[7].steal + cpu[8].steal)
        printf("Steal works\n");
    else
        printf("Steal not work: %d != %d\n", cpu[0].steal, cpu[1].steal + cpu[2].steal + cpu[3].steal + cpu[4].steal + cpu[5].steal + cpu[6].steal + cpu[7].steal + cpu[8].steal);

    if (cpu[0].guest == cpu[1].guest + cpu[2].guest + cpu[3].guest + cpu[4].guest + cpu[5].guest + cpu[6].guest + cpu[7].guest + cpu[8].guest)
        printf("Guest works\n");
    else
        printf("Guest not work: %d != %d\n", cpu[0].guest, cpu[1].guest + cpu[2].guest + cpu[3].guest + cpu[4].guest + cpu[5].guest + cpu[6].guest + cpu[7].guest + cpu[8].guest);

    if (cpu[0].guest_nice == cpu[1].guest_nice + cpu[2].guest_nice + cpu[3].guest_nice + cpu[4].guest_nice + cpu[5].guest_nice + cpu[6].guest_nice + cpu[7].guest_nice + cpu[8].guest_nice)
        printf("Guest Nice works\n");
    else
        printf("Guest Nice not work: %d != %d\n", cpu[0].guest_nice, cpu[1].guest_nice + cpu[2].guest_nice + cpu[3].guest_nice + cpu[4].guest_nice + cpu[5].guest_nice + cpu[6].guest_nice + cpu[7].guest_nice + cpu[8].guest_nice);

    fclose(file);

    return 0;
}