#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
struct stack
{
int item[MAXSIZE];
int top;
} s;
/***********************************/
void push ()
{
    int num;
    if(s.top==(MAXSIZE - 1))
    {
        printf("\n STACK OVERFLOWS.");
        exit(1);
    }
    else
    {
        printf ("\nEnter the element to be pushed\n");
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.item[s.top] = num;
    }
}
/*************************************/
int pop()
{
    int num;
    if (s.top==-1)
    {
        printf ("\n STACK UNDERFLOWS.");
        exit(1);
    }
    else
    {
        num = s.item[s.top];
        printf ("\n Poped element is = %d\n", s.item[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}
/*************************************/
void display()
{
    int i;
    if(s.top==-1)
    {
        printf ("\nStack is EMPTY.\n");
        exit(1);
    }
    else
    {
        printf ("\nThe status of the stack is\n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.item[i]);
        }
    }
    printf ("\n");
}
/***************************************/
int main()
{
    int ch;
    int option = 1;
    s.top = -1;
    printf ("STACK OPERATION\n");
    printf ("------------------------------------------\n");
    printf (" 1 --> PUSH \n");
    printf (" 2 --> POP \n");
    printf (" 3 --> DISPLAY \n");
    printf (" 4 --> EXIT \n");
    printf ("------------------------------------------\n");
    while (option)
    {
        printf ("Enter your choice\n");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: return;
        }
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf ("%d", &option);
    }
    return 0;
}
