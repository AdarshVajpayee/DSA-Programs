// Program to read a file of n integers from the file "Document.txt"

#include<stdio.h>

void main()
{
    FILE *in,*out;
    int a[10],n,i;
    char file_name[20];

    printf("Enter the name of the File: \n");
    scanf("%s",file_name);

    printf("Enter the Number of integers : \n");
    scanf("%d",&n);
    //if file Does not exists
    if((in=fopen("test.txt","r"))==NULL)
    {
        printf("Error in opening a File");
        return;
    }
    //if file exists read content from file
    for(i=0;i<n;i++)
    {
        fscanf(in,"%d",&a[i]);
    
    }
    fclose(in);

    out=fopen("output.txt","w");
    for(i=0;i<n;i++)
    {
        printf("%d\n", a[i]);
    }
    fclose(out);
}
