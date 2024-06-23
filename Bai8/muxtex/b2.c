//Viết 1 chương trình C tạo ra 2 thread, 2 thread đều ghi vào chung 1 file, sử dụng mutex để bảo vệ file, nên sử dụng wrapper function thay cho hàm ghi file thông thường.


#include <stdio.h>
#include <pthread.h>
#include <string.h>


static FILE *fp;

pthread_mutex_t fp_lock;

void *myThreadFun(void *vargp) 
{
    pthread_mutex_lock(&fp_lock); 

    printf("%ld\n", strlen(vargp));
    fwrite(vargp, 1, strlen(vargp), fp);
    
    pthread_mutex_unlock(&fp_lock);

    return NULL; 
} 

int main() {
    pthread_t thread_id1, thread_id2;

    if((fp = fopen("file.txt" , "w+")) == NULL )
    {
        return -1;
    }

    pthread_mutex_init(&fp_lock, NULL);

    pthread_create(&thread_id1, NULL, myThreadFun, "Quang Anh"); 
    pthread_create(&thread_id2, NULL, myThreadFun, "Quang Phuc"); 
    pthread_join(thread_id1, NULL); 
    pthread_join(thread_id2, NULL); 

    fclose(fp);
    pthread_mutex_destroy(&fp_lock);
    return 0;
}