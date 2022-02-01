//                                      Program to implement dequeue using Circular Singly linked list

//Function to get a new node from the operating System.
//Function to insert an item at the Front end of the list.
//Function to insert an item at the Rear end of the list.
//Function to delete an item from the Front end.
//Function to delete an item from the Rear end.
//Function to display the contents of the Circular list.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

//Function to get a new node from the operating System.
NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

//Function to insert an item at the Front end of the list.
NODE Insert_Front(int item,NODE last){
    NODE temp;
    temp=getnode();
    temp->info=item;
    if(last==NULL)
    {
        last=temp;
    }
    else{
        temp->link=last->link;       //link last node to the first node.
    }
    last->link=temp;                 //link last node to first or temp node.
    return last;
}

//Function to insert an item at the Rear end of the list.
NODE Insert_Rear(int item,NODE last){
    NODE temp;
    temp=getnode();
    temp->info=item;
    if(last==NULL){
        last = temp;
    }
    else {
        temp->link=last->link;
    }
    last->link=temp;           //link last node to the new node.
    return temp;          
}

//Function to delete an item from the Front end.
NODE Delete_Front(NODE last){
    NODE first;
    if(last==NULL){
        printf("List is empty\n");
        return NULL;
    }
    if(last->link==last){             //delete if only one node is present
        printf("Item deleted is %d\n",last->info);
        free(last);
        return NULL;
    }
    //list contains more than one node.
    first=last->link;           //obtain node to be deleted.
    last->link=first->link;
    printf("Item Deleted is %d\n",first->info);
    free(first);
    return last;
}

//Function to delete an item from the Rear end.
// NODE Delete_Rear(NODE last){
//     NODE first,cur;
//     if(last==NULL){
//         printf("List is empty\n");
//         return NULL;
//     }
//     if(last->link==last){             //delete if only one node is present
//         printf("Item deleted is %d\n",last->info);
//         free(last);
//         return NULL;
//     }
//     first=last->link;
//     cur=first;
//     while(cur->link!=last){
//         cur=cur->link;
//     }
//     cur->link=first;
//     printf("Item deleted is %d\n",last->info);
//     free(last);
//     return cur;
// }

//Function to delete an item from the Rear end.
NODE Delete_Rear(NODE last){
    // NODE first,cur;
    NODE prev;
    if(last==NULL){
        printf("List is empty\n");
        return NULL;
    }
    if(last->link==last){             //delete if only one node is present
        printf("Item deleted is %d\n",last->info);
        free(last);
        return NULL;
    }
    // first=last->link;
    // cur=first;
    prev=last->link;
    while(prev->link!=last){
        prev = prev->link;
    }
    // cur->link=first;
    prev->link=last->link;
    printf("Item deleted is %d\n",last->info);
    free(last);
    return prev;
}

//Function to display the contents of the Circular list.
void Display(NODE last){
    NODE temp;
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Contents of the list is\n");
    temp=last->link;
    while(temp!=last){
        printf("%d ",temp->info);
        temp=temp->link;
    }
    printf("%d\n",temp->info);
}

void main(){
    NODE last;
    int choice,item;
    last=NULL;
    for(;;){
        printf("1.Insert_Front  2.Insert_Rear\n");
        printf("3.Delete_Front  4.Delete_Rear\n");
        printf("5.Display  6.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    last=Insert_Front(item,last);
                    break;
            case 2: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    last=Insert_Rear(item,last);
                    break;
            case 3:
                    last = Delete_Front(last);
                    break;
            case 4: 
                    last = Delete_Rear(last);
                    break;
            case 5:
                    Display(last);
                    break;
            default:
                    exit(0);
        }
    }
}
/*OUTPUT:
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
1
Enter the item to be inserted
123
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
1
Enter the item to be inserted
2345
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
2
Enter the item to be inserted
5000
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item Deleted is 2345
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
4
Item deleted is 5000
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
3
Item deleted is 123
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
5
List is empty
1.Insert_Front  2.Insert_Rear
3.Delete_Front  4.Delete_Rear
5.Display  6.Exit
Enter the choice
6
*/