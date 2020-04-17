#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *prev;
struct node *next;
}*head=NULL;

struct node* createNode()
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newNode->data);
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void insertNode()
{
    if(head==NULL)
        head=createNode();

    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=createNode();
        temp->next->prev=temp;
    }
}
void createList()
{
    printf("Enter the size of the list:");
    int size;
    scanf("%d",&size);
    for(int i=0;i<size;i++)
        insertNode();
}
void deleteNode()
{
    printf("Enter the item to be deleted:");
    int item;
    scanf("%d",&item);
    if(head==NULL)
    {printf("Empty List");
    return;
    }
    struct node *temp=head;
    while(temp->data!=item)
        temp=temp->next;
    if(temp->next==NULL)
    {
        if(temp->prev==NULL)
            free(temp);
        else
        {
            temp->prev->next=NULL;
            free(temp);

        }

    }
    else if(temp->prev==NULL)
    {
        head=temp->next;
        head->prev=NULL;
        free(free);
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void main()
{
    createList();
    display();
    deleteNode();
    display();
}
