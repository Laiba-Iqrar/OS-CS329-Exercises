#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function that will be executed by each thread
void *print_message_function(void *ptr) {
    char *message = (char*)ptr;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;

    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    if (iret1 != 0) {
        printf("Error creating thread 1\n");
        exit(1);
    }
    if (iret2 != 0) {
        printf("Error creating thread 2\n");
        exit(1);
    }

    // Wait till threads are complete before main continues
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}


//Output :
// Thread 1 
// Thread 2 
// or :
// Thread 2
// Thread 1