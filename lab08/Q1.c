
#include <stdio.h>
#include <pthread.h>

#define SYNC_MAX_COUNT 3

int sync_count = 0;
pthread_mutex_t sync_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t sync_cond = PTHREAD_COND_INITIALIZER;

void SynchronizationPoint() {
    pthread_mutex_lock(&sync_lock);
    sync_count++;
    if (sync_count < SYNC_MAX_COUNT) {
        printf("Thread %ld waiting for synchronization point.\n", pthread_self());
        pthread_cond_wait(&sync_cond, &sync_lock);
    } else {
        printf("Thread %ld Reached synch point.\n", pthread_self());        
        pthread_cond_broadcast(&sync_cond);
    }
    pthread_mutex_unlock(&sync_lock);
}



int main() {
    pthread_t threads[3];

    pthread_create(&threads[0], NULL, SynchronizationPoint, (void *)1);
    pthread_create(&threads[1], NULL, SynchronizationPoint, (void *)2);
    pthread_create(&threads[2], NULL, SynchronizationPoint,NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
        
    }

    pthread_mutex_destroy(&sync_lock);
    pthread_cond_destroy(&sync_cond);

    return 0;
}
