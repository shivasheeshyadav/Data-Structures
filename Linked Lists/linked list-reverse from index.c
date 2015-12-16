#include<stdio.h>
struct node
{
    int data;
    struct node *link;
};

main()
{
    struct node *p;
    p=NULL;

    insert(&p,1);
    insert(&p,2);
    insert(&p,3);
    insert(&p,5);
    insert(&p,6);
    insert(&p,7);

    display(&p);
    rev(p,2);


}

insert(struct node **q,int num)
{
    struct node *temp,*r;
    temp=*q;
    if(*q==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->data=num;
        temp->link=NULL;
        *q=temp;
    }
    else
    {
        temp=*q;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }

        r=malloc(sizeof(struct node));
        r->data=num;
        r->link=NULL;
        temp->link=r;
    }
}

display(struct node **q)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp=*q;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
    temp=temp->link;
    }
    printf("\n");
}

rev(struct node *q,int n)
{
    struct node *temp,*s,*a;
    temp=malloc(sizeof(struct node));
    s=malloc(sizeof(struct node));
    a=malloc(sizeof(struct node));
    temp=q;
    s=temp;
    a=s;
    int i=0;
    while(i<=n)
    {
        s=temp;
        temp=temp->link;
        ++i;
    }
    struct node *prev=NULL;
    struct node *current=temp;
    struct node *next;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;

    }
    temp=prev;
    s->link=temp;

    display(&a);
}

