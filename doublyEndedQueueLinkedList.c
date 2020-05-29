#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head=NULL,*last=NULL;

struct node* createNode()
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void enqueueFront()
{
    if(head==NULL)
    {
        head=createNode();
        last=head;
    }
    else
    {
        head->prev=createNode();
        head->prev->next=head;
        head=head->prev;
    }
}
void enqueueRear()
{
    if(head==NULL)
    {
        head=createNode();
        last=head;
    }
    else
    {
        last->next=createNode();
        last->next->prev=last;
        last=last->next;
    }
}
void dequeueFront()
{
    if(head==NULL)
        printf("Underflow");
    else if(head->next==NULL)
        free(head);
    else
    {
        struct node* temp=head;
        printf("Element removed = %d",temp->data);
        head=head->next;
        free(temp);
    }
}
void dequeueRear()
{
    if(last==NULL)
        printf("Underflow");
    else if(last->prev==NULL)
        free(last);
    else
    {
        struct node* temp=last;
        printf("Element removed = %d",temp->data);
        last=last->prev;
        free(last);
    }
}
void display()
{
    struct node* temp=head;
    while(temp)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void main()
{
     while(1)
    {
        int choice;
        printf("Enter a choice");
        scanf("%d",&choice);
        if(choice==1)
            enqueueFront();
        else if(choice==2)
            enqueueRear();
        else if(choice==3)
            dequeueFront();
        else if(choice==4)
            dequeueRear();
        else if(choice==5)
            display();
}}
