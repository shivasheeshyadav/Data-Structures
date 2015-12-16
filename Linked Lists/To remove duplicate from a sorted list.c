//LINKED LISTS-To remove duplicate from a sorted list
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

    append(&p,1);
    append(&p,1);
    append(&p,1);
    append(&p,2);
    append(&p,4);
    append(&p,4);
    append(&p,5);
    append(&p,8);
    append(&p,8);

    display(p);
    printf("\n");

    rem(p);
    display(p);
    printf("\n");
}

append(struct node **q,int num)
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
    {   temp=*q;
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

rem(struct node *q)
{
    struct node *m;
    while(q->link!=NULL)
    {
       if(q->data==q->link->data)
       {
           m=q->link->link;
           free(q->link);
           q->link=m;
       }
       else
       {
            q=q->link;
       }

    }
}

display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->link;
    }
}
