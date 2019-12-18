#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<sys/time.h>
#include<signal.h>
#include<fcntl.h>
#include<pthread.h>
#include<limits.h>
#include<sys/syscall.h>
#include<semaphore.h>
#define LOOP 1000000
#define NUM 4
#define TN 100
