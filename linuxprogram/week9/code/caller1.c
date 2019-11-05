#include "my.h"

int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("./test1 123 345 hello");
	printf("After calling!\n");
	sleep(100);
return 0;
}
