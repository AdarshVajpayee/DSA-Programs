//                                              Program to Implement multiple queues

//Function to get a new node from the operating systems.
//Function to insert an item at the rear end of the list.
//Function to delete an item from the front end of the list.
//Function to display the contents of the list.

#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUES 5

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

//Function to get a new node from the operating systems.
NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("OUT OF MEMORY\n");
        exit(0);
    }
    return x;
}

//Function to insert an item at the rear end of the list.
NODE Insert_Rear(int item,NODE first){
    NODE temp;
    NODE cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)return temp;
    cur=first;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

//Function to delete an item from the front end of the list.
NODE Delete_Front(NODE first){
    NODE temp;
    if(first==NULL){
        printf("List is empty cannot delete\n");
        return NULL;
    }
    temp=first;
    first=first->link;
    printf("Item deleted = %d\n",temp->info);
    free(temp);
    return first;
}

//Function to display the contents of the list.
void Display(NODE first){
    NODE cur;
    if(first==NULL){
        printf("List is empty\n");
        return;
    }
    cur=first;
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->link;
    }
    printf("\n");
}

void main(){
    NODE a[MAX_QUEUES];
    int choice,item,i;
    for(i=0;i<MAX_QUEUES;i++){
        a[i]=NULL;
    }
    for(;;){
        printf("Enter the Queue Number : 0, 1, 2, 3, 4 : ");
        scanf("%d",&i);
        printf("1.Insert Rear  2.Delete Front\n");
        printf("3.Display 4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    a[i]=Insert_Rear(item,a[i]);
                    break;
            case 2:a[i]=Delete_Front(a[i]);
                        break;
            case 3:Display(a[i]);
                    break;
            default:exit(0);
        }
    }
}
/*
OUTPUT:
Enter the Queue Number : 0, 1, 2, 3, 4 : 1
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
12
Enter the Queue Number : 0, 1, 2, 3, 4 : 0
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
134
Enter the Queue Number : 0, 1, 2, 3, 4 : 2
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
24
Enter the Queue Number : 0, 1, 2, 3, 4 : 3
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
144
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
155
Enter the Queue Number : 0, 1, 2, 3, 4 : 1
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
196
Enter the Queue Number : 0, 1, 2, 3, 4 : 1
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
3
12 196 
Enter the Queue Number : 0, 1, 2, 3, 4 : 2
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
2000
Enter the Queue Number : 0, 1, 2, 3, 4 : 2
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
3
24 2000 
Enter the Queue Number : 0, 1, 2, 3, 4 : 2
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
2
Item deleted = 24
Enter the Queue Number : 0, 1, 2, 3, 4 : 2
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
2
Item deleted = 2000
Enter the Queue Number : 0, 1, 2, 3, 4 : 2
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
2
List is empty cannot delete
Enter the Queue Number : 0, 1, 2, 3, 4 : 2
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
3
List is empty
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
3
155 
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
125
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
3
155 125 
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
2
Item deleted = 155
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
2
Item deleted = 125
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
3
List is empty
Enter the Queue Number : 0, 1, 2, 3, 4 : 4
1.Insert Rear  2.Delete Front
3.Display 4.Exit
Enter the choice
4
*/