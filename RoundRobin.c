#include <stdio.h>

int main() {
    int n, i, time = 0, remain;
    int at[10], bt[10], rt[10], ct[10], wt[10], tat[10], pid[10];
    int tq = 3;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("Enter AT and BT for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    remain = n;

    while(remain > 0) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                done = 0;

                if(rt[i] <= tq) {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    remain--;
                } else {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }

        if(done)
            time++;
    }

    float awt = 0, atat = 0;

    printf("\nProcess\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("P%d\t%d\t%d\n", pid[i], wt[i], tat[i]);

        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAWT = %.2f\nATAT = %.2f\n", awt/n, atat/n);

    return 0;
}

//https://www.programiz.com/online-compiler/0NTsSpKAzBsgF
