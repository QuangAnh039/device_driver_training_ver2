// Viết 1 chương trình C tạo ra 3 thread, các thread lần lượt được tăng 1 biến chung thêm một đơn vị và ghi giá trị mới vào 1 trong 2 file output. Sử dụng semaphore để đồng bộ việc ghi vào 2 file

//Viết 1 chương trình C tạo ra 2 thread, 2 thread đều ghi vào chung 1 file, sử dụng mutex để bảo vệ file, nên sử dụng wrapper function thay cho hàm ghi file thông thường.


#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h> 

static FILE *fp;

sem_t sem_fp;

void *myThreadFun(void *vargp) 
{
    sem_wait(&sem_fp); 

    printf("%ld\n", strlen(vargp));
    fwrite(vargp, 1, strlen(vargp), fp);
    
    sem_post(&sem_fp);

    return NULL; 
} 

int main() {
    pthread_t thread_id1, thread_id2;

    if((fp = fopen("file.txt" , "w+")) == NULL )
    {
        return -1;
    }

    sem_init(&sem_fp, 0, 2);

    pthread_create(&thread_id1, NULL, myThreadFun, "Quang Anh"); 
    pthread_create(&thread_id2, NULL, myThreadFun, "Quang Phuc"); 
    pthread_join(thread_id1, NULL); 
    pthread_join(thread_id2, NULL); 

    fclose(fp);
    sem_destroy(&sem_fp);
    return 0;
}