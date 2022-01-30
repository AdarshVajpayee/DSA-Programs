//                                              Program to Implement multiple Stacks

//Function to get a new node from the operating systems.
//Function to insert an item at the front end of the list.
//Function to delete an item from the front end of the list.
//Function to display the contents of the list.

#include<stdio.h>
#include<stdlib.h>
#define MAX_STACKS 5

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

//Function to insert an item at the Front end of the list.
NODE Insert_Front(int item,NODE first){
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->link=first;
    return temp;
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
    NODE a[MAX_STACKS];
    int choice,item,i;
    for(i=0;i<MAX_STACKS;i++){
        a[i]=NULL;
    }
    for(;;){
        printf("Enter the Stack Number : 0, 1, 2, 3, 4 : ");
        scanf("%d",&i);
        printf("1.Push    2.Pop\n");
        printf("3.Display 4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    a[i]=Insert_Front(item,a[i]);
                    break;
            case 2: a[i]=Delete_Front(a[i]);
                    break;
            case 3: Display(a[i]);
                    break;
            default:exit(0);
        }
    }
}
/*
OUTPUT: 
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
12
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
24
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
36
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
3
36 24 12 
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
2
Item deleted = 36
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
2
Item deleted = 24
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
2
Item deleted = 12
Enter the Stack Number : 0, 1, 2, 3, 4 : 0
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
3
List is empty
Enter the Stack Number : 0, 1, 2, 3, 4 : 1
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
12
Enter the Stack Number : 0, 1, 2, 3, 4 : 1
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
3
12 
Enter the Stack Number : 0, 1, 2, 3, 4 : 1
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
2
Item deleted = 12
Enter the Stack Number : 0, 1, 2, 3, 4 : 1
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
3
List is empty
Enter the Stack Number : 0, 1, 2, 3, 4 : 4
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
2
List is empty cannot delete
Enter the Stack Number : 0, 1, 2, 3, 4 : 3
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
1
Enter the item to be inserted
1223
Enter the Stack Number : 0, 1, 2, 3, 4 : 3
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
2
Item deleted = 1223
Enter the Stack Number : 0, 1, 2, 3, 4 : 4
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
2
List is empty cannot delete
Enter the Stack Number : 0, 1, 2, 3, 4 : 4
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
3
List is empty
Enter the Stack Number : 0, 1, 2, 3, 4 : 4
1.Push    2.Pop
3.Display 4.Exit
Enter the choice
4
*/