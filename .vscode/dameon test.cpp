#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<unistd.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>



#define MAXFILE 65535



int main()

{

int i,fd;

pid_t pid;

char *buf = "hello,dameon";

int len = strlen(buf);

//��һ���������ӽ���

pid = fork();

if(pid < 0)

{

printf("error\n");

exit(1);//�쳣�˳�

}

else if(pid > 0)

{

exit(0);

}

//�ڶ����������Ự

setsid();

//���������޸ĸ�Ŀ¼

chdir("/");

//���Ĳ�����������

umask(0);

for(i=0;i<MAXFILE;i++)

{ 
close(i);

}

while(1)

{

fd = open("/mnt/hgfs/H/C/dameon.log",O_CREAT|O_WRONLY,0600);

if(fd < 0)

{

perror("open");

exit(1);

}

write(fd,buf,len+1);

close(fd);

}

return 0;

}