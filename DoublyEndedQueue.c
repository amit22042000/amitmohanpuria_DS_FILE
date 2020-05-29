#include<stdio.h>
#include<stdlib.h>
int q[100];
int f=-1,r=-1,s=5;

void enqueueRear(int item)
{
    if(r==s-1)
        printf("Overflow\n");
    else
        q[++r]=item;
}
void enqueueFront(int item)
{
    if(f==-1)
        printf("Overflow\n");
    else
    {
        q[f--]=item;
    }
}
void dequeueFront()
{
    if(f==r)
        printf("Underflow\n");
    else
        printf("Deleted element is %d\n",q[++f]);
}
void dequeueRear()
{
    if(f==r)
        printf("Underflow\n");
    else
        printf("Deleted element is %d\n",q[r--]);
}
void display()
{
    for(int i=f+1;i<=r;i++)
    {
        printf("%d\n",q[i]);
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
        {
            int item;
            printf("Enter item:");
            scanf("%d",&item);
            enqueueFront(item);
        }
        else if(choice==2)
        {
            int item;
            printf("Enter item:");
            scanf("%d",&item);
            enqueueRear(item);
        }
        else if(choice==3)
        {
            dequeueFront();
        }
        else if(choice==4)
        {
            dequeueRear();
        }
        else if(choice==5)
            display();
}
}
