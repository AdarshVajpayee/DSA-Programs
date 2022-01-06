//infix to postfix expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stack_size 40

struct stack
{
    int items[stack_size],top;
};
typedef struct stack element;
void push(char item,element *s)
{
    if(s->top==stack_size-1)
    {
        printf("Overflow");
        return;
    }
    s->top++;
    s->items[s->top]=item;
}
char pop(element *s)
{
    char deleted;
    if(s->top==-1)
    {
        printf("Underflow");
        return;
    }
    else {
          deleted=s->items[s->top];
          s->top--;
          return deleted;
    }
}
int input(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '%':return 3;
        case '^':
        case '$':return 5;
        case '(':return 9;
        case ')':return 0;
        default:return 7;
    }
}
int stp(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '%':return 4;
        case '^':
        case '$':return 6;
        case '(':return 0;
        case '#':return -1;
        default:return 8;
    }
}
void infix_postfix(char infix[],char postfix[])
{
    element s;
    int i,j;
    char symbol;
    s.top=-1;
    push('#',&s);
    j=0;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        while(stp(s.items[s.top])>input(symbol))
        {
            postfix[j++]=pop(&s);
        }
        if(stp(s.items[s.top])!=input(symbol))
        {
            push(symbol,&s);
        }
        else{
            pop(&s);
        }
    }
    while(s.items[s.top]!='#')
    {
        postfix[j++]=pop(&s);
    }
    postfix[j++]='\0';
}
void main(){
    char infix[50],postfix[50];
    printf("Enter the infix expression: ");
    gets(infix);
    infix_postfix(infix,postfix);
    printf("postfix Expression is : %s",postfix);
    getchar();
}
