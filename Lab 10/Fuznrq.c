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
void *sharedMemory = (void *)0;
struct sharedArea *sharedStuff;
int shmid;
shmid= shmget((key_t)1234,sizeof(struct sharedArea),0666 |IPC_CREAT);
if(shmid == -1)
{
printf("failed\n");
exit(EXIT_FAILURE);
}
sharedMemory =shmat(shmid,(void *)0,0);
if(sharedMemory == (void *)-1)
{
printf("failed\n");
exit(EXIT_FAILURE);
}
printf("Memory attached at %ls\n",(int *)sharedMemory);
sharedStuff = (struct sharedArea *) sharedMemory;
while(running)
{
if(sharedStuff->writtenData == 1)
{
printf("entered data is %s",sharedStuff->text);
sleep(2);
sharedStuff->writtenData =0;
if(strcmp(sharedStuff->text,"end") == 0)
{
running =0;
}
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
