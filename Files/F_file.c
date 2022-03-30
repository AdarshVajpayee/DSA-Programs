//c program to concatenate two files.

#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;

    char file1[20];
    char file2[20];
    char file3[20];
    char ch;

    printf("Enter the name of first file : ");
    scanf("%s",file1);
    //open the first file in read mode.
    if((fp1=fopen(file1,"r"))==NULL)
    {
        printf("Error in opening the file.\n");
        exit(0);
    }

    printf("Enter the name of second file : ");
    scanf("%s",file2);
    //open the second file in read mode.
    if((fp2=fopen(file2,"r"))==NULL)
    {
        printf("Error in opening the file.\n");
        fclose(fp1);
        exit(0);
    }

    printf("Enter the name of third file : ");
    scanf("%s",file3);
    //open the third file in write mode.
    if((fp3=fopen(file3,"w"))==NULL)
    {
        printf("Error in opening the file.\n");
        fclose(fp1);
        fclose(fp2);
        exit(0);
    }
    //input file copied to output file.
    while((ch=getc(fp1))!=EOF)
    {
        putc(ch,fp3);
    }

    //input file appended to output file.
    while((ch=getc(fp2))!=EOF)
    {
        putc(ch,fp3);
    }
    printf("Check your output file for the required output.\n");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}