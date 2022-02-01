#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 5

void push(int item, int *top, int s[])
{
    if (*top == STACK_SIZE - 1)
    { //runs till the top points 4 when size is 5
        printf("Stack is full or overflow");
        return;
    }
    s[++(*top)] = item; //inserting the item into the stack, here first increment of top will take place as top points to -1 it will execute if statement else it will increment top and s[++top={0}]=item
}
int pop(int *top, int s[])
{
    int item_deleted; //used to hold the top most element of the stack
    if (*top == -1)
    {
        printf("Stack is empty or underflow");
        return 0;
    }
    // obtain the top most element and change position of the top
    item_deleted = s[(*top)--];
    return item_deleted;
}
void display(int top, int s[])
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    //Display contents of the Stack
    printf("The contents of the stack");
    for (i = 0; i <= top; i++)
    {
        printf("%d\n", s[i]);
    }
}
int palindrome(char str[])
{
    int i, top;
    char s[20], stk_item; //stack variables
    top = -1;
    for (i = 0; i < strlen(str); i++){
            s[++top] = str[i];
         }  
        for (i = 0; i < strlen(str); i++)
        {
            stk_item = s[top--];
            if (str[i] != stk_item)
                return 0;
            //the string or given number is not a palindrome
        }

        // printf("The reverse of the string is : %d\n",stk_item);
        return 1; //the string or given number is palindrome
    }

    void main()
    {
        int item, top, s[10]; //stack variables
        char str[20];         //used to check palindrome
        int choice, flag;
        top = -1; //indicates stack is empty are start with
        while (1)
        {
            printf("1.push 2.pop\n");
            printf("3.Display 4.palindrome\n");
            printf("5.exit\n");

            printf("Enter the choice\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter the item\n");
                scanf("%d", &item);
                push(item, &top, s);
                break;
            case 2:
                item = pop(&top, s);
                if (item == 0)
                    printf("Stack is empty\n");
                else
                    printf("Item deleted =%d\n", item);
                break;
            case 3:
                display(top, s);
                break;
            case 4:
                printf("Enter the string : ");
                scanf("%s", &str);
                flag = palindrome(str);
                if (flag == 0)
                    printf("The string %s is not palindrome",str);

                else
                    printf("The string  %s is palindrome",str);
            default:
                exit(0);
            }
        }
    }