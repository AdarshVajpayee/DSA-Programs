//                                              Program to implement dequeues using doubly linked list.

//first try to write yourself all this functions ,then see the below program if required.
//Function to get a new node from the operating system .
//Function to Insert an item at the front end of the list.
//Function to Insert an item at the rear end of the list.
//Function to Delete an item from the front end of the list.
//Function to Delete an item from the Rear end of the list.
//Function to display the contents of the linked list.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

//Function to get a new node from the operating system .
NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

//Function to Insert an item at the front end of the list.
NODE Insert_Front(int item,NODE first){
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(first==NULL){
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

//Function to Insert an item at the rear end of the list.
NODE Insert_Rear(int item,NODE first){
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(first==NULL){
        return temp;
    }
    cur=first;
    while(cur->rlink!=NULL){
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    return first;
}

//Function to Delete an item from the front end of the list.
NODE Delete_Front(NODE first){
    NODE second;
    if(first==NULL){
        printf("List is Empty\n");
        return NULL;
    }
    if(first->rlink==NULL){
        printf("Item Deleted = %d\n",first->info);
        free(first);
        return NULL;
    }
    second=first->rlink;
    second->llink=NULL;
    printf("Item Deleted = %d\n",first->info);
    free(first);
    return second;
}

//Function to Delete an item from the Rear end of the list.
NODE Delete_Rear(NODE first){
    NODE prev,cur;
    if(first==NULL){
        printf("List is Empty\n");
        return NULL;
    }
    if(first->rlink==NULL){
        printf("Item Deleted = %d\n",first->info);
        free(first);
        return NULL;
    }
    cur=first;
    prev=NULL;
    while(cur->rlink!=NULL){
        prev=cur;
        cur=cur->rlink;
    }
    prev->rlink=NULL;
    printf("Item Deleted = %d\n",cur->info);
    free(cur);
    return first;
}

//Function to display the contents of the linked list.
void Display(NODE first){
    NODE cur;
    int count=0;
    if(first==NULL){
        printf("List is empty\n");
        return;
    }
    printf("The contents of the list:\n");
    cur=first;
    while(cur!=NULL){
        printf("%d ",cur->info);
        count++;
        cur=cur->rlink;
    }
    printf("\nNumber of nodes = %d\n",count);
}

void main(){
    NODE first;
    int choice,item;
    first=NULL;
    for(;;){
        printf("1.Insert_Front 2.Insert_Rear\n");
        printf("3.Delete_Front 4.Delete_Rear\n");
        printf("5.Display  6.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    first=Insert_Front(item,first);
                    break;
            case 2: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    first=Insert_Rear(item,first);
                    break;
            case 3: 
                    first=Delete_Front(first);
                    break;
            case 4: 
                    first=Delete_Rear(first);
                    break;
            case 5: Display(first);
                    break;
            default:
                    exit(0);
        }
    }
}
/*
OUTPUT:
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
1
Enter the item to be inserted
1000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
1
Enter the item to be inserted
2000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
3000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
4000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
5
The contents of the list:
2000 1000 3000 4000
Number of nodes = 4
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item Deleted = 2000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item Deleted = 4000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item Deleted = 1000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item Deleted = 3000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
List is Empty
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
List is Empty
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
5
List is empty
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
6
*/