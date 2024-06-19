#!/bin/bash

#compile with address sanitizer enabled and uses shared library
gcc -L/usr/lib/over_flow_sample -Wl,-rpath=/usr/lib/over_flow_sample -Wall -g -fsanitize=address -o test main.c -lbuffer_over_flow