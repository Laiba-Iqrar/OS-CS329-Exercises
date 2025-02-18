#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//When one thread executes the function the countr increments the value 0->1 
//this is the Shared resource
//Counter variable isin the L2 Cache (global)
//L1 cache is for different process
//Task is to increment the counter such that if there are two processes executing the coutner should be two
//mutex1  is the object
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;//declaration of mutex obj and inintialzation of mutex object
int counter = 0;
//run two options on mutex function : loc function 
//all the thread competing for the resource would call the lock function
// when the threads is done with the shared resource ; it has to unlock it .
void functionC (){
pthread_mutex_lock(&mutex1);
counter ++;
printf("Counter value: %d\n",counter);
pthread_mutex_unlock(&mutex1);}

main(){
int rc1, rc2;
pthread_t thread1, thread2;

if ((rc1=pthread_create(&thread1, NULL,&functionC,NULL)))
{
	printf("Thread Creation failed: %d\n",rc1);
	}

if ((rc2=pthread_create(&thread2, NULL,&functionC,NULL)))
{
	printf("Thread Creation failed: %d\n",rc2);
	}			
	
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
exit(0);}




