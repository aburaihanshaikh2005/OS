#include <stdio.h>

int main()
{
    int block[20], process[20];
    int allocation[20];
    int m, n, i, j, best;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of memory blocks:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of processes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    for(i = 0; i < n; i++)
    {
        best = -1;

        for(j = 0; j < m; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            block[best] = block[best] - process[i];
        }
    }

    printf("\nProcess\tProcess Size\tBlock\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("B%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
w
    return 0;
}
