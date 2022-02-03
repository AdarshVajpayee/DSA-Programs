//                          DOUBLE ENDED QUEUE USING CIRCULAR DOUBLY LINKED LIST WITH HEADER NODE.

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
    if(x==NULL){
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

//Function to Insert an item at the front end of the list.
NODE Insert_Front(int item,NODE head){
    NODE temp,first;
    temp=getnode();
    temp->info=item;
    first=head->rlink;
    temp->llink=head;
    head->rlink=temp;
    temp->rlink=first;
    first->llink=temp;
    return head;
}

//Function to Insert an item at the rear end of the list.
NODE Insert_Rear(int item,NODE head){
    NODE temp,last;
    temp=getnode();
    temp->info=item;
    last=head->llink;
    temp->llink=last;
    last->rlink=temp;
    head->llink=temp;
    temp->rlink=head;
    return head;
}

//Function to Delete an item from the front end of the list.
NODE Delete_Front(NODE head){
    NODE first,second;
    if(head->rlink==head){
        printf("Dequeue is empty\n");
        return head;
    }
    first=head->rlink;
    second=first->rlink;
    head->rlink=second;
    second->llink=head;
    printf("Item deleted = %d\n",first->info);
    free(first);
    return head;
}

//Function to Delete an item from the Rear end of the list.
NODE Delete_Rear(NODE head){
    NODE last,prev;
    if(head->rlink==head){
        printf("Dequeue is empty\n");
        return head;
    }
    last=head->llink;
    prev=last->llink;
    head->llink=prev;
    prev->rlink=head;
    printf("Item deleted = %d\n",last->info);
    free(last);
    return head;
}

//Function to display the contents of the linked list.
void Display(NODE head){
    NODE cur;
    if(head->rlink==head){
        printf("Dequeue is empty\n");
        return;
    }
    printf("The Contents of the list\n");
    cur=head->rlink;
    while(cur!=head){
        printf("%d\n",cur->info);
        cur=cur->rlink;
    }
}

void main(){
    NODE head;
    int choice,item;
    head=getnode();
    head->rlink=head->llink=head;
    for(;;){
        printf("1.Insert_Front 2.Insert_Rear\n");
        printf("3.Delete_Front 4.Delete_Rear\n");
        printf("5.Display  6.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    head=Insert_Front(item,head);
                    break;
            case 2: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    head=Insert_Rear(item,head);
                    break;
            case 3: 
                    head=Delete_Front(head);
                    break;
            case 4: 
                    head=Delete_Rear(head);
                    break;
            case 5: Display(head);
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
120
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
1
Enter the item to be inserted
200
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
1
Enter the item to be inserted
500
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
5000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
1000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
5
The Contents of the list
500
200
120
5000
1000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item deleted = 500
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item deleted = 1000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
100000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item deleted = 100000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item deleted = 200
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item deleted = 5000
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item deleted = 120
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Dequeue is empty
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Dequeue is empty
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
5
Dequeue is empty
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
6
*/