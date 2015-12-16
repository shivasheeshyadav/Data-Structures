//LINKED LISTS-Pairwise swap of a list.c
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
    append(&p,2);
    append(&p,8);
    append(&p,4);
    append(&p,5);
    append(&p,7);
    append(&p,10);
    //append(&p,11);
    display(&p);
    printf("\n");

    pswap(p);
    display(&p);
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


display(struct node **q)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    int i;temp=*q;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

pswap(struct node *q)
{
    while(q!=NULL&&q->link!=NULL)
    {
        swap(&q->data,&q->link->data);
        q=q->link->link;
    }
}

swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
