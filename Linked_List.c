
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;
NODEPTR list=NULL;
NODEPTR getnode()
{
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    return p;
}
freenode(NODEPTR p)
{
    free(p);
}
void Insbeg(int x)
{
    NODEPTR p;
    p=getnode();
    p->info=x;
    p->next=list;
    list=p;
}
Traverse()
{
    NODEPTR p=list;
    while(p!=NULL)
    {
        printf("\t%d",p->info);
        p=p->next;
    }
}
void Insaft(int x,int val)
{
    NODEPTR p,q;
    p=getnode();
    p=list;
    q=getnode();
    q->info=val;
    while(p->info!=x)
    {
        p=p->next;
    }
    q->next=p->next;
    p->next=q;
}
void Insend(int x)
{
    NODEPTR p=list;
    NODEPTR q;
    while((p->next)!=NULL)
    {
        p=p->next;
    }
    q=getnode();
    q->info=x;
    q->next=NULL;
    p->next=q;
}
int Delbeg()
{
    int x;
    NODEPTR p=list;
    list=p->next;
    x=p->info;
    freenode(p);
    return x;
}
int Delend()
{
    NODEPTR p=list,q;
    while((p->next)!=NULL)
    {
        q=p;
        p=p->next;
    }
    int x=p->info;
    freenode(p);
    q->next=NULL;
    return x;
}
int Delaft(int x)
{
    NODEPTR p,q;
    p=list;
    q=p->next;
    while((p->info)!=x)
    {
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    freenode(q);
    return x;
}
main()
{
    int ch,x,val;
    printf("\nEnter 1 for Insertion at Beginning of Linked list.");
    printf("\nEnter 2 for Traversal of Linked list.");
    printf("\nEnter 3 for Insertion after a particular node of Linked list.");
    printf("\nEnter 4 for Insertion at End of Linked list.");
    printf("\nEnter 5 for Deletion from Beginning of Linked list.");
    printf("\nEnter 6 for Deletion after a particular node of Linked list.");
    printf("\nEnter 7 for Deletion from end of Linked list.");
    printf("\n Enter any other key for EXIT.");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n Enter value u want to insert in beginning:");
                   scanf("%d",&x);
                    Insbeg(x);
                    break;
            case 2:Traverse();
                    break;
            case 3:printf("\nEnter value after which u want to insert a node:");
                   scanf("%d",&x);
                   printf("\nEnter value which you want to insert:");
                   scanf("%d",&val);
                    Insaft(x,val);
                    break;
            case 4:printf("\n Enter value want to insert in the end:");
                   scanf("%d",&x);
                    Insend(x);
                    break;
            case 5:Delbeg();
                    break;
            case 6:printf("\nEnter value after which u want to delete a node:");
                   scanf("%d",&x);
                   Delaft(x);
                   break;
            case 7:Delend();
                    break;
            default : exit(1);
        }
}    }
