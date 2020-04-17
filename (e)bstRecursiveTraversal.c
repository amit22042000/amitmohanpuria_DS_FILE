#include<stdio.h>
#include<stdlib.h>
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
void createTree()
{   int t;
    printf("Enter root data:");
    scanf("%d",&t);
    root=createNode(t);
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
    }
}}
void traverseInorder(struct node* t)
{
    if(t->left!=NULL)
        traverseInorder(t->left);

    printf("%d",t->data);

    if(t->right!=NULL)
        traverseInorder(t->right);
}

void traversePreorder(struct node*t)
{
    printf("%d",t->data);

    if(t->left!=NULL)
        traversePreorder(t->left);

    if(t->right!=NULL)
        traversePreorder(t->right);
}
void traversePostorder(struct node*t)
{
    if(t->left!=NULL)
        traversePostorder(t->left);

    if(t->right!=NULL)
        traversePostorder(t->right);

    printf("%d",t->data);
}
void main()
{
    createTree();
    printf("Inorder:");
    traverseInorder(root);
    printf("\nPreorder:");
    traversePreorder(root);
    printf("\nPostorder:");
    traversePostorder(root);
}
