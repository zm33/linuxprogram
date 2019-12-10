#include "my.h"

void *fun(void *arg)
{
struct sendval * k=(struct sendval *)arg;
int i=0,sum=0;
for(i=0;i<k->s;i++)
	sum+=i;
printf("work-----%d:gettid pthread_self return %p\n",k,(void*)pthread_self());

pthread_exit(NULL);
return NULL;
}

int main()
{
	pthread_t tid[NUM];
	int ret[NUM],i;
	struct sendval d;
	for(i=0;i<NUM;i++)
{
	d.n=i;
	d.s=100*(i+1);
	ret[i]=pthread_create(&tid[i],NULL,fun,(void*)i);
	if(ret[i] !=0)
{
