#include <stdio.h>
#include <unistd.h>

int main()
{
int a;
int fact=1;
int count=0;

//User Input
printf("Enter a Number: ");
scanf("%d",&a);

int arr[a];


int pid=fork();

if(pid==0)
{
printf("\nThe User Entered: %d \n",a);
}

else
{

//Calculation of factorial
for(int b=a; b>=1; b--)
{
fact=fact*b;
arr[count]=fact;
count++;
}

printf("Array: ");
//Printing of Array
for(int b=0; b<=a-2;b++)
{
printf("\t %d", arr[b]);
}

}

return 0;
}
