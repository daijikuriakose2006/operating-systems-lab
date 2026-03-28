#include <stdio.h>

int main() {
    int n,i,j,completed=0,time=0;
    int at[10],bt[10],wt[10],tat[10],ct[10],pid[10];
    int visited[10]={0};
    printf("enterhe no of process: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("Enter AT and BT for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }
    while (completed<n){
        int min=999,index=-1;
        for(i=0;i<n;i++){
            if(at[i] < time &&visited[i]==0&&bt[i]<min){
                min=bt[i];
                index=i;
            }
        }
        if(index==-1){
            time++;
        }
        else{
            time+=bt[index];
            ct[index]=time;
            visited[index]=1;
            completed++;
        }
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("p\tAT\tBT\tCT\tWT\tTAT\n");
    float awt,atat;
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
        awt+=wt[i];
        atat+=tat[i];
    }
    printf("average WT: %.2f\n",awt/n);
    printf("average TAT: %.2f",atat/n);
    return 0;
}


// programiz: https://www.programiz.com/online-compiler/7cfYTID3PgJVh
