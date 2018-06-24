#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *node;
struct node *CLIST;
struct node *p;
struct node *q;
struct node *r;

node getnode()
{
    node p;
    p=(node)malloc(sizeof(struct node));
    return p;
}

freenode(node p)
{
    free(p);
}

void ins_beg()
{
    int ITEM;
    node p;
    p=getnode();
    printf("\nEnter the ITEM you wants to insert:\n");
    scanf("%d",&ITEM);
    if(CLIST==NULL)
    {
        p->info=ITEM;
        p->next=p;
        CLIST=p;
    }
    else
    {
        p->info=ITEM;
        p->next=CLIST->next;
        CLIST->next=p;
    }
}

void del_beg()
{
    int ITEM;
    node p;
    p=getnode();
    if(CLIST==NULL)
    {
        printf("\nCircular linked list UNDERFLOWS.");
        exit(1);
    }
    else
    {
        if(CLIST==CLIST->next)
        {
            q=CLIST;
            CLIST=NULL;
            printf("\n DELETED element is=%d",(q->info));
            freenode(q);
        }
        else
        {
            q=CLIST->next;
            CLIST->next=q->next;
             printf("\n DELETED element is=%d",(q->info));
            freenode(q);
        }
    }
}

void ins_end()
{
    node p;
    p=getnode();
    int ITEM;
    printf("\nEnter the ITEM to be inserted:\n");
    scanf("%d",&ITEM);
    p->info=ITEM;
    if(CLIST==NULL)
    {
        p->next=p;
        CLIST=p;
    }
    else
    {
        p->next=CLIST->next;
        CLIST->next=p;
        CLIST=p;
    }
}

void del_end()
{
    int ITEM;
    if(CLIST==NULL)
    {
        printf("\nUNDERFLOWS.");
        exit(1);
    }
    else
    {
        p=CLIST;
        q=CLIST->next;
        r=CLIST->next;
        while(q->next!=CLIST)
        {
            q=q->next;
        }
        q->next=r;
        if(CLIST==q->next)
        {
            CLIST=NULL;
        }
        else
        CLIST=q;
        printf("\n DELETED element is=%d",(p->info));
        freenode(p);
        q=NULL;

    }
}

traverse()
{
    q=CLIST;
    if(CLIST==NULL)
    {
        printf("\nCircular linked list is EMPTY.");
        exit(1);
    }
    else
    {
        q=q->next;
        while(q!=CLIST)
        {
            printf("%d\t",q->info);
            q=q->next;
        }
        if(q==CLIST)
        {
            printf("%d\t",q->info);
        }
    }
}

int main()
{
    int ch;
    printf("\nEnter 1 for Insertion at Beginning of Circular Linked list.");
    printf("\nEnter 2 for Deletion from Beginning of Circular Linked list.");
    printf("\nEnter 3 for Insertion at End of Circular Linked list.");
    printf("\nEnter 4 for Deletion from end of Circular Linked list.");
    printf("\nEnter 5 for Traversal of Circular Linked list.");
    printf("\n Enter any other key for EXIT.");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: ins_beg();
                    break;
            case 2: del_beg();
                    break;
            case 3: ins_end();
                    break;
            case 4: del_end();
                    break;
            case 5: traverse();
                    break;
            default: exit(1);

        }
    }
    return 0;
}
