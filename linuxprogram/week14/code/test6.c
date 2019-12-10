#include "my.h"

void *fun(void *arg)
{
//int TID=pthread_self();
int k=(int)arg;
printf("work-----%d:gettid pthread_self return %p\n",k,(void*)pthread_self());

pthread_exit(NULL);
return NULL;
}

int main()
{
	pthread_t tid[NUM];
	int ret[NUM],i;
	for(i=0;i<NUM;i++)
{
	ret[i]=pthread_create(&tid[i],NULL,fun,(void*)i);
	if(ret[i] !=0)
{
	perror("failed\n");
	return -1;
}
	printf("%d:ALL DONE\n",getpid());
	return 0;
}
}
