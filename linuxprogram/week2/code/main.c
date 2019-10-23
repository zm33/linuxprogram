#include "ourhdr.h"
char   buf1[] = "asdfghj";
char   buf2[] = "ASDFGHJ";

int main(void)
{
	int fd;
	if((fd=creat("file.hole",FILE_MODE))<o)
		err_sys("creat error");
		
	if(write(fd,buf1,10) !=10)
		err_sys("buf1 write error");

	if(lseek(fd,40,SEEK_SET) ==-1)
		err_sys("lseek error");

	if(write(fd,buf2 ,10)!=10)
		err_sys("buf2 write error");

	exit(0);
}
