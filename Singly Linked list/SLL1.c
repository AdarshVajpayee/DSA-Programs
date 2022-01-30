//                                      Program to perform various operation on Singly linked list

//Write a Function to get a new node from an operating system
//Write a Function to insert an item at the front end of the list
//Write a Function to find the length of the list
//Write a Function to Display
//Write a Function to search for an key element in list
//Write a Function to delete a node whose info field is specificed
//Write a Function to reverse a list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

//Function to get a new node from an operating system
NODE getnode(){
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("OUT OF MEMORY\n");
        exit(0);
    }
    return x;
}

//Function to insert an item at the front end of the list
NODE Insert_Front(int item,NODE first){
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    temp->link=first;
    return temp;
}

//Function to find the length of the list
int Length(NODE first){
    NODE cur;
    int count=0;
    if(first==NULL)
        return 0;
    cur=first;
    while(cur!=NULL){
        count++;
        cur=cur->link;
    }
    return count;
}

//Function to search for an key element in list
void Search(int key,NODE first){
    NODE cur;
    if(first==NULL){
        printf("List is empty\n");
        return;
    }
    cur=first;
    while(cur!=NULL){
        if(key==cur->info){
                 break;
        } 
        cur=cur->link;
    }
    if(cur==NULL){
        printf("Item not Found!! search is unsuccessful\n");
        return;
    }
    printf("Item Found !!Search is Successful\n");
}

//Function to delete a node whose info field is specificed
NODE Deleted_Info(int key,NODE first){
    NODE cur,prev;
    if(first==NULL){
        printf("List is empty\n");
        return NULL;
    }
    if(key==first->info){//if key is present in first node the save address of first in cur and make first to point to second node then delete cur 
        cur=first;
        first=first->link;
        free(cur);
        return first;
    }
    //Search for the node to be deleted
    prev=NULL;
    cur=first;
    while(cur!=NULL){
        if(key==cur->info){
            break;
        }
        prev=cur;
        cur=cur->link;
    }
    if(cur==NULL){
        printf("Search is unsuccessful Can't delete\n");
        return first;
    }
    //search is successful delete a node
    prev->link=cur->link;
    free(cur);
    return first;
}

//Function to reverse a list
/*design : Assume the given list is divided into two sub list such that the first list is reversed and second list has to be yet.
           1.Pointer varible cur always contains the address of the first node of partially reversed list.
           2.Pointer varible first always contain the address of the first node of the list to be reversed.
           */
NODE Reverse(NODE first){
    NODE cur,temp;
    cur=NULL;
    while(first!=NULL){
        temp=first->link;  // obtain the address of second node of the list to be reversed
        first->link=cur;   // Attach first node of the list to be reversed at the beginning of the partialy reversed list.
        cur=first;         // point cur to first and first to temp
        first=temp;
    }
    return cur;             //Contains the address of the reversed list
}

//function to display
void Display(NODE first){
    NODE cur;
    if(first==NULL){
        printf("List is empty\n");
        return;
    }
    printf("The Contents of the  singly linked list\n");
    cur=first;
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->link;
    }
    printf("\n");
}


void main(){
    NODE first;
    int choice,item,key,Res;
    first=NULL;

    while(1){
        printf("1.Insert Front\n2.Length of the list\n3.search\n4.Delete item\n5.Reverse\n6.Display\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the item to be inserted\n");
                   scanf("%d",&item);
                   first=Insert_Front(item,first);
                   break;
            case 2:printf("Length of the list = %d\n",Length(first));
                   break;
            case 3:printf("Enter the item to be searched\n");
                   scanf("%d",&key);
                   Search(key,first);
                   break;
            case 4:printf("Enter the item to be deleted\n");
                   scanf("%d",&key);
                   first=Deleted_Info(key,first);
                   break;
            case 5:first=Reverse(first);
                   break;
            case 6:Display(first);
                   break;
            default:
                    exit(0);
        }
    }
}
/*OUTPUT:
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
1
Enter the item to be inserted
12
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
1
Enter the item to be inserted
13
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
1
Enter the item to be inserted
24
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
1
Enter the item to be inserted
25
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
2
Length of the list = 4
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
3
Enter the item to be searched
25
Item Found !!Search is Successful
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
4
Enter the item to be deleted
25
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
6
The Contents of the  singly linked list
24 13 12
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
5
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
6
The Contents of the  singly linked list
12 13 24
1.Insert Front
2.Length of the list
3.search
4.Delete item
5.Reverse
6.Display
7.Exit
7
*/