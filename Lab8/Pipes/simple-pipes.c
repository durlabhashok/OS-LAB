#include <stdio.h>
#include <unistd.h> // for pipes and forks
#include <string.h> // for strlen
#include <sys/wait.h>
int  main()
{

int a=fork();

int p[2]; pipe(p);


if (a>0)
{

wait(NULL);
char out[5];
printf("Hello");
read(p[0],out,5);

printf("%s",out);

}

else
{

char arr [5]="Alpha";


write(p[1], arr,5);


}


return 0;
}
