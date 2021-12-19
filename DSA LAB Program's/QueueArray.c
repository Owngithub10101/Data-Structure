#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
void Insert();
void Delete();
void Display();
int front = -1, rear = -1;
int queue[maxsize];
void main ()
{
    int choice;
    while(choice != 4)
    {
        printf("\n************************* Main Menu *****************************\n");
        printf("\n\t       Queue Operations Using Array  \n");
        printf("\n=================================================================\n");
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        printf("\nEnter your choice(?) : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            Insert();
            break;
            case 2:
            Delete();
            break;
            case 3:
            Display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nEnter valid choice(?) : ");
        }
    }
}

void Insert()
{
    int item;
    printf("\nEnter the element(?) : ");
    scanf("\n%d",&item);
    if(rear == maxsize-1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear+1;
    }
    queue[rear] = item;
    printf("\nValue Inserted.!");

}

void Delete()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        return;

    }
    else
    {
        item = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1 ;
        }
        else
        {
            front = front + 1;
        }
        printf("\nValue Deleted.!");
    }


}

void Display()
{
    int i;
    if(rear == -1)
    {
        printf("\nEmpty queue.!\n");
    }
    else
    {   printf("\nPrinting values are : ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
