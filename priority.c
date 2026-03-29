#include <stdio.h>

int main() {
    int i,j,n,time=0,pid[10],ct[10];
    int bt[10],at[10],p[10],wt[10],tat[10],visited[10]={0};
    int completed=0;
    printf("Enter the no of process: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the AT and BT and P of proc%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&p[i]);
        pid[i]=i+1;
    }
    while(completed<n){
        int highest=999,index=-1;
        for(i=0;i<n;i++){
            if(at[i]<=time&&visited[i]==0&&p[i]<highest){
                highest=p[i];
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
    float awt=0,atat=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        awt+=wt[i];
        atat+=tat[i];
    }
    printf("P\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("Average WT: %.2f\n",awt/n);
    printf("Average TAT: %.2f\n",atat/n);
    return 0;
}

//programiz: https://www.programiz.com/online-compiler/0pu8lJVzzYyiO
