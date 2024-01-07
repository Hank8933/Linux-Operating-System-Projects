# Linux Operating System Projects

This repository contains projects for the Fall 2023 Linux Operating System course.

-   **[Project 1](./Project%201/)**
    
    This project implements a new Linux system call to retrieve the physical address corresponding to a given virtual address. It utilizes a multi-threaded test program to observe and compare the memory layout of various variable types (e.g., global, local, heap) across different threads.

-   **[Project 2](./Project%202/)**
    
    This project involves creating a new system call, `my_set_process_priority`, to attempt to set a process's scheduling priority. The work includes modifying kernel scheduler structures (like `task_struct`) and conducting extensive tests under various CPU loads to analyze the impact of `static_prio` and `vruntime` on a process's actual execution time under the Completely Fair Scheduler (CFS).