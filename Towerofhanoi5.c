//tower of hanoi
#include<stdio.h>
#include<math.h>
void toh(int n,char source,char temp,char dest)//here n is no.of disks,temp is used to hold the 
{   
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",source,dest);
        return;
    }
        toh(n-1,source,dest,temp);//moving disk from source to temp
        printf("Move disk %d from %c to %c\n",n,source,dest);//moving nth disk from source to destination
        toh(n-1,temp,source,dest);//moving disk from temp to dest
}
void main(){
    int n,result;
    printf("Enter the no. of disk: ");
    scanf("%d",&n);
    result = pow(2,n);
    if(n<=2){
        printf("Enter the valid no. of disks ");
    }
    else{
        toh(n,'A','c','B');
    }
    printf("The no. of moves required %d",(result-1));
}
