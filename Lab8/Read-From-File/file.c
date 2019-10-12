#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{

//int fd=creat("samplefile.txt",0777);
//close(fd);

int op=open("samplefile.txt",O_RDWR);
write(op,"helloWorld",10);
close(op);

char arr[12];
int fd1=open("samplefile.txt",O_RDONLY);

read(fd1,arr,strlen(arr));

printf("%s \n",arr);
close(fd1);


return 0;
}

