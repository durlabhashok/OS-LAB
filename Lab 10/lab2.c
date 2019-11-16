#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define size 2048

struct sharedArea
{
int writtenData;
char text[size];
};

int main()
{
int running =1;
int *sharedMemory;
struct sharedArea *sharedStuff;
char buffer[BUFSIZ];
int shmid;
shmid = shmget((key_t)1234,sizeof(struct sharedArea),0666 |IPC_CREAT);
if(shmid == -1)
{
printf("failed\n");
exit(EXIT_FAILURE);
}
sharedMemory =shmat(shmid,0,0);
if(sharedMemory == (void *)-1)
{
printf("failed\n");
exit(EXIT_FAILURE);
}
printf("Memory attached at %ls\n",(int *)sharedMemory);
sharedStuff = (struct sharedArea *) sharedMemory;
while(running)
{
printf("sharedStuff->writtenData is %d",sharedStuff->writtenData);
while(sharedStuff->writtenData == 1)
{
sleep(1);
printf("waiting");
}
printf("Enter text");
fgets(buffer,BUFSIZ,stdin);
strcpy(sharedStuff->text,buffer);
sharedStuff->writtenData = 1;
if(strcmp(buffer,"end") == 0)
{
running =0;
}
}
shmdt(sharedMemory);
if(shmdt(sharedMemory) == -1)
{
printf("failed\n");
exit(EXIT_FAILURE);
}
shmctl(shmid,IPC_RMID,0);
exit(EXIT_SUCCESS);
return 0;
}
