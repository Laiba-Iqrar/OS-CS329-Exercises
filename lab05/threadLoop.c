#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* arg){
    char *message = (char*)arg;
    printf("%s\n",message);
    return NULL;
}

int main(){
    pthread_t threads[5];
    char *message = "Hello World";

    for (int i=0;i<5; i++){
        pthread_create(&threads[i], NULL,print_message, (void*)message);}

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);}

    return 0;
}
// #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* arg) {
    char *message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t threads[5];
    char *message = "Hello World";

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, print_message, (void*)message);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
// #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* arg) {
    char *message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t threads[5];
    char *message = "Hello World";

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, print_message, (void*)message);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;}

// Output:
//  Hello World
// Hello World
// Hello World
// Hello World
// Hello World