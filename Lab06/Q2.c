#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define VECLEN 100000
#define NUM_THREADS 4

typedef struct {
    double *a;
    double *b;
    double sum;
    int veclen;
} DOTDATA;

DOTDATA dotstr;
pthread_t threads[NUM_THREADS];
pthread_mutex_t mutexsum;

void *dotprod(void *arg) {
    int i, start, end, offset;
    double mysum = 0.0;
    offset = *(int *)arg;
    start = offset * (dotstr.veclen / NUM_THREADS);
    end = start + (dotstr.veclen / NUM_THREADS);
    
    for (i = start; i < end; i++) {
        mysum += (dotstr.a[i] * dotstr.b[i]);
    }
    
    pthread_mutex_lock(&mutexsum);
    dotstr.sum += mysum;
    pthread_mutex_unlock(&mutexsum);
    
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int i, len;
    double *a, *b;
    int thread_args[NUM_THREADS];
    pthread_mutex_init(&mutexsum, NULL);
    
    len = VECLEN;
    a = (double *)malloc(len * sizeof(double));
    b = (double *)malloc(len * sizeof(double));
    
    for (i = 0; i < len; i++) {
        a[i] = 1.0;
        b[i] = a[i];
    }
    
    dotstr.veclen = len;
    dotstr.a = a;
    dotstr.b = b;
    dotstr.sum = 0.0;
    
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, dotprod, (void *)&thread_args[i]);
    }
    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Sum = %f \n", dotstr.sum);
    
    free(a);
    free(b);
    pthread_mutex_destroy(&mutexsum);
    
    return 0;
}

