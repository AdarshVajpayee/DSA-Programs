//                              program to remove duplicate items,find union and intersection of two list

//Function to get new node from the operating system.
//function to display the contents of the list.
//Function to insert an item at the rear end of the list.
//function to search for key in the list .
//Function to remove duplicates in the list.
//Function to find Union of the two list.
//Function to find Intersection of two list. 

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

//Function to get new node from the operating system.
NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Out of Memory\n");
        exit(0);
    }
    return x;
}

//function to display the contents of the list.
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

//Function to insert an item at the rear end of the list.
NODE Insert_Rear(int item,NODE first){
    NODE temp;
    NODE cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;

    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}
//function to search for key in the list .
int search(int key,NODE first){
    NODE cur;
    if(first==NULL)return 0;
    cur=first;
    while(cur!=NULL){
        if(key==cur->info)return 1;
        cur=cur->link;
    }
    return 0;
}

//Function to remove duplicates in the list.
NODE Remove_Duplicate(NODE first){
    NODE a,b;
    int flag;
    if(first==NULL)return NULL;//check for an empty list.
    b=NULL;                    //existing new list b.
    a=first;                   //existing list a.
    while(a!=NULL){            //traverse the entire list a.
        flag=search(a->info,b); //search for an item in list b.
        // if not found insert into new list.
        if(flag==0)b=Insert_Rear(a->info,b);
        a= a->link;             //Access next item in  the list
    }
    return b;
}

//Function to find Union of the two list.
NODE Union_of_list(NODE first,NODE second){
    NODE a,third;
    int flag;
    a=first;                            //Access first list using variable a.
    //Add all elements of first list to the end list .
    third=NULL;                         //initialize third list.
    while(a!=NULL){                     //Traverse till the end.
        third=Insert_Rear(a->info,third);  //insert till the end
        a=a->link;
    }
    //Search for each item of 2nd list in 3rd list.if not found add into 3rd list.
    a=second;                           //existing list.
    while(a!=NULL){                  //traverse entire second list
        flag=search(a->info,third);     //search for the item in the list b.
        //if not found insert into resultant list.
        if(flag==0)third=Insert_Rear(a->info,third);
        a=a->link;
    }
    return third;
}

//Function to find Intersection of two list. 
NODE Intersection_of_list(NODE first,NODE second){
    NODE a,b,third;
    int flag;
    a=first;
    b=second;
    third =NULL;
    while(a!=NULL){
        flag=search(a->info,b);
        if(flag==1)third=Insert_Rear(a->info,third);
        a=a->link;
    }
    return third;
}

void main(){
    NODE  first,second,third;
    int choice,item,i,n;
    for(;;){
        printf("1.Create First list    2.Create Second list\n");
        printf("3.Remove duplicates of the list 1    4.Remove duplicates of the list 2\n");
        printf("5.Union of Two lists   6.Intersection of Two lists\n");
        printf("7.Exit\n");
        printf("Enter your choice ?\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the numbers of nodes in first list\n");
                    scanf("%d",&n);
                    first=NULL;
                    for(i=0;i<n;i++){
                        printf("Enter the item \n");
                        scanf("%d",&item);
                        first=Insert_Rear(item,first);
                    }
                    break;
            case 2: printf("Enter the numbers of nodes in Second list\n");
                    scanf("%d",&n);
                    second=NULL;
                    for(i=0;i<n;i++){
                        printf("Enter the item \n");
                        scanf("%d",&item);
                        second=Insert_Rear(item,second);
                    }
                    break;
            case 3:printf("The first list before removing the duplicates\n");
                   Display(first);
                   first=Remove_Duplicate(first);
                   printf("The first list after removing duplicates\n");
                   Display(first);
                   break;
            case 4:printf("The Second list before removing the duplicates\n");
                   Display(second);
                   second=Remove_Duplicate(second);
                   printf("The second list after removing duplicates\n");
                   Display(second);
                   break;
            case 5:printf("The first list\n");
                   Display(first);
                   printf("The second list\n");
                   Display(second);
                   third=Union_of_list(first,second);
                   printf("The union of two list\n");
                   Display(third);
                   break;
            case 6:printf("The first list\n");
                   Display(first);
                   printf("The second list\n");
                   Display(second);
                   third=Intersection_of_list(first,second);
                   printf("The Intersection of two list\n");
                   Display(third);
                   break;
            default:exit(0);
        }
    }
}
/* OUTPUT :
1.Create First list    2.Create Second list
3.Remove duplicates of the list 1    4.Remove duplicates of the list 2
5.Union of Two lists   6.Intersection of Two lists
7.Exit
Enter your choice ?
1
Enter the numbers of nodes in first list
5
Enter the item 
10
Enter the item 
20
Enter the item 
20
Enter the item 
30
Enter the item 
100
1.Create First list    2.Create Second list
3.Remove duplicates of the list 1    4.Remove duplicates of the list 2
5.Union of Two lists   6.Intersection of Two lists
7.Exit
Enter your choice ?
2
Enter the numbers of nodes in Second list
5
Enter the item 
20
Enter the item 
150
Enter the item 
200
Enter the item 
20
Enter the item 
125
1.Create First list    2.Create Second list
3.Remove duplicates of the list 1    4.Remove duplicates of the list 2
5.Union of Two lists   6.Intersection of Two lists
7.Exit
Enter your choice ?
3
The first list before removing the duplicates
10 20 20 30 100
The first list after removing duplicates
10 20 30 100
1.Create First list    2.Create Second list
3.Remove duplicates of the list 1    4.Remove duplicates of the list 2
5.Union of Two lists   6.Intersection of Two lists
7.Exit
Enter your choice ?
4
The Second list before removing the duplicates
20 150 200 20 125
The second list after removing duplicates
20 150 200 125
1.Create First list    2.Create Second list
3.Remove duplicates of the list 1    4.Remove duplicates of the list 2
5.Union of Two lists   6.Intersection of Two lists
7.Exit
Enter your choice ?
5
The first list
10 20 30 100
The second list
20 150 200 125
The union of two list
10 20 30 100 150 200 125
1.Create First list    2.Create Second list
3.Remove duplicates of the list 1    4.Remove duplicates of the list 2
5.Union of Two lists   6.Intersection of Two lists
7.Exit
Enter your choice ?
6
The first list
10 20 30 100
The second list
20 150 200 125
The Intersection of two list
20
1.Create First list    2.Create Second list
3.Remove duplicates of the list 1    4.Remove duplicates of the list 2
5.Union of Two lists   6.Intersection of Two lists
7.Exit
Enter your choice ?
7
*/