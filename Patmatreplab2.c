//if Pattern matched then replace 
#include <stdio.h>

void readstr(char *str, char *pat, char *rep)
{
    printf("Enter the string : ");
    gets(str);
    printf("Enter the pattern : ");
    gets(pat);
    printf("Enter the replacement pattern : ");
    gets(rep);
}
void patmatrep(char *str, char *pat, char *rep, char *ans) {
    int i,m,c,j,k,flag=0;
    i=m=c=j=k=0;
    while(str[c] != '\0') {
          if(str[m] == pat[i]) {
            i++;
            m++;
            if(pat[i] == '\0') {
                for(k=0;rep[k] !='\0'; k++,j++) {
                    ans[j] = rep[k];
                }
            i=0;c=m; flag=1;
            }
        }
        else {
            ans[j] = str[c];
            j++;c++; 
            m=c; i=0;
        }

    }
    ans[j] = '\0';
    if (flag == 0) {
    printf("Pattern not found");
}  
}
void main () {
    char str[20], pat[20], rep[20],ans[20];
    readstr(str,pat,rep);
    patmatrep(str,pat,rep,ans);
printf("Resultant string = %s\n", ans);
}