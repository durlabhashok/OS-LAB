#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int *a, *b;

int shmid = shmget(IPC_PRIVATE, 2*sizeof(int),0777|IPC_CREAT);

int pid=fork();

if(pid==0)
{
wait(NULL);
a=(int *) shmat(shmid,0,0);
printf("Child %d", a[0]);
shmdt(b);
}
else
{

b = (int *)shmat(shmid,0,0);
b[0]=5;
}

shmctl(shmid,IPC_RMID,0);

}
