#include <stdio.h>
#include <stdlib.h>

#define size 5
int buffer[size];
int in=0,out=0;
int mutex=1,full=0,empty=size;
void producer(){
    int item;
    if(empty==0){
        printf("buffer is full\n");
    }
    else{
        mutex=0;
        item=full+1;
        buffer[in]=item;
        in=(in+1)%size;
        printf("producer produces the item %d\n",item);
        mutex=1,full++,empty--;
    }
}
void consumer(){
    int item;
    if(full==0){
        printf("buffer is empty\n");
    }
    else{
        mutex=0;
        item=buffer[out];
        out=(out+1)%size;
        printf("consumer consumes the item %d\n",item);
        mutex=1,full--,empty++;
    }
}
int main() {
    int choice;
    while(1){
        printf("1.producer\n2.consumer\n3.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting");
                return 0;
            default :
                printf("Invalid choice\n");
        }
    }
    return 0;
}



//programiz : https://www.programiz.com/online-compiler/1Tv9VFvSHW1de
