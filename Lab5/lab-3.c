#include <stdio.h>
#include <unistd.h> // lib for fork
#include <sys/types.h> // used for pid_t data type
#include <sys/wait.h>

int main()
{
//int a =fork(); // we can use int in place of pid_t data type as well

pid_t pid;

pid=fork();
if (pid<0)
{
printf("Error");
}
else if(pid>0)
{
printf("Hello World from Parent process. ID is %d \n",pid);
wait(NULL); // waits for child process to complete
printf("After Parent Wait Command \n");
}
else
{
printf ("Hello World from Child Process, ID is %d \n",pid);
wait(NULL);
printf("After Child Wait Command \n");
}
return 0;
}
