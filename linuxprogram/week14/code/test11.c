#include "my.h"

int run_now=1;
void *thread_function(void *arg){
int print_count2=0;
while(print_count2++<5)
{
	if(run_now==2){
	printf("function thread is running\n");
	run_now=1;
	}
	else{
	printf("function sleep\n");
	sleep(1);
	}
}
pthread_exit(NULL);

}

int main()
{
	int print_count1=0;
	pthread_t a_thread;
	if(pthread_create(&a_thread,NULL,thread_function,NULL)){
	perror("Thread failed");
	exit(1);
}
	while(print_count1++<5){
	if(run_now==1){
	printf("main thread is running\n");
	run_now=2;
}
	else{
	printf("main sleep\n");
	sleep(1);
}
}
pthread_join(a_thread,NULL);
exit(0);
}










