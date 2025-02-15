#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *computation (void *add);

int main(){
	pthread_t thread1 ,thread2 ;
	long value1 = 1;
	long value2 = 2;
	pthread_create ( &thread1, NULL,computation, (void*) &value1);
	pthread_join(thread1,NULL);	
	pthread_create ( &thread2, NULL,computation, (void*) &value2);
	

	pthread_join(thread1,NULL);
	
	return 0;}
	
	

void *computation (void *add){
	long sum = 0;
	long *add_num = (long *) (add);
	for (long i = 0; i <1000000; i++)
		sum += *add_num;
		
	printf("%ld \n",sum);
	return NULL;
	}
		

