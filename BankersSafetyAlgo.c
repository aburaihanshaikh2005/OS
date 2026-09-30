#include <stdio.h>
int main()
{
  int n,m;
  printf("Enter the number of Process:");
  scanf("%d",&n);
  
  printf("Enter the number of resources:");
  scanf("%d",&m);
  
  int allocation[n][m];
  int max[n][m];
  int need[n][m];
  int available[m];
  int work[m];
  int finish[n];
  int safeSequence[n];
  
  printf("\nEnter the allocation Matrix:\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      scanf("%d",&allocation[i][j]);
    }
  }
  printf("\nEnter the max Matrix:\n");
  for(int i =0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    { 
      scanf("%d",&max[i][j]);
    }
  }
  printf("\nEnter the available resources:\n");
  for(int j=0;j<m;j++)
  {
    scanf("%d",&available[j]);
  }
  
  //Calculating Need Matrix
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
     {
       need[i][j]=max[i][j]-allocation[i][j];
     }
  }
  
  for(int j=0;j<m;j++)
  { 
    work[j]=available[j];
  }
  
  for(int i=0;i<n;i++)
  {
    finish[i]=0;
  }
  
  int count=0;
  
  while(count<n)
  {
    int found=0;
    
    for(int i=0;i<n;i++)
    {
       if (finish[i] == 0) 
            {
                int canExecute = 1;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j]) 
                    {
                        canExecute = 0;
                        break;
                    }
                }
                if (canExecute)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = 1;
                    safeSequence[count] = i;
                    count++;
                    found = 1;
                }
            }
        }
        if(found==0)
        {
          break;
        }
}
    if (count == n) 
    {
        printf("\nSystem is in a SAFE state.\n");

        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++) 
        {
            printf("P%d", safeSequence[i]);

            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    }
    else
    {
      printf("\nSystem is in Unsafe State");
    }
    return 0;
}

      
