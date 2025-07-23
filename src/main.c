#include "includes.h"

int main(int argc, char* argv[])
{
	assert(argc >= 2);
	if(!strcmp(argv[1], "help"))
		printf_help();
	else if(!strcmp(argv[1], "get-proc"))
		printf_process();
	else if(!strcmp(argv[1], "memory-usage"))
		printf("%f GiB\n", mem_info());
	else if(!strcmp(argv[1], "cpu-usage"))
		printf("%.2f %\n", cpu_usage());
	else if(!strcmp(argv[1], "kill-proc"))
	{
		assert(argc >= 3);
		pid_t pid = atoi(argv[2]);
		if(pid) kill_process(pid);
	}
	else if(!strcmp(argv[1], "get-proc-info"))
	{
		assert(argc >= 3);
		pid_t pid = atoi(argv[2]);
		if(pid) get_process_info(pid);
	}
	else if(!strcmp(argv[1], "get-os-name"))
		printf_system_name();
	else if(!strcmp(argv[1], "get-disk-info"))
	{
		assert(argc >= 3);
		char* path = argv[2];
		printf_free_space(path);
	}
	else if(!strcmp(argv[1], "get-cpu-name"))
		printf_cpu_name();
	else if(!strcmp(argv[1], "scan-all-ports"))
	{
		assert(argc >= 3);
		scan_proc_ports(argv[2]);
	}
	else
	{
		perror("No such method. Type \"help\" for all methods");
		return 1;
	}
	return 0;
}
