//Viết chương trình C tạo 2 thread, cả 2 thread lần lượt tăng biến đó lên 1 đơn vị, sử dụng mutex để đồng bộ việc ghi vào biến đó

#include <stdio.h>
#include <pthread.h>

int var1 = 0;
pthread_mutex_t var1_lock;

void *myThreadFun(void *vargp) 
{ 
    pthread_mutex_lock(&var1_lock);
    for(int i = 1; i <= 100000; i++)
    {
        var1++;
    }
    pthread_mutex_unlock(&var1_lock);
    return NULL; 
} 

int main() {
    pthread_t thread_id1, thread_id2;

    pthread_mutex_init(&var1_lock, NULL);


    pthread_create(&thread_id1, NULL, myThreadFun, NULL); 
    pthread_create(&thread_id2, NULL, myThreadFun, NULL); 
    pthread_join(thread_id1, NULL); 
    pthread_join(thread_id2, NULL); 

    printf("%d\n", var1);
    return 0;
}
