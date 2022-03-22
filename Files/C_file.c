//program to delete a file.
//try to delete a file by creating a file in same directory by specifying some name
#include<stdio.h>

void main()
{
    char file_name[20];
    int status;
    printf("enter the File_name: ");
    scanf("%s",file_name);

    status=remove(file_name);

    if(status!=0)
    {
        printf("Error : File cannot be deleted\n");
        return;
    }
    printf("The file %s is successfully deleted\n",file_name);
}

/*
syntax :int remove(char *file_name);
Output:
enter the File_name: C_delete.txt
The file C_delete.txt is successfully deleted
*/