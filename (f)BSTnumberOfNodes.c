#include<stdio.h>
#include<stdlib.h>
int s=0;
struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL;

struct node* createNode(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void createTree()
{   int t;
    printf("Enter root data:");
    scanf("%d",&t);
    root=createNode(t);
    s++;
    while(1)
   {
    printf("Enter the node data(-1 to terminate):");
    int data;
    scanf("%d",&data);
    if(data==-1)
        return;
    else
    {
        addNode(data,root);
        s++;
    }
}}
void addNode(int data,struct node* n)
{
    if(data>n->data)
    {
        if(n->right)
            addNode(data,n->right);
        else
            n->right=createNode(data);
    }
    else
    {
        if(n->left)
            addNode(data,n->left);
        else
            n->left=createNode(data);
    }
}
int countLeafNodes(struct node* t,int c)
{
    if(t->left)
    {
        c=countLeafNodes(t->left,c);
    }
    if(t->right)
    {
        c=countLeafNodes(t->right,c);
    }
    if(t->left==NULL && t->right==NULL)
    {
        c=c+1;
    }
    return c;
}
int countNonLeafNodes(struct node* t)
{
    if((t->right==NULL && t->left==NULL)|| t==NULL)
        return 0;
    else
        return (1+countNonLeafNodes(t->left)+ countNonLeafNodes(t->right));
}
void main()
{
   createTree();
   printf("number of leaf nodes:%d\n",countLeafNodes(root,0));
   printf("number of non leaf nodes:%d\n",countNonLeafNodes(root));
}
