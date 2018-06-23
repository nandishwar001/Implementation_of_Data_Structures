#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;

node* getnode()
{
    return (node*)malloc(sizeof(struct node));
}

node* makeNode(int x)
{
    node *p=getnode();
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void setLeft(node**p,int x)
{
    node *q=makeNode(x);
    (*p)->left=q;
}

void setRight(node **p,int x)
{
    node *q=makeNode(x);
    (*p)->right=q;
}

void CreateTree(node **p)
{
    int ch,x;
    node*q;
    printf("\nDoes left of %d exist(1/0)?",(*p)->data);
    scanf("%d",&ch);
    if(ch)
    {
        printf("\nEnter information of the node:");
        scanf("%d",&x);
        setLeft(p,x);
        CreateTree(&((*p)->left));
    }
    printf("\nDoes right of %d exist(1/0)?",(*p)->data);
    scanf("%d",&ch);
    if(ch)
    {
        printf("\nEnter information of the node:");
        scanf("%d",&x);
        setRight(p,x);
        CreateTree(&((*p)->right));
    }
}

void PreOrderTraversal(node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void InOrderTraversal(node *root)
{
    if(root!=NULL)
    {

        InOrderTraversal(root->left);
        printf("%d\t",root->data);
        InOrderTraversal(root->right);
    }
}

void PostOrderTraversal(node *root)
{
    if(root!=NULL)
    {

        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d\t",root->data);
    }
}

int countNodes(node *root)
{
    int count=0;
    if(root!=NULL)
    {
        count++;
        count+=countNodes(root->left);
        count+=countNodes(root->right);
    }
    return count;
}

int countLeafNodes(node *root)
{
    int count_leaf=0;
    if(root!=NULL)
    {
        if(root->left==NULL && root->right==NULL)
        count_leaf++;
        count_leaf+=countLeafNodes(root->left);
        count_leaf+=countLeafNodes(root->right);
    }
    return count_leaf;
}

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int height(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		return (1 + (max(height(root->left),height(root->right))));
	}
}

int isComplete(node* root)
{
	 if(pow(2,height(root))==countLeafNodes(root))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	node *root=NULL;
        int value;
        printf("Enter the information of the root node:");
        scanf("%d",&value);
        root=makeNode(value);
	CreateTree(&root);
	printf("\nPre Order Traversal = ");
	PreOrderTraversal(root);
	printf("\nIn Order Traversal = ");
	InOrderTraversal(root);
	printf("\nPost Order Traversal = ");
	PostOrderTraversal(root);
	printf("\nTotal Number of nodes=%d",countNodes(root));
	printf("\nTotal number of leaf nodes=%d",countLeafNodes(root));
	printf("\nHeight=%d",height(root));
	if(isComplete(root))
        printf("\nThe tree is COMPLETE BINARY TREE.");
	else
        printf("\nThe tree is INCOMPLETE BINARY TREE.");
     return 0;
}

