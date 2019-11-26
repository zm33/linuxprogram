#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include <sys/types.h>
#include <sys/wait.h>
void handler_sigint(int signo,siginfo_t *siginfo,void*pvoid)
{
        int *a;
        a=(int*)(siginfo->si_ptr);
       printf("recv SIGINT,the pointer data is %d\n",*a);
}
int main(int argc,char*argv[])
{
        pid_t pid;
         switch(pid=fork())
{
       case -1:
       printf("fork error\n");
       break;
       case 0:
{
      printf("child process is running\n");
      struct sigaction act;
       act.sa_sigaction=handler_sigint;
      act.sa_flags=SA_SIGINFO;
      sigaction(SIGINT,&act,NULL);
       pause();
         break;
}
      default:
{       union sigval value;
       int signum=SIGINT;
       int i,stat;
       value.sival_ptr=&signum;
      printf("parent process is running\n");
        int *a;
       a=(int *)value.sival_ptr;
        printf("In the father process,the pointer data is %d\n",*a);
          if(argc!=1&&argc!=3&&argc!=5)
{
         printf("./send_pointer\n");
         exit(1);
}
       for(i=1;i<argc;i++)
 {
        if(!strcmp(argv[i],"-s"))
  {
         signum=atoi(argv[i+1]);
       continue;
}
}
sleep(5);
       if(sigqueue(pid,signum,value) < 0)
{
     perror("sigqueue");
     exit(1);
}
     wait(&stat);
      break;
}
}
 return 0;
}
