/*design, develop and implement a menu driven program in c
    1.create an array of n elements
    2.display of  array elements with suitable headings
    3.Inserting an element at the given valid position
    4.Deleting an elements at the given valid position
    5.exit */

#include <stdio.h>
#include <stdlib.h>

void Create_an_array(int a[],int n) {
    int i;
    for (i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
} 
void Display(int a[],int n) {
    int i;
    for (i=0;i<n;i++) {
        printf("%d\t",a[i]);
    }
}   
int insert_an_element(int item,int a[],int n,int pos) {
    int i;
    if(pos>n || pos<0){//when pos is greater than number of item
        printf("Invalid position");
        return n;//no insertion and return number of item 
    }
    for(i=n-1;i>=pos;i--){//create space for item at pos 
        a[i+1]=a[i];
    }
    a[pos]=item;//insert item at specified pos
    return n+1;//update number of items in array
}
int delete_at_pos(int a[],int n, int pos)
{
    int i;
    if(pos>=n || pos<0){
        printf("Invalid position");
        return n;//no insertion and return number of item 
    }
    printf("item deleted = %d\n",a[pos]);
    for(i=pos+1;i<n;i++){//move elements towards left
        a[i-1]=a[i];
    }
    return n-1;
}
void main(){
    int choice,a[20],n,item,pos;
    while(1){
        printf("\n1.Create an array\n2.Display\n3.insert\n4.delete\n5.exit\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the numbers of elements in array: ");
                scanf("%d",&n);
                printf("Enter %d elements\n",n);
                Create_an_array(a,n);
                break; 
            case 2:printf("The contents of the array are\n");
                   Display(a,n);
                   break;
            case 3:printf("Enter the item to be inserted : ");
                scanf("%d",&item);
                printf("Enter the position : ");
                scanf("%d",&pos);
                n=insert_an_element(item,a,n,pos);
                break;
            case 4:printf("Enter the position : ");
                scanf("%d",&pos);
                n=delete_at_pos(a,n,pos);
                break;
            default:
                 exit(0);
        }
    }
}
