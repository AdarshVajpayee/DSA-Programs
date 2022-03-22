//program to print size of the given file.
#include<stdio.h>
#include<process.h>

long file_size(FILE *fp)
{
    long length;
    fseek(fp,0L,2);
    length=ftell(fp);
    return length;
}

void main(){
    FILE *fp;
    char file_name[20];

    printf("Enter the file name\n");
    scanf("%s",file_name);

    fp=fopen(file_name,"r");

    if(fp==NULL)
    {
        printf("Error in opening a file\n");
        exit(0);
    }
    printf("Filesize of %s is %ld bytes \n",file_name,file_size(fp));
    fclose(fp);
}
/*output
Enter the file name
B_Fsize.txt
Filesize of B_Fsize.txt is 26 bytes 
*/

/*syntax to remember:
int fseek(FILE *fp,long offset,int start_point);
Function "fseek"  is used to set the position of the file Pointer Syntax:fseek(fp,offset,start_point);

long ftell(FILE *fp);
ftell gives the current position of the filepointer from the beginning of the file.
*/