# Makefile template for a shared library in C

# tat ca cac options muon them vao khi build se duoc chua trong bien CFLAGS
# day la bien mac dinh cua Makefile
# CFLAGS += -fPIC -Wall -Wextra -g -fsanitize=address # C flags


all:
	gcc -c -g -fPIC buffer_over_flow.c -g -fsanitize=address
	gcc -shared buffer_over_flow.o -g -fsanitize=address -o libbuffer_over_flow.so

install:
	mkdir -p /usr/lib/over_flow_sample
	cp libbuffer_over_flow.so /usr/lib/over_flow_sample/libbuffer_over_flow.so

uninstall:
	rm -rf /usr/lib/over_flow_sample

clean:
	rm *.o *.so