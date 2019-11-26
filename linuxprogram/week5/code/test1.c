#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

void main(){
    printf("parent running.\n");
    int res;
    char buf_wr[] = "9ijghjkk9988";
    char buf_rd[sizeof(buf_wr)];
    buf_rd[0] = '\0';
    int fd = open("/tmp/data.txt", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(fd < 0){
        printf("error: open file:/tmp/data.txt failed.\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    switch(pid){
        case 0:
            // 子进程
            printf("child process running.\n");
            res = write(fd, buf_wr, sizeof(buf_wr));
            if(res != sizeof(buf_wr)){
                printf("error: child process write failed.\n");
                exit(EXIT_FAILURE);
            }
            close(fd); // 子进程先关闭自己的文件描述符
            printf("child process done.\n");
            exit(0);
        case -1:
            // error
            exit(EXIT_FAILURE);
        default:
        	// 父进程
        	// 父进程等待子进程终止
            wait(0);
            //
			// 设置文件的‘读写位置’，使其偏移到子进程执行写入操作时的位置
			//
            lseek(fd, 0 - sizeof(buf_wr), SEEK_CUR);

            res = read(fd, buf_rd, sizeof(buf_wr));
            if(res == 0){
                // EOF
                printf("EOF\n");
            }else if(res > 0){
                printf("parent process done. readed string is '%s'\n", buf_rd);
            }else{
                // error
                printf("error: parent process read failed.\n");
                exit(EXIT_FAILURE);
            }
            close(fd);
            exit(EXIT_SUCCESS);
    }
}

