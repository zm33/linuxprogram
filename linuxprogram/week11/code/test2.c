#include "my.h"

int main()
{
	pid_t pid;
	int r ,status;
	pid=fork();
	if(pid<0)
	{
	perror("failed fork!\n");
	return -1;
	
}

	else if(pid==0)
{
	printf("child %d is running\n",getpid());
	printf("child will exit\n");
	//while(1);
	exit(120);
}
	else
{
	printf("parent waiting child %d to exit\n",pid);
	r=wait(&status);
	printf("child %d is finishied.return code =%d",r,WEXITSTATUS(status));
	printf("parent %d is running\n",getpid());
	return 0;
}



}
