all : 
	gcc -c -Wall -Werror -fPIC mylib.c 
	gcc -shared -o libshared.so  mylib.o
	#gcc -L./ -Wl,-rpath=/usr/bin -Wall -o test build_dlib.c -lmylib
clean:
	rm *.so *.o