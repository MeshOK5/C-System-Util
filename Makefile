system_mon: src/main.c src/process.c src/help.c src/system_info.c src/resource_use.c
	gcc src/main.c src/process.c src/help.c src/system_info.c src/resource_use.c src/port_scan.c -o /usr/bin/system-mon
