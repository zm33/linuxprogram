#include"my.h"
int main()
{
	//ps aus
// /etc/rc.d
	FILE *fp;
	time_t t;
	init_daemon();
	while(1)
{
	sleep(5);
	if((fp=fopen("work.log","a+"))>=0)
{
	
	t=time(0);
	fprintf(fp,"daemon is running,append time is :%s,pid=%d\n",asctime(localtime(&t)));

}
}

}
