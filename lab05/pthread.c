#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//a thread can only take a void ptr as an argument . if i need to pass some other type I would type cast it to ptr
// char ptr message1 and message2  type casted as void ptr  IDEALlY
//taken two integers iret1 ,iret2 are the return values .
//pthread_t always has a return value 
//if the func successfully created thread : retturn value is 0
//if the func not  created thread : retturn value is 1

// Here I'm creating two threads
// thread1 ptr is passed first (&thread1)
//attribute of the thread  -> (NULL) my default threads are created joinable eans default attributes are used 
//by default : joinable
//Attribute includes : stack size , execution mexchanism , also if the  state of the thread  isto be created joinable or deteched 
//Joinable or detached helps us in synchronization  ie when you dont any process to succeed unless a particular thread is executed . you want to make an order .// whe

// we can take an array of threads if more threads are to be created

// thread1 should execute print_message_function 
// I'm passing the fourth argument as messagfe1 first typecasting it to pointer
//derefernece it and use it 
// inside a func you can type cast it as int and 
void *print_message_function(void *ptr) {
    char *message = (char *) ptr; // Typecast void pointer to char pointer
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2; // Thread identifiers
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2; // Return values for pthread_create

    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);
    
    pthread_join(thread1, NULL); //the first join ensures that main func is blocked unless thread1 fininshes
    pthread_join(thread2, NULL); // blocked until the thread2 finishes
    
    printf("Thread returns:%d\n", iret1);
    printf("Thread returns:%d\n", iret2);
    
    exit(0); // error free halting 
}

//FLow :
//main()//
//thread 1  first and thread2 then created
//as soon as it gets created it starts executing
//main wouldn't terminate unless both threads are executed : threads are inside the main function
//join makes sures no concurrency is there 

//In a Uniprocossor system , iti s bound to create the thread 
// thread1 and thread2 would be creeated concurrently ..
//join  facilites us in ordering
