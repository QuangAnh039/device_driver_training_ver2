# GDB

## 1. Install 
> sudo apt install -y gdb
> gdb --version

## 2. How to compile a program to use with gdb

- Build
> gcc -g -o binary src_code.c

- Includes:
	--> Start debugging
	--> Set breakpoints
	--> View source code
	--> Single-step debugging
	--> View variables
- How to run.
	
> gdb ./binary

> gdb
> file ./binary

## 3. Basic command line
- Set breakpoints.
> break [func_numb]
> break [func_name]

- Delete breakpoints
> delete [breakpoint_numb]

-View source at break point.
> list

- Run programm 
> run

- Run next command line.
> next [line_numb]
> next

- Run inside the function body.
> step

- Back to the top of the function
> return 

- Continue execution untill the next breakpoint or the end of program.
> continue

- Manipulating variables
> display [var_name]
> print [var_name]
> ptype [var_name]
> set variable [var_name] = [value]

## 4. Debug Coredumped
### 4.1 The problem

- Core Dump/Segment fault

### 4.2 Fixing core dumps
> ulimit -c unlimited
> gcc -g -o test src_coredumped.c
> ./test # generate core file 

> cat /proc/sys/kernel/core_pattern 
./core
> cat /proc/sys/kernel/core_uses_pid
0
> echo "1" > /proc/sys/kernel/core_uses_pid

> gdb test core


# Valgrind 

1. Use of unitialized memory
2. read/write freed memory blocks;
3. read/write memory blocks beyond malloc allocation
4. read/write inappropriate stacks memory block
5. memory leak, the pointer to a piece of memory is lost forever
6. incorrect malloc/free or new/delete match
7. the dst and src pointers in memcpy() related functions overlap

> sudo apt install -y valgrind 
> valgrind --leak-check=yes
> valgrind --tool=memcheck --leak-check=yes --show-reachable=yes
--num-callers=20 -- track-fds=yes ./test

- I have a leak but WHERE?
> gcc -o test src_memleak.c -Wall -ggdb3
> valgrind --leak-check=yes ./test

# Strace
sudo apt install -y strace 
1. Trace Linux Command System Calls
strace ls -l

2. Trace Linux Process PID
sudo strace -p 3569

3. Get Summary of Linux Process
sudo strace -c -p 3569

4. Print Instruction Pointer During System Call
sudo strace -i ls -l

5. Show Time of Day For Each Trace Output Line
sudo strace -t ls -l 

6. Print Command Time Spent in System Calls
sudo strace -T ls -l 

7. Trace Only Specific System Calls
sudo strace -e trace=write ls -l 

8. Trace System Calls based on a certain condition 
sudo strace -q -e trace=process ls -l
sudo strace -q -e trace=file ls -l 
sudo strace -q -e trace=memory ls -l 

9. Redirect Trace Output to File
sudo strace -o df_debug.txt ls -l 

10. Show some Debbuging Output of Strace
strace -d ls -l 