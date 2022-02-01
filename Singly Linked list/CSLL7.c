//                             Program to implement Queues using circular singly linked list with Header node.

//Function to get a new node from the operating system.
//Function to insert at Rear end of the list.
//Function to delete an item from the front end of the list.
//Function to display the contents of the list.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

//Function to get a new node from the operating system.
NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

//Function to insert at Rear end of the list.
NODE Insert_Rear(int item,NODE head){
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    cur=head->link;
    while(cur->link!=head){
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}

//Function to delete an item from the front end of the list.
NODE Delete_Front(NODE head){
    NODE first;
    if(head->link==head){
        printf("List is empty\n");
        return head;
    }
    first=head->link;
    printf("Item to be deleted is %d\n",first->info);
    head->link=first->link;
    free(first);
    return head;
}
//Function to display the contents of the list.
void Display(NODE head){
    NODE temp;
    if(head->link==head){
        printf("List is empty\n");
        return;
    }
    printf("The contents of the list is\n");
    temp=head->link;
    while(temp!=head){
        printf("%d ",temp->info);
        temp=temp->link;
    }
    printf("\n");
}

void main(){
    NODE head;
    int choice,item;
    head=getnode();
    head->link=head;
    for(;;){
        printf("1.Insert_Rear  2.Delete_Front\n");
        printf("3.Display\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    head=Insert_Rear(item,head);
                    break;
            case 2:
                    head=Delete_Front(head);
                    break;
            case 3:
                    Display(head);
                    break;
            default:
                    exit(0);
        }
    }
}
/*
OUTPUT:

1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
1
Enter the item to be inserted
123
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
1
Enter the item to be inserted
420
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
1
Enter the item to be inserted
2000
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
3
The contents of the list is
123 420 2000
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
2
Item to be deleted is 123
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
2
Item to be deleted is 420
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
3
The contents of the list is
2000
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
2
Item to be deleted is 2000
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
3
List is empty
1.Insert_Rear  2.Delete_Front
3.Display
Enter the choice
4
*/