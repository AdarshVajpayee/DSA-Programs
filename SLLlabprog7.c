/*program : To design ,develop and implement a menu driven program in c for the following operations on Singly linked list on students Data with Fields : USN,NAME,BRANCH,SEM ,PHNO...................
(a.)Create a SLL of N students data by using front insertion.  
(b.)Display the status of the SLL and count the number of nodes in it.
(c.)Perform insertion and deletion operations at End of the SLL.
(d.)Perform insertion and deletion operations at from of the SLL.
(e.)Demonstrate how this SLL can be used as STACK and QUEUE.
(f.)EXIT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node //To create structure of students data
{
    int usn;
    char name[25],branch[25];
    int sem;
    unsigned long long phno;
    struct node *link;
};
typedef struct node *element;

element InsFront(element);
element InsEnd(element);
element DelFront(element);
element DelEnd(element);
void display(element);
element getnode();
element stack(element);
element queue(element);

void main(){
    element first =NULL;
    int opn,usn,sem,i,ch,n;
    long unsigned int phno;
    do{
        printf("\n\n###Singly Linked List Operations###");
        printf("\npress\n1-Creation of singly linked list with Front insertion");
        printf("\n2-display\n3-InsertEnd\n4-DeleteEnd\n");
        printf("\n5-InsertFront\n6-DeleteFront\n");
        printf("\n7-Stack Working\n8-Queue Working");
        printf("\n9-Exit\nENTER YOUR CHOICE ?");
        scanf("%d",&opn);
        switch(opn){
            case 1:printf("\n\nHow Many Nodes ?\n");
                   scanf("%d",&n);
                   for(i=0;i<n;i++){
                       first =InsFront(first);
                   }
                   printf("\nSingly Linked list with %d Nodes are ready to use",n);
                   break;
            case 2:printf("Linked List is \n");
                   display(first);
                   break;
            case 3:first =InsEnd(first); 
                   break;
            case 4:first =DelEnd(first); 
                   break;
            case 5:first =InsFront(first); 
                   break;
            case 6:first =DelFront(first); 
                   break;
            case 7:first =stack(first); 
                   break;
            case 8:first =queue(first); 
                   break;
            case 9:printf("\n\nTerminating\n\n");
                   break;
            default: printf("\n\nInvalid Option!!! Try Again!!!\n\n");
                    break;
        }
    }
    while(opn!=9);
    getch();
}
element getnode(){
    element x;
    x=(element)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Out of Memory");
        exit(0);
    }
    printf("\n\n Enter the Details : ");
    printf("\nUSN:");
    scanf("%d",&x->usn);
    printf("\nNAME:");
    scanf("%s",&x->name);
    printf("\nBRANCH:");
    scanf("%s",&x->branch);
    printf("\nSEM:");
    scanf("%d",&x->sem);
    printf("\nPH NO DETAILS:");
    scanf("%llu",&x->phno);
    x->link=NULL;
    return x;
}

element InsFront(element first){
       element temp;
       temp=getnode();
       temp->link=first;
       printf("NODE HAS BEEN INSERTED SUCCESSFULLY!!");
       return temp;
}

element InsEnd(element first){
       element temp,cur;
       temp =getnode();
       if(first == NULL)//
           return temp;//return new node as the first node
       else{
              cur=first;
              while(cur->link!=NULL){
                     cur=cur->link;
              }
              cur->link=temp;/*once cur ->link==NUll then new node has been inserted at the end (||||temp gets attached to last node of the prev present list)*/
              printf("NODE HAS BEEN INSERTED BACK SUCCESSFULLY!");
              return first;
       }
}

element DelFront(element first){
       element temp;
       int i=0;
       if(first == NULL){
              printf("\n Can't Delete !! List is empty ");
              return first;//we can also return NULL
       }
       temp=first;
       printf("\nDelete students node's details are \nUSN= %d\nNAME= %s\nBRANCH = %s\nSEM= %d\nPH NO. = %llu",first->usn,first->name,first->branch,first->sem,first->phno);
       first =first->link;
       free(temp);
       return first;
}

element DelEnd(element first){
       element cur,prev;
       if(first==NULL){//checking for empty list
              printf("\nCan't Delete !! List is empty");
              return first;
       }
       /*checking if only one node is present in the list ,if only one node is present them we free that node nothing but deletion operation............... */
       if(first->link==NULL){
             printf("\nDelete students node's details are \nUSN= %d\nNAME= %s\nBRANCH = %s\nSEM= %d\nPH NO. = %llu",first->usn,first->name,first->branch,first->sem,first->phno);
             free(first);
       return NULL;
       }
       prev=NULL;//previous means say list is present and before first node nothing is present so prev to that nodeis NULL
       cur=first;
       while(cur->link!=NULL){
              prev =cur;/*moves Along with cur and once cur->link will become NULL behind prev pointer is pointing to previous node of cur and we free cur later as deletion end operation, before freeing cur i.e last node we have to make prev->link=NULL so we use here a pointer " PREV "*/
              cur=cur->link;
       }
       printf("\nDelete students node's details are \nUSN= %d\nNAME= %s\nBRANCH = %s\nSEM= %d\nPH NO. = %llu",cur->usn,cur->name,cur->branch,cur->sem,cur->phno);
       prev->link=NULL;
       free(cur);
       return first;
}
void display(element first){
       element temp;
       if(first == NULL){
              printf("Empty List ");
       }
       else{
              temp=first;
              printf("START->");
              while (temp){
                     printf("[%d,%s,%s,%d,%llu]->",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
                     temp=temp->link;
              }
              printf("NULL\n");
       }
}
element stack(element first){
       int ch;
       while(1){
              printf("\n###STACK OPERATIONS###\nPress\n1-to-insert into stack\n2-to-delete an item \n3-Display\n4-Exit from Stack Operations\n Your choice ? : ");
              scanf("%d",&ch);
              switch(ch){
                     case 1:first=InsFront(first);
                            break;
                     case 2: first=DelFront(first);
                            break;
                     case 3:printf("\n The contest of the stacks is : "); 
                            display(first);
                            break;
                     case 4:return first;
              }
       }
}

element queue(element first){
       int ch;
       while(1){
              printf("\n###QUEUE OPERATIONS###\nPress\n1-to-Insert into Queue\n 2-to-delete an item \n3-Display\n4-Exit from Queue Operations\n Your choice ? : ");
              scanf("%d",&ch);
              switch(ch){
                     case 1:first=InsEnd(first);
                            break;
                     case 2: first=DelFront(first);
                            break;
                     case 3:printf("\n The contest of the Queue is : ");
                            display(first);
                            break;
                     case 4:return first;
              }
       }
}