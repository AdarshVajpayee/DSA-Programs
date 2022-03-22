//program to copy one file to other file using getc() and putc()

#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp1;          //points to input file
    FILE *fp2;          //points to output file
    char file_1[10];    //name of the input file
    char file_2[10];    //name of the output file
    int ch;             //used to store character read

    printf("Enter the input file \n");
    scanf("%s",file_1);

    //open the input file in read mode.
    if((fp1=fopen(file_1,"r"))==NULL)
    {
        printf("Opening input file failed\n");
        exit(0);
    }
    printf("Enter the output file\n");
    scanf("%s",file_2);
    
    //open the output file in write mode.

    fp2=fopen(file_2,"w");
    if(fp2==NULL)
    {
        printf("Opening output file failed\n");
        exit(0); 
    }
    //read untill the end of file (EOF) encountered.

    while((ch=getc(fp1))!=EOF)//read each character from input file 
    {
        putc(ch,fp2);    // and put it in output file.
    }
    printf("Check the output file u created u will get to know the contents of input file is pushed into outfile file..\n");
    //close both input and output files.
    fclose(fp1);
    fclose(fp2);
}