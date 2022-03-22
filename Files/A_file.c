//program to write n integers into a  file.

#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    int a[10];
    int n,i;
    char file_name[20];

    printf("Enter the file_name\n");
    scanf("%s",file_name);

    printf("Enter the numbers of integers: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if((fp=fopen(file_name,"w"))==NULL)
    {
        printf("Error in opening file : \n");
        return;
    }
    fwrite(a,sizeof(int),n,fp);
    if(ferror(fp))
    {
        printf("Error in writing the file");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }
}
