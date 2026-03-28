#include <stdio.h>

int main() {
    int n,i,j,temp;
    int at[10],bt[10],wt[10],tat[10],ct[10];
    printf("enter the no of process: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the AT and BT of p%d",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
    //sort the at
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp=at[i];
                at[i]=at[j];at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];bt[j]=temp;
            }
        }
    }
    //complition time
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++){
        if(at[i]>ct[i-1]){
            ct[i]=at[i]+bt[i];
        }
        else{
            ct[i]=ct[i-1]+bt[i];
        }
    }
    float atat=0,awt=0;
    printf("P\tWT\tTAT\n");
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        printf("%d\t%d\t%d\n",i+1,wt[i],tat[i]);
        atat+=tat[i];
        awt=wt[i];
        
    }
    printf("average WT= %d",awt/n);
    printf("average TAT= %d",atat/n);
    
    return 0;
}

// programiz: https://www.programiz.com/online-compiler/9Rca5RtZKCr7t
