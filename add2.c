#include<stdio.h>
int main()
{
 int pid;
 printf("Enter a checking  number:");
 scanf("%d",&pid);
 fork();
 if(pid==0)
 {
 printf("Child Process creation successfully.");
 }
 else if(pid>0)
 {
 printf("Parent Process creation successfully.");
 }
 else
 {
 printf("Child process creation failed");
 }
 return 0;
 }
