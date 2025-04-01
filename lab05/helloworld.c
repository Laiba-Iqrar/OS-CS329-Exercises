#define  NUM_THREADS 8 //define the constant

char *messages[NUM_THREADS];//global char pointer .array of pointers
//Would the other function be able to access the content (string ) from that address ?Yes 

void *PrintHello(void* threadid)
{int taskid;
sleep(1);
taskid = (int)threadid;
printf("TThread %d: %s\n",taskid, messages[taskid]);
pthread_exit(NULL);
}



//ideally we should pass the int pointer type casted as void pointer , not type cast the i
int main (){

