#include "includes.h"

void printf_system_name()
{
    FILE* file = fopen("/etc/os-release", "r");
    char name[50];

    if(!file)
    {
        perror("Error: ");
        abort();
    }

    fgets(name, 50, file);
    printf("%s", name);

    fclose(file);
}

void printf_cpu_name()
{
    FILE* file = fopen("/proc/cpuinfo", "r");
    char name[50];

    if(!file)
    {
        perror("Error: ");
        abort();
    }

    while(fgets(name, 50, file))
        if(!strncmp(name, "model name	:", strlen("model name	:"))) break;

    printf("%s", name);
}