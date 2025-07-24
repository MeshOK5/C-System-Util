#include "includes.h"

void scan_proc_ports(char* pid)
{
    char path[100];
    char buffer[256];

    strcat(path, "/proc/");
    strcat(path, pid);
    strcat(path, "/net/tcp");

    FILE* file = fopen(path, "r");
    printf("TCP:\n");
    if(file)
    {
        while(fgets(buffer, 256, file) != NULL)
            printf("%s", buffer);
        fclose(file);
    }

    strncpy(path, "", sizeof(path));

    strcat(path, "proc/");
    strcat(path, pid);
    strcat(path, "/net/udp");

    printf("UDP:\n");
    file = fopen(path, "r");
    if(file)
    {
        while(fgets(buffer, 200, file))
            printf("%s", buffer);
        fclose(file);
    }
}