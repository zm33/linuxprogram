#include "my.h"

void fun(void *arg)
{printf("thread is running.pid=%d\n",getpid());}

int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,(void *(*)())fun,NULL);
	if(ret!=0)
{
	perror("failed\n");
	return -1;
}
pthread_join(tid ,NULL);
	printf("%d:ALL DONE\n",getpid());
	return 0;
}
