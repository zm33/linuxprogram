#include"my.h"

int g=10;
int main()
{
	int t=20;
	static int s=30;
	pid_t pid;
	pid=vfork();
	if(pid<0)
{
	perror("vfork failed");
	exit(-1);
}
	else if(pid==0)
{
	printf("before chlid pid=%d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
	g=100;
	t=200;
	s=300;
printf("after chlid pid=%d:g=%d,t=%d,s=%d\n",getpid(),g,t,s);
sleep(3);
_exit(0);
}

else
{
printf("parent pid=%d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
printf("parent pid=%d:g=%d,t=%d,s=%d\n",getpid(),g,t,s);
return 0;
}








}
