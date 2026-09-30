//Implement FCFS Algorithm
#include<stdio.h>
#define MAX 20
int main()
{
  int n,i,j,temp;
  int pid[MAX],at[MAX],bt[MAX],wt[MAX],ct[MAX],tat[MAX];
  int current_time=0;
  float avg_wt=0,avg_tat=0;
  printf("Enter the number of process:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    pid[i]=i+1;
    printf("Enter Arrival time for P%d:",pid[i]);
    scanf("%d",&at[i]);
    printf("Enter Burst time for P%d:",pid[i]);
    scanf("%d",&bt[i]);
  }
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
     if(at[i]>at[j])
     {
        temp=at[i];
        at[i]=at[j];
        at[j]=temp;
        
        temp=bt[i];
        bt[i]=bt[j];
        bt[j]=temp;
        
        temp=pid[i];
        pid[i]=pid[j];
        pid[j]=temp;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    if(current_time<at[i])
      current_time=at[i];
      
    ct[i]=current_time + bt[i];
    current_time=ct[i];
      
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
      
    avg_wt +=wt[i];
    avg_tat +=tat[i];
  }
  
  printf("n\PID\tAT\tBT\tCT\tTAT\tWT\n");
  for(i=0;i<n;i++)
  {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
  }
  printf("Average Waiting Time:%.2f",avg_wt/n);
  printf("Average Turn Around Time:%.2f",avg_tat/n);
  return 0;
}
  
 

  
