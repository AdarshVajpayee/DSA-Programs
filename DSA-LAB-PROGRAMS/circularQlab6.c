//CIRCULAR QUEUE OPERATIONS : INSERT,DELETE,DEMONSTRATION OF OVERFLOW AND UNDERFLOW SITUATIONS,DISPLAY,EXIT

#include<stdio.h>
#include<stdlib.h>
#define size 5

void CQinsert(char *CQ,int f, int *r,char elem,int *count){
    if(*count ==size){
        printf("Overflow\n");
        return;
    }
    else{
        *r=((*r)+1)%size;/*since we assumed Q is circular so when rear is incremented by one when rear points to 4th means last elem and after further increment of rear ,rear=5 (overflow)thats why using modulus  we get 5%5=0;(instead of 5 it is 0)*/
        CQ[*r]=elem;
        (*count)++;
    }
}

int CQdelete(char *CQ,int *f,int *r,int *count){
    char elem;
    if(*count==0){
        printf("Underflow\n");
        return 1;
    }
    else{
        elem=CQ[*f];
        *f=((*f)+1)%size;
        (*count)--;
    }
    return elem;
}

void display(int *count,char *CQ,int f,int r){
    int i;
    if(*count==0){
        printf("Underflow \n");
        return ;
    }
    else{
        printf("Front[%d]->",f);
        for(i=f;i!=r;i=(i+1)%size){
            printf("%c\t",CQ[i]);
        }
    printf("%c",CQ[i]);
    printf("<-[%d]Rear",r);
    }
}

void main(){
    int choice,f=0,r=-1,count=0;
    char CQ[size],elem;
    while(1){
        printf("\nEnter the choice\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the element: ");
                   scanf(" %c",&elem);
                   CQinsert(CQ,f,&r,elem,&count);
                   break;
            case 2:elem=CQdelete(CQ,&f,&r,&count);
                   if(elem!=-1){
                       printf("Deleted= %c",elem);
                       break;
                   }
            case 3:display(&count,CQ,f,r);
                   break;
            case 4: exit(0);
        }
    }
}