#include <stdio.h>
#include <pthread.h>

#define SIZE 16
#define THREADS 4

int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int global_sum = 0;d
pthread_mutex_t mutex;

void* compute_sum(void* arg) {
    int index = *(int*)arg;
    int local_sum = 0;

    for (int i = index; i < SIZE; i += THREADS) {
        local_sum += array[i];
    }

    pthread_mutex_lock(&mutex);
    global_sum += local_sum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int indices[THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < THREADS; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, compute_sum, &indices[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Final Sum(Global): %d\n", global_sum);
    return 0;
}

