#include "includes.h"

float mem_info()
{
    FILE* file = fopen("/proc/meminfo", "r");
    char buffer[50];
    bool isDigit = 0;
    int count1 = 0;
    int count2 = 0;
    int memory_info[3];
    char current;

    if(!file)
    {
        perror("Error: ");
        abort();
    }

    while(count2 < 3)
    {
        current = fgetc(file);

        if(isdigit(current))
        {
            buffer[count1] = current;
            isDigit = 1;
            count1++;
        }

        else
        {
            if(isDigit)
            {
                memory_info[count2] = atoi(buffer);
                strncpy(buffer, "", sizeof(buffer));
                count2++;
                count1 = 0;
                isDigit = 0;
            }
        }
    }

    float free_space = memory_info[0] - memory_info[2];
    free_space = free_space / 1000000;
    fclose(file);
    return free_space;
}

int* parse_cpu()
{
    FILE* file = fopen("/proc/stat", "r");
    char buffer[15] = "";
    int buffer_count = 0;
    int* cpu_info = malloc(15 * sizeof(int));
    int cpu_count = 0;
    char current;
    bool isDigit = 0;
    char stirng_to_parse[256];

    if(!file)
    {
        perror("Error: ");
        abort();
    }

    fgets(stirng_to_parse, 256, file);
    fclose(file);

    for(int i = 0; i < strlen(stirng_to_parse); i++)
    {
        current = stirng_to_parse[i];

        if(isdigit(current))
        {
            buffer[buffer_count] = current;
            buffer_count++;
            isDigit = 1;
        }

        else
        {
            if(isDigit)
            {
                cpu_info[cpu_count] = atoi(buffer);
                cpu_count++;
                strncpy(buffer, "", sizeof(buffer));
                buffer_count = 0;
                isDigit = 0;
            }
        }
    }

    return cpu_info;
}

double cpu_usage()
{
    int* cpu_1 = parse_cpu();
    sleep(1);
    int* cpu_2 = parse_cpu();

    int used_1 = cpu_1[0] + cpu_1[2];
    int used_2 = cpu_2[0] + cpu_2[2];

    int total_1 = cpu_1[0] + cpu_1[2] + cpu_1[3];
    int total_2 = cpu_2[0] + cpu_2[2] + cpu_2[3];

    double usage = (double)(used_2 - used_1) / (total_2 - total_1) * 100;
    
    free(cpu_1);
    free(cpu_2);

    return usage;
}

void printf_free_space(char* path)
{
    struct statvfs vfs;

    if(statvfs(path, &vfs) == -1)
    {
        perror("Statvfs error");
        abort();
    }

    long long free_space = vfs.f_bfree * vfs.f_frsize;

    printf("Free space in directory %s - %lld Bytes\n", path, free_space);
}