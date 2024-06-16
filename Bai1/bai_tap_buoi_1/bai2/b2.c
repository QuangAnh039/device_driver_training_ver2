#include <fcntl.h>  // for open
#include <unistd.h> // for read, close
#include <stdio.h>  // for printf
#include <stdlib.h> // for exit

void read_and_print_file(const char *file_path)
{
	int file = open(file_path, O_RDONLY);
    	if (file < 0) 
    	{
       		 printf("File at path %s not found or cannot be opened.\n", file_path);
        	return;
    	}
    	char buffer[1024];
    	ssize_t bytes_read;
   	 while ((bytes_read = read(file, buffer, sizeof(buffer) - 1)) > 0) 
   	 {
       		 buffer[bytes_read] = '\0';
       		 printf("%s", buffer);
   	 }


    	if(bytes_read < 0)
   	 {
		 printf("An error occurred while reading the file at path %s.\n", file_path);
 	 }
   	 close(file);
}

int main()
{
	const char *file_path = "./quanganh.txt";
	read_and_print_file(file_path);
	return 0;
}
