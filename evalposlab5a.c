//Lab program 5a : Evaluation of postfix expression
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void push(int *s, int *top, int opnd)
{
    s[++(*top)] = opnd;
}
int pop(int *s, int *top) //this function gets call whenever the operator like (+,-,*,$,^,%) is found
{
    return (s[(*top)--]); //and when operator is found ,leads to removal of two operands from the stack eg: A=pop(s,&top) and B=pop(s,&top)
}
int power(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return (x * power(x, n - 1));
}
int evaluate(int A, int B, char sym)
{
    switch (sym)
    {
    case '+':
        return (B + A);
    case '-':
        return (B - A);
    case '*':
        return (B * A);
    case '/':
        if (A != 0)
            return (B / A);
        else
        {
            printf("Divide by zero error");
            exit(0);
        }
    case '%':
        return (B % A);
    case '^':
    case '$':
        return (power(B, A));
    }
}
void main()
{
    int s[100], A, B, i = 0;
    int top = -1; //initializing top to -1 to check the condition of Underflow
    int item, val;
    char p[50], sym;
    printf("Enter the postfix Expression : ");
    scanf("%s", p);
    while (p[i] != '\0')
    {
        sym = p[i++];
        if (isdigit(sym))
        {
            item = sym - '0'; //here is sym is of character type char-char=int eg:'A'-'0'
            push(s, &top, item);
        }
        else
        {
            A = pop(s, &top);
            B = pop(s, &top);
            val = evaluate(A, B, sym);
            push(s, &top, val);
        }
    }
    printf("Infix Result is : %d", s[top]);
    getchar();
}