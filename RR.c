// Implement Round Robin CPU Scheduling Algorithm
#include <stdio.h>

#define MAX 20

int main()
{
    int n, i, tq;
    int bt[MAX], rem_bt[MAX];
    int wt[MAX], rt[MAX], tat[MAX], at[MAX], ct[MAX];
    int first_start[MAX];

    int time = 0, completed = 0;
    int found;

    float avg_wt=0,avg_tat=0,avg_rt=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter AT and BT for each process:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        rem_bt[i] = bt[i];
        wt[i] = 0;
        tat[i] = 0;
        ct[i] = 0;
        rt[i] = -1;
        first_start[i] = -1;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    if (tq <= 0)
    {
        printf("Time Quantum must be greater than 0.\n");
        return 1;
    }

   
    time = at[0];

    for (i = 1; i < n; i++)
    {
        if (at[i] < time)
        {
            time = at[i];
        }
    }

    
    while (completed < n)
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0 && at[i] <= time)
            {
                found = 1;

                
                if (first_start[i] == -1)
                {
                    first_start[i] = time;
                    rt[i] = first_start[i] - at[i];
                }
                if (rem_bt[i] > tq)
                {
                    time+=tq;
                    rem_bt[i]-=tq;
                }
                else
                {
                    time+=rem_bt[i];
                    rem_bt[i]=0;

                    ct[i]=time;
                    tat[i]=ct[i] - at[i];
                    wt[i]=tat[i] -bt[i];

                    completed++;
                }
            }
        }

       
        if (found == 0)
        {
            int next_at = 99999;
            for (i = 0; i < n; i++)
            {
                if (rem_bt[i] > 0 && at[i] > time)
                {
                    if (at[i] < next_at)
                    {
                        next_at = at[i];
                    }
                }
            }
            time = next_at;
        }
    }

    for (i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_rt += rt[i];
    }

    avg_wt /= n;
    avg_tat /= n;
    avg_rt /= n;
    printf("\nProcess\tAT\tBT\tWT\tTAT\tRT\tCT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,
               at[i],
               bt[i],
               wt[i],
               tat[i],
               rt[i],
               ct[i]);
    }

    printf("\nAverage WT  = %.2f", avg_wt);
    printf("\nAverage TAT = %.2f", avg_tat);
    printf("\nAverage RT  = %.2f\n", avg_rt);

    return 0;
}

