#include <stdio.h>
#include <stdlib.h>

 struct node
 {
 int data;
 struct node* link;
 }*head=NULL;

 struct node* createNode()
 {
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data:");
  scanf("%d",&newNode->data);
  newNode->link=NULL;
  return newNode;
 }

 void insertNode()
 {
     if(head==NULL)
     {
         head=createNode();
     }
     else
     {
         struct node* temp=head;
         while(temp->link!=NULL)
            temp=temp->link;
         temp->link=createNode();
     }
 }
 void createList()
 {
     int size;
     printf("Enter the size of the list\n");
     scanf("%d",&size);
     for(int i=0;i<size;i++)
     {
         insertNode();
     }
 }
 void deleteLink(int item)
 {
     if(head==NULL)
        printf("List is Empty");
     if(head->data==item)
     {
         struct node* t=head;
         head=head->link;
         free(t);
     }
     else if(head->link->data==item)
     {
         struct node* t=head->link;
         head->link=head->link->link;
         free(t);
     }
     else
     {
         struct node* temp=head;
         {
             while(temp->link->data!=item)
                temp=temp->link;
             struct node* t=temp->link;
             temp->link=temp->link->link;
             free(t);
         }
     }
}
void display()
{   struct node* temp=head;
    while(temp!=NULL)
            {
                printf("%d\n",temp->data);
                temp=temp->link;
            }
}
void main()
{
    createList();
    printf("Enter item to be deleted:");
    int item;
    scanf("%d",&item);
    deleteLink(item);
    display();
}
