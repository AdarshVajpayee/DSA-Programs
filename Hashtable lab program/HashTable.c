/*
Given a file of 'n' employee Records with a set 'k' of keys (4-Digits) which uniquelly determine the records 
in a files[f].Assume that file is maintained in memory by hashtable of 'm' memory locations with 'L'
has the set of memory address (2-Digits) of locations in HashTable let the key in 'K' and address in 'L'
are integers .
Design and develop a program in c that uses hash Function H: K-->L has H(k)= Kmod(n) remainder method implement 
hashing Technique to map given Key(k) to the address place(L) Resolve resolving Collision (if any using Linear Probing).
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct record{
    int flag,usn;
    char name[20];
}rec[10];

int hash(int m)
{
    int slots=10;
    int r;
    r=m % slots;
    return r;
}

void main()
{
    int m,k,usn1,loc,n,j,i;
    char name1[20];
    FILE *in,*out;
    printf("Enter the Number of records\n ");
    scanf("%d",&n);
    in=fopen("input.txt","r");
    if(n<=10)
    {
        for(k=0;k<10;k++)
            rec[k].flag=0;
        for(i=0;i<n;i++)
        {
            fscanf(in,"%s %d",name1,&usn1);
            loc=hash(usn1);
            printf("\nAddress %d ",loc);
            if(rec[loc].flag==0)
            {
                strcpy(rec[loc].name,name1);
                rec[loc].usn=usn1;
                rec[loc].flag=1;
            }
            else
            {
                for(j=loc+1;j%10<10;j++)
                {
                    if(rec[j%10].flag==0)
                    {
                       strcpy(rec[j%10].name,name1);
                       rec[j%10].usn=usn1;
                       rec[j%10].flag=1; 
                       break;
                    }
                }
            }
        }
            fclose(in);
            printf("\nHashTable Content\n");
            for(i=0;i<10;i++)
            {
                if(rec[i].flag==1)
                    printf("\n %s %d",rec[i].name,rec[i].usn);
                else
                    printf("\n###");
            }
            out=fopen("Output.txt","w");
            for(i=0;i<10;i++)
            {
                if(rec[i].flag==0)
                    fprintf(out,"\n ###");
                else
                    fprintf(out,"\n %s %d",rec[i].name,rec[i].usn);
            }
        fclose(out);
    }
}
