#include "my.h"

void *fun(void *arg)
{
int TID=pthread_self();
printf("work-----%d:gettid return %d\n",TID,TID);
printf("work-----%d:gettid pthread_self return %p\n",TID,(void*)pthread_self());
printf("work-----%d:will exit\n",TID);
pthread_exit(NULL);
return NULL;
}

int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,fun,NULL);
	if(ret!=0)
{
	perror("failed\n");
	return -1;
}
pthread_join(tid ,NULL);

ret=pthread_create(&tid,NULL,fun,NULL);
	if(ret!=0)
{
	perror("failed\n");
	return -1;
}
pthread_join(tid ,NULL);

	printf("%d:ALL DONE\n",getpid());
	return 0;
}
