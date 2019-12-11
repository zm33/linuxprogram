#include "my.h"
int arg=0;
void *foo(void *v)
{
	int n=(int)v,*sum,i;
	arg++;
sum=(int *)malloc(sizeof(int));
	printf("%d :global arg=%d\n",n,arg);
	for(i=0;i<(n+1);i++)
		*sum+=i;
	int arg;
	arg=n*100;
	printf("%d :local arg=%d,sum=%d\n",n,arg,*sum);
	pthread_exit((void *)sum);
}

int main()
{
	pthread_t tid[NUM];
	int rev[NUM],**pt;
	for(int i=0;i<NUM;i++)
{
	rev[i]=pthread_create(&tid[i],NULL,(void*(*)())foo,(void*)i);
	if(rev[i]!=0)
{
	perror("failed\n");
	exit -1;

}
	
	pthread_join(tid[i],(void **)&pt);
	printf("master %d: arg=%d,sum=%d\n",i,arg,*pt);
}
}






