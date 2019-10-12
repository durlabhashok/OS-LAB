#include<stdio.h>
#include<fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{

//int fd= creat("samplefile.txt",0777);

int fd1=open("samplefile.txt",O_RDWR);

write(fd1,"hello",5);

close(fd1);
//printf("%d\n",fd1);


}
