#include "my.h"
void init_daemon(void)
{
	
	pid_t p;
	int i;
	p=fork();
	if(p>0)
	exit(0);
	else if(p<0)
{
	perror("failed\n");
	exit(1);
}
	setsid();
	chdir("/tmp");
	umsk(0);
	for(i=0;i<NOFILE;i++)
{
	close(i);
}
}
