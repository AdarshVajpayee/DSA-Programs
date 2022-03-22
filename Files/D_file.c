//Program to Rename a file.
#include<stdio.h>

void main()
{
    char old_file_name[20];
    char new_file_name[20];
    int status;

    printf("Enter the old file name : ");
    scanf("%s",old_file_name);
    printf("Enter the new file name : ");
    scanf("%s",new_file_name);

    status=rename(old_file_name,new_file_name);

    if(status!=0)
    {
        printf("Error : File cannot be removed\n");
        return;
    }
    printf("The file is successfully renamed.\n");

}
/*
output :
Enter the old file name : D_Rename.txt
Enter the new file name : D_frename.txt
The file is successfully renamed.
*/


/*
some important things to remember:->

syntax : int rename(char *old_file_name,char *new_file_name);
int getc(FILE *fp);
int putc(int ch,FILE *fp);
fprintf(fp,"format string",variable_list);
fscanf(fp,"Control string",variable_list);


value 0 on success.
non-zero on failure.

*/