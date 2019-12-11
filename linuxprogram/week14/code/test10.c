#include "my.h"
void *foo(void * arg)
{
	printf("thread running\n");
	return(void*)0;
}
int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,foo,NULL);
	if(ret)
{
	perror("failed\n");
	exit (1);
}
	//pthread_join(tid,NULL);
	pthread_detach(tid);
	sleep(5);
	printf("Master done\n");
	return 0;
}
