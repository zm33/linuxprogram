#include "my.h"


int main()
{
	pthread_t tid;
	int i,pid;
	struct timeval tv1,tv2;
	 struct timezone tz;
	gettimeofday(&tv1,&tz);
	for(i=0;i<10000;i++)
{
	pid=fork();
{
		perror("create thread failed!\n");
		return -1;
}
}
gettimeofday(&tv2,&tz);
printf("running time is %ld\n",tv2.tv_usec-tv1.tv_usec);
return 0;
}
