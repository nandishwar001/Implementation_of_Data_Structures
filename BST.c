#include<stdio.h>
#include<malloc.h>

struct node
{
    int info ;
    struct node *left ;
    struct node *right ;
    struct node *father;
};
typedef struct node *NODEPTR ;

NODEPTR getnode()
{
    NODEPTR p ;
    p=(NODEPTR)malloc(sizeof(struct node)) ;
    return p ;
}

NODEPTR MakeNode(int x)
{
    NODEPTR q=getnode() ;
    q->info=x ;
    q->left=NULL ;
    q->right=NULL ;
    return q ;
}

void setleft(NODEPTR *p,int x)
{
    if((*p)->left!=NULL)
    {
        printf("Void insertion!!");
        return ;
    }
    NODEPTR q=getnode();
    q->info=x;
    q->left=NULL;
    q->right=NULL;
    (*p)->left=q;
    q->father=*p;
}

void setright(NODEPTR *p,int x)
{
    if((*p)->right!=NULL)
    {
        printf("Void insertion!!");
        return ;
    }
    NODEPTR q=getnode();
    q->info=x;
    q->left=NULL;
    q->right=NULL ;
    (*p)->right=q;
    q->father=*p;
}

void CreateTree(NODEPTR *p)
{
    int ch,x;
    NODEPTR q;
    printf("\nDoes left of %d exist(1/0)?",(*p)->info);
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter information of the node:");
        scanf("%d",&x);
        setleft(p,x);
        CreateTree(&((*p)->left));
    }
    printf("\nDoes right of %d exist(1/0)?",(*p)->info);
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter information of the node:");
        scanf("%d",&x);
        setright(p,x);
        CreateTree(&((*p)->right));
    }
}

void insert(NODEPTR *root, int x)
{
    NODEPTR p, q;
    p=*root;
    q=NULL;
    while(p!=NULL)
    {
        q=p;
        if(x<p->info)
            p=p->left;
        else
            p=p->right;
    }
    if(x<q->info)
        setleft(&q,x);
    else
        setright(&q,x);
}


NODEPTR bstmax(NODEPTR root)
{
    NODEPTR p;
    p=root;
    if(root==NULL)
        return NULL;
    else
    {
        while(p->right!=NULL)
        {
            p=p->right;
        }
        return p;
    }
}

NODEPTR bstmin(NODEPTR root)
{
    NODEPTR p;
    p=root;
    if(root==NULL)
        return NULL;
    else
    {
        while(p->left!=NULL)
        {
            p=p->left;
        }
        return p;
    }
}

NODEPTR bstsearch(NODEPTR root, int x)
{
    NODEPTR p;
    p=root;
    while(p!=NULL)
    {
        if(p->info==x)
            return p;
        else
        {
            if(x<p->info)
                p=p->left;
            else
                p=p->right;
        }
    }
    return NULL;
}

void InOrderTraversal(NODEPTR root)
{
    NODEPTR p;
    p=root;
    if(p!=NULL)
    {

        InOrderTraversal(p->left);
        printf("%d\t",p->info);
        InOrderTraversal(p->right);
    }
}

NODEPTR bst_predecessor(NODEPTR p)
{
    NODEPTR q;
    if(p==NULL)
        return NULL;
    else
    {
        if(p->left!=NULL)
            return bstmax(p->left);
        else
        {
            q=p->father;
            while(q->left==p && q!=NULL)
            {
                p=q;
                q=p->father;
            }
            return q;
        }
    }
}

NODEPTR bst_successor(NODEPTR p)
{
    NODEPTR q;
    if(p==NULL)
        return NULL;
    else
    {
        if(p->right!=NULL)
            return bstmin(p->right);
        else
        {
            q=p->father;
            while(q->right==p && q!=NULL)
            {
                p=q;
                q=p->father;
            }
            return q;
        }
    }
}

NODEPTR bst_delete(NODEPTR p,int key)
{
    NODEPTR q;
    if(p==NULL)
        return p;
    if(key<p->info)
        p->left=bst_delete(p->left,key);
    else if(key>p->info)
        p->right=bst_delete(p->right,key);
    else
    {
        if(p->left==NULL)
        {
            q=p->right;
            free(p);
            return q;
        }
        else if(p->right==NULL)
        {
            q=p->left;
            free(p);
            return q;
        }

        q=bstmin(p->right);
        p->info=q->info;
        p->right=bst_delete(p->right,q->info);
    }
    return p;
}

main()
{
    NODEPTR root;
    NODEPTR res,max,min,pre,succ;
    int max_value,min_value,pre_value,succ_value,choice;
    root=NULL ;
    int x,value,key,x1,x2,v;
    char ch;
    printf("Enter information of root node: ") ;
    scanf("%d",&x);
    root=MakeNode(x);
    printf("\nEnter 1 for Insertion in Binary Search Tree.");
    printf("\nEnter 2 for InOrder Traversal of Binary Search Tree.");
    printf("\nEnter 3 for Searching an element in a Binary Search Tree.");
    printf("\nEnter 4 for finding MINIMUM information in Binary Search Tree.");
    printf("\nEnter 5 for finding MAXIMUM information in Binary Search Tree");
    printf("\nEnter 6 for finding Logical Predecessor.");
    printf("\nEnter 7 for finding Logical Successor.");
    printf("\nEnter 8 for Deletion from a Binary Search Tree.");
    printf("\n Enter any other key for EXIT.");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateTree(&root);
                    break;
            case 2: printf("\nInOrder Traversal of BST is:\n");
                    InOrderTraversal(root);
                    break;
            case 3: printf("\nEnter element you want to search in a given Binary Search Tree:");
                    scanf("%d",&key);
                    res=bstsearch(root,key);
                    if(res!=NULL)
                    printf("\nElement exists in given Binary Search Tree.\n");
                    else
                    printf("\nUNSUCCESSFUL SEARCH.\n");
                    break;
            case 4: min=bstmin(root);
                    min_value=min->info;
                    printf("\nMinimum value is=%d",min_value);
                    break;
            case 5: max=bstmax(root);
                    max_value=max->info;
                    printf("\nMaximum value is=%d",max_value);
                    break;
            case 6: printf("\nEnter value whose predecessor you want to find:");
                    scanf("%d",&x1);
                    pre=bstsearch(root,x1);
                    if(pre==NULL)
                        printf("\nPredecessor of %d NOT exist.",x1);
                    else
                    {
                        pre=bst_predecessor(pre);
                        pre_value=pre->info;
                        printf("\nLogical Predecessor is=%d",pre_value);
                    }
                    break;
            case 7: printf("\nEnter value whose successor you want to find:");
                    scanf("%d",&x2);
                    succ=bstsearch(root,x2);
                    if(succ==NULL)
                        printf("\nSuccessor of %d NOT exist.",x2);
                    else
                    {
                        succ=bst_successor(succ);
                        succ_value=succ->info;
                        printf("\nLogical Successor is=%d",succ_value);
                    }
                    break;
            case 8: printf("\nEnter information of node that you want to delete from BST:");
                    scanf("%d",&v);
                    printf("\nDeletion of node from BST.");
                    root=bst_delete(root,v);
                    printf("\nIn Order Traversal of modified tree is:\n");
                    InOrderTraversal(root);
                    break;
            default : exit(1);
        }
    }
}

