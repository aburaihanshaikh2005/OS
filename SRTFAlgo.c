//Implement SRTF Algorithm
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("Enter Arrival Time and Burst Time for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];  
    }

    int completed = 0;
    int current_time = 0;

    while (completed != n) {
        int shortest = -1;
        int min_remaining = 999999;

      
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time &&
                rt[i] > 0 &&
                rt[i] < min_remaining) {

                min_remaining = rt[i];
                shortest = i;
            }
        }

      
        if (shortest == -1) {
            current_time++;
            continue;
        }

        
        rt[shortest]--;
        current_time++;

     
        if (rt[shortest] == 0) {
            completed++;

            ct[shortest] = current_time;

          
            tat[shortest] = ct[shortest] - at[shortest];

           
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    float avg_tat = 0, avg_wt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i],
               ct[i], tat[i], wt[i]);

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time    = %.2f\n", avg_wt);

    return 0;
}
