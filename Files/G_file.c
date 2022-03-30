//program for counting the characters,blanks,tabs and lines in file.

#include <stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    char file_name[20];
    char ch;

    int char_count=0;
    int blank_count=0;
    int tab_count=0;
    int line_count=0;

    printf("Enter the file name : \n");
    scanf("%s",file_name);
    
    //open the file in read mode.
    if((fp=fopen(file_name,"r"))==NULL)
    {
        printf("Error in opening the file\n");
        exit(0);
    }

    //read each character till the end of the file.
    while((ch=getc(fp))!=EOF)
    {
        char_count++;
        if(ch == ' ') blank_count++;
        if(ch == '\n') line_count++;
        if(ch == '\t') tab_count++;
    }
    fclose(fp);

    printf("Number of characters = %d\n",char_count);
    printf("Number of tabs = %d\n",tab_count);
    printf("Number of lines = %d\n",line_count);
    printf("Number of blanks = %d\n",blank_count);
}
/*
Output :
Enter the file name : 
G_Count.txt
Number of characters = 200
Number of tabs = 0
Number of lines = 3
Number of blanks = 36
*/