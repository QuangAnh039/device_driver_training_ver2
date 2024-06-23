//Đếm số lượng số lẻ từ 1 đến 100 tỷ. Code theo 2 trường hợp, trường hợp 1 sử dụng multithread, trường hợp 2 không sử dụng multithread. So sánh thời gian của 2 trường hợp

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

void *myThreadFun1(void *vargp1) 
{ 
    long long n1 = *(long long *)vargp1;
    for (long long i = 0; i < 25000000000; ++i) 
    {
        if(i % 2 != 0)
        {
            ++n1;
        }    
    }
    *(long long *)vargp1 = n1;
    return NULL; 
} 

void *myThreadFun2(void *vargp2) 
{ 
    long long n2 = *(long long *)vargp2;
    for (long long i = 25000000000; i < 50000000000; ++i) 
    {
        if(i % 2 != 0)
        {
            ++n2;
        }    
    }
    *(long long *)vargp2 = n2;
    return NULL; 
} 
void *myThreadFun3(void *vargp3) 
{ 
    long long n3 = *(long long *)vargp3;
    for (long long i = 50000000000; i < 75000000000; ++i) 
    {
        if(i % 2 != 0)
        {
            ++n3;
        }    
    }
    *(long long *)vargp3 = n3;
    return NULL; 
} 
void *myThreadFun4(void *vargp4) 
{ 
    long long n4 = *(long long *)vargp4;
    for (long long i = 75000000000; i < 100000000000; ++i) 
    {
        if(i % 2 != 0)
        {
            ++n4;
        }    
    }
    *(long long *)vargp4 = n4;
    return NULL; 
} 

int main() {
    pthread_t thread_id1, thread_id2, thread_id3, thread_id4;

    struct timeval start, end;
    long seconds, useconds;    
    double duration;
    long long count1 = 0;
    long long count2 = 0;
    long long count3 = 0;
    long long count4 = 0;

    gettimeofday(&start, NULL);

    pthread_create(&thread_id1, NULL, myThreadFun1, (void *)&count1); 
    pthread_create(&thread_id2, NULL, myThreadFun2, (void *)&count2); 
    pthread_create(&thread_id3, NULL, myThreadFun3, (void *)&count3); 
    pthread_create(&thread_id4, NULL, myThreadFun4, (void *)&count4); 

    pthread_join(thread_id1, NULL); 
    pthread_join(thread_id2, NULL); 
    pthread_join(thread_id3, NULL); 
    pthread_join(thread_id4, NULL); 

    gettimeofday(&end, NULL);

    
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    duration = seconds + useconds / 1.0e6;

    printf("number of so le: %lld\n", count1 + count2 + count3 + count4);
    printf("Time execute %f seconds\n", duration);

    return 0;
}
