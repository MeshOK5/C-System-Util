#include "includes.h"

void printf_process()
{
	DIR *dir;
	struct dirent *next;

	dir = opendir("/proc");
	
	char buffer[256];
	bool isNotEmpty = 0;

	char *path;

	if(dir)
	{
		while(next = readdir(dir))
		{
			for(int i = 0; i < strlen(next->d_name); i++)
			{
				if(!isdigit(next->d_name[i]))
					goto skip;
			}

			path = malloc((strlen("/proc/") + strlen(next->d_name) + strlen("/cmdline")));
			path[0] = '\0';
			path[1] = '\0';	

			strcat(path, "/proc/");
			strcat(path, next->d_name);
			strcat(path, "/cmdline");
			
			FILE *file = fopen(path, "r");
			if(file)
			{
				while(fgets(buffer, 256, file) != NULL)
				{
					printf("%s", buffer);
					isNotEmpty = 1;
				}

				if(isNotEmpty)
					printf(" - PID:%s\n", next->d_name);
				fclose(file);
				isNotEmpty = 0;
			}
			free(path);
			skip:
				continue;
		}
		closedir(dir);
	}
}

void kill_process(pid_t pid)
{
	kill(pid, SIGKILL);
}

void get_process_info(pid_t pid)
{
	char str_pid[15];
	sprintf(str_pid, "%d", pid);
	
	char* path = malloc((strlen("/proc/") + strlen(str_pid) + strlen("/status")) * sizeof(char));
	
	if(!path)
	{
		perror("Can't malloc memory");
		abort();
	}

	strcat(path, "/proc/");
	strcat(path, str_pid);
	strcat(path, "/status");	
	
	FILE* file = fopen(path, "r");

	if(!file)
	{
		perror("Can't open file");
		free(path);
		fclose(file);
		abort();
	}
	
	char buffer[256];

	while(fgets(buffer, 256, file) != NULL) printf("%s", buffer);
	
	fclose(file);
	free(path);
}
