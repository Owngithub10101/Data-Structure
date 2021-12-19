#include <stdio.h>
#include <stdlib.h>
int stack[100],i,j,choice=0,n,top=-1;
void Push();
void Pop();
void Display();
void main ()
{
    printf("\n****************** MAIN MENU ***************** \n");
    printf("\n\tStack operations using array \n");
    printf("\n==============================================\n");
    printf("Enter the number of elements in the stack : ");
    scanf("%d",&n);
    while(choice != 4)
    {
        printf("\nChose one from the below options.\n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                Push();
                break;
            }
            case 2:
            {
                Pop();
                break;
            }
            case 3:
            {
                Display();
                break;
            }
            case 4:
            {
                printf("Exiting...!");
                break;
            }
            default:
            {
                printf("Please Enter valid choice :  ");
            }
        };
    }
}

void Push ()
{
    int val;
    if (top == n )
    printf("\n Overflow");
    else
    {
        printf("Enter the value(?) : ");
        scanf("%d",&val);
        top = top +1;
        stack[top] = val;
    }
}

void Pop()
{
    if(top == -1)
    printf("Underflow");
    else
    top = top -1;
}

void Display()
{
    printf("Stack Elements are : ");
    for (i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    if(top == -1)
    {
        printf("Stack is empty.\n");
    }
}
