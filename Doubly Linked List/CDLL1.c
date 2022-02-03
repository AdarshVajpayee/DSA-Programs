//                                       Program to implement dequeues using Circular doubly linked list.

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
NODE Insert_Front(int item,NODE first){
    NODE last,temp;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=temp;
    if(first==NULL){
        return temp;
    }
    last=first->llink;
    temp->rlink=first;
    first->llink=temp;
    last->rlink=temp;
    temp->llink=last;
    return temp;
}

//Function to Insert an item at the rear end of the list.
NODE Insert_Rear(int item,NODE first){
    NODE last,temp;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=temp;
    if(first==NULL){
        return temp;
    }
    last=first->llink;
    last->rlink=temp;
    temp->llink=last;
    first->llink=temp;
    temp->rlink=first;
    return first;
}

//Function to Delete an item from the front end of the list.
NODE Delete_Front(NODE first){
    NODE second,last;
    if(first==NULL){
        printf("List is empty Cannot delete\n");
        return NULL;
    }
    if(first->rlink==first){
        printf("Item deleted = %d\n",first->info);
        free(first);
        return NULL;
    }
    second=first->rlink;
    last=first->llink;
    second->llink=last;
    last->rlink=second;
    printf("Item deleted = %d\n",first->info);
    free(first);
    return second;
}
//Function to Delete an item from the Rear end of the list.
NODE Delete_Rear(NODE first){
    NODE last,prev;
    if(first==NULL){
        printf("List is empty Cannot delete\n");
        return NULL;
    }
    if(first->rlink==first){
        printf("Item deleted = %d\n",first->info);
        free(first);
        return NULL;
    }
    last=first->llink;
    prev=last->llink;
    prev->rlink=first;
    first->llink=prev;
    printf("Item deleted = %d\n",last->info);
    free(last);
    return first;
}

//Function to display the contents of the linked list.
void Display(NODE first){
    NODE cur,last;
    if(first==NULL){
        printf("List is empty\n");
        return;
    }
    printf("The contents of the linked list\n");
    cur=first;
    last=first->llink;
    while(cur!=last){
        printf("%d ",cur->info);
        cur=cur->rlink;
    }
    printf("%d ",cur->info);
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
10
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
1
Enter the item to be inserted
20
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
30
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
45
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
5
The contents of the linked list
20 10 30 45 1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item deleted = 20
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item deleted = 45
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item deleted = 10
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item deleted = 30
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice

3
List is empty Cannot delete
1.Insert_Front 2.Insert_Rear
3.Delete_Front 4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
List is empty Cannot delete
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