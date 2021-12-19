#include<stdlib.h> 
// standard library header
#include <stdio.h> 
// standard input output header
// create a linked list and perform all these oprations...
// Navneet code goes here...

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node
{
        int info;
        struct node *next;
};

struct node *start=NULL;
int main()
{
        int choice;
        while(1){

                printf("\n************** MENU **************\n");
                printf("\n 1.Create");
                printf("\n 2.Display");
                printf("\n 3.Insert at the beginning");
                printf("\n 4.Insert at the end");
                printf("\n 5.Insert at specified position");
                printf("\n 6.Delete from beginning");
                printf("\n 7.Delete from the end");
                printf("\n 8.Delete from specified position");
                printf("\n 9.Exit");
                printf("\n\n***********************************\n\n");
                printf(" Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: create(); break;
                        case 2: display(); break;
                        case 3: insert_begin(); break;
                        case 4: insert_end(); break;
                        case 5: insert_pos(); break;
                        case 6: delete_begin(); break;
                        case 7: delete_end(); break;
                        case 8: delete_pos(); break;
                        case 9: exit(0); break;
                        default: printf("n Wrong Choice:n"); break;
                }
        }
        return 0;
}

// To create a singly linked list...
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\n Out of Memory Space:\n");
                exit(0);
        }
        printf("\n Enter the data value for the node : ");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

//  To display the lists elements.
void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\n List is empty. \n");
                return;
        }
        else
        {
                ptr=start;
                printf("\n The List elements are : ");
                while(ptr!=NULL)
                {
                        printf("%d ",ptr->info );
                        ptr=ptr->next ;
                }
                printf("\n");
        }
}

// Insert at beginning of list...
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\n Out of Memory Space : \n ");
                return;
        }
        printf("\n Enter the data value for the node : " );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}

// insertion at the end of the list...
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\n Out of Memory Space : \n");
                return;
        }
        printf("\n Enter the data value for the node : " );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}

// Insertion at the perticular position of the list...
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\n Out of Memory Space : \n");
                return;
        }
        printf("\n Enter the position for the new node to be inserted : ");
        scanf("%d",&pos);
        printf("\n Enter the data value of the node : ");
        scanf("%d",&temp->info) ;

        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\n Position not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

// Deletion from beginning of the list...
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("\n List is Empty : \n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\n The deleted element is : %d ",ptr->info);
                free(ptr);
        }
}

// deletion from the end of the list...
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\n List is Empty : ");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("\n The deleted element is : %d ",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\n The deleted element is : %d ",ptr->info);
                free(ptr);
        }
}

// deletion from a perticular position of the list...
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\n The List is Empty : \n");
                exit(0);
        }
        else
        {
                printf("\n Enter the position(index value) of the node to be deleted : ");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\n The deleted element is : %d ",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\n Position not Found : \n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\n The deleted element is : %d ",ptr->info );
                        free(ptr);
                }
        }
}
