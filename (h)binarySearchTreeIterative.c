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
void traverseInorder()
{
    int top=-1;
    struct node* arr[s];
    struct node* temp=root;
    while(1)
    {
        if(temp)
        {   arr[++top]=temp;
            temp=temp->left;
            continue;
        }
        if(top!=-1)
        {
            temp=arr[top]->right;
            printf("%d",arr[top--]->data);
            continue;
        }
        else
            break;
    }
}
int height(struct node* t)
{
    int lheight=0;
    int rheight=0;
    if(t->left)
    lheight=1+height(t->left);
    if(t->right)
    rheight=1+height(t->right);

    if(rheight>lheight)
        return rheight;
    else
        return lheight;
}
void main()
{
   createTree();
   traverseInorder();
   printf("\n%d",1+height(root));
}
