# About
Simple util to print some system info for Linux

# How to build
First, be sure that you have all of packages:

| **gcc compiler**      |
| **make build system** |
| **sudo**              |

Then download repository:

```sh
git clone https://github.com/MeshOK5/C-System-Util
```

Go to directory and type:

```sh
sudo make
```

Now you can get description about all method by typing:

```sh
system-mon help
```

# Usage

| Method                             | Description                                |
| :--------------------------------- | :----------------------------------------- |
| **system-mon get-proc**            | Get all running processes                  |
| **system-mon kill-proc -PID-**     | Kill process by PID                        |
| **system-mon memory-usage**        | Get RAM usage                              |
| **system-mon cpu-usage**           | Get CPU usage                              |
| **system-mon get-proc-info -PID-** | Get all process information by PID         |
| **system-mon get-disk-info -PATH** | Get free space of path directory           |
| **system-mon get-cpu-name**        | Get name of your CPU                       |
| **system-mon get-os-name**         | Get name of your operating system          |
