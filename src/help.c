#include "includes.h"

void printf_help()
{
	printf("get-proc - Get all running processes\n");
	printf("kill-proc -PID- - Kill process by PID\n");
	printf("memory-usage - Get RAM usage\n");
	printf("cpu-usage - Get CPU usage\n");
	printf("get-proc-info -PID- - Get all process information by PID\n");
	printf("get-disk-info -Path- - Get free space in path directory\n");
	printf("get-cpu-name - Get name of your CPU\n");
	printf("get-os-name - Get name of your operating system\n");
	printf("scan-all-ports -PID- - Get all ports on process\n");
}
