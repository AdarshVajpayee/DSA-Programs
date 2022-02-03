/*8. Design, Develop and Implement a menu driven Program in C for the following operations on Doubly 
Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation,Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit*/

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>

struct node
{
	int ssn;
	char name[20],dept[20],dsgn[20];
	double sal;
	unsigned long long phno;
  	struct node *llink;
  	struct node *rlink;
};
typedef struct node *element;

element getnode()
{
	element x;
	x=(element)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("out of memory\n");
		exit(0);
	}
	printf("\n Enter the details");
	printf("\n SSN : ");
	scanf("%d",&x->ssn);
	printf("\n NAME : ");
	scanf("%s",x->name);
	printf("\n DEPARTMENT : ");
	scanf("%s",x->dept);
	printf("\n DESIGNATION : ");
	scanf("%s",x->dsgn);
	printf("\n SALARY : ");
	scanf("%ld",&x->sal);
	printf("\n PHONE NUMBER : ");
	scanf("%llu",&x->phno);
	x->llink = x->rlink = NULL;
	return x;
}
	
//Function To End/Rear insert/

element insertend(element first)
{        
  	element temp, cur;
	
	/* Node to be inserted*/

   	temp=getnode();
	if(first==NULL)
		return temp;
   	cur=first;
	while(cur->rlink!=NULL) // obtain the address of last node
		cur=cur->rlink;
	cur->rlink=temp;
	temp->llink=cur;
	return first;
}

//Function To Front Insert/

element insertfront(element first)
{
    	element temp;
	temp=getnode();
	if(first==NULL)
		return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}

/* Delete a front node in DLL*/

element deletefront(element first)
{
	element prev, cur, next;
	if (first==NULL)
	{
		printf(" List is empty\n");
		return first;
	}
	cur=first;
	first=first->rlink;
	printf("\n The deleted node is : [%d , %s , %s , %s , %ld , ",cur->ssn,cur->name,cur->dept,cur->dsgn,cur->sal);
	printf(" %llu ] -> ",cur->phno);
	free(cur);
	return first;
}

//Function to Delete End
element deleteend(element first)
{
	element prev, cur, next;
	if (first==NULL)
	{
		printf(" List is empty\n");
		return first;
	}
	cur=first;
	while(cur->rlink!=NULL)
		cur=cur->rlink;
	
	prev=cur->llink;
	if(prev) // if not NULL
	  	prev->rlink=NULL;
	else
		first=NULL;
	printf("\n The deleted node is : [%d , %s , %s , %s , %ld , ",cur->ssn,cur->name,cur->dept,cur->dsgn,cur->sal);
	printf(" %llu ] -> ",cur->phno);
	free(cur);
	return first;
}

//Display the contents of the list/

void display(element first)
{
	element temp;
	int count=0;
	if (first==NULL)
	{
		printf(" List is empty\n");
		return;
	}

	printf("\nThe contents of the Doubly Linked list are\n");
	printf("\n START -> ");
	for(temp=first;temp!=NULL;temp=temp->rlink)
	{
		printf("[%d , %s , %s , %s , %ld , ",temp->ssn,temp->name,temp->dept,temp->dsgn,temp->sal);
		printf(" %llu ] -> ",temp->phno);
		count++;
	}
	printf(" END ");
	printf("\n The Number of nodes in the DLL is : %d",count);
}

void main()
{
    	element first=NULL;
	int choice,item,n,i;
	for(;;)
    	{
     		printf("\n ### Doubly Linked List Operations ### \n\n");
     		printf("\n Press\n  1-Creation with End Insertion");
     		printf("\n  2-Display");
     		printf("\n  3-Insert END\n  4-Delete END\n  5-Insert Front\n  6-Delete Front ");
     		printf("\n  7-DLL as Double Ended Queue");
     		printf("\n  8-Exit\n");
     		printf("\n  Your choice ? ");
     		scanf("%d",&choice);
     		switch(choice)
      		{
       			case 1: printf("\n\nHow Many Nodes ?");
	       		scanf("%d",&n);
	       		for(i=1;i<=n;i++)
	          			first= insertend(first);
	       		printf("\nDoubly Linked list with %d nodes is ready toUse!!\n",n);
	       		    break;  
       		    case 2: display(first);
		   	        break;
       		    case 3: first=insertend(first);
	       	        break;
	   		    case 4: first=deleteend(first);
		   	        break;
	   		    case 5: first=insertfront(first);
		   	        break;
	   		    case 6: first=deletefront(first); 
		   	        break;
	   		    case 7: printf("\n\n **Demonstration of DOUBLE ENDED QUEUE** ");
			             printf("\n --Insert front and delete rear--");
			            printf("\n\nHow Many Nodes ?");
			            scanf("%d",&n);
			            for(i=1;i<=n;i++)
			            	first = insertfront(first);
			            display(first);
			            while(first!=NULL)
			            {
			            	printf("\n Press any key to delete ");
			            	getch();
			            	first=deleteend(first);
			            }
			            printf("\n\n Press any key to see other ended queue \n");
			            getch();
			            printf("\n --Insert rear and delete front--");
			            printf("\n\nHow Many Nodes ?");
			            scanf("%d",&n);
			            for(i=1;i<=n;i++)
			            	first=insertend(first);
			            display(first);
			            while(first!=NULL)
			            {
			            	printf("\n Press any key to delete ");
			            	getch();
			            	first=deletefront(first);
			            }
			            break;
       		            	default: exit(0);
      		            }
      		printf("\n\n\n\n  Press a Key to Continue . . . ");
      
      	}
}