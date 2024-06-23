//Đếm số lượng số lẻ từ 1 đến 100 tỷ. Code theo 2 trường hợp, trường hợp 1 sử dụng multithread, trường hợp 2 không sử dụng multithread. So sánh thời gian của 2 trường hợp

#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;
    long seconds, useconds;    
    double duration;
    long long count = 0;

    gettimeofday(&start, NULL);

    for (long long i = 0; i < 100000000000; ++i) 
    {
        if(i % 2 != 0)
        {
            count++;
        }    
    }

    
    gettimeofday(&end, NULL);

    
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    duration = seconds + useconds / 1.0e6;

    printf("number of so le: %lld\n", count);
    printf("Time execute %f seconds\n", duration);

    return 0;
}
