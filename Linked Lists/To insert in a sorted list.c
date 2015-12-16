//Linked Lists-To insert in a sorted list
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
    append(&p,4);
    append(&p,5);
    append(&p,8);
    display(&p);
    printf("\n");
    insert(&p,3);
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


insert(struct node **q,int m)
{
    struct node *temp,*r;
    temp=malloc(sizeof(struct node));
    temp=*q;
    while(temp!=NULL)
    {
        if(temp->data<m&&m<temp->link->data)
        {
            r=malloc(sizeof(struct node));
            r->data=m;
            r->link=temp->link;
            temp->link=r;
            return;
        }
        else
        {
            temp=temp->link;
        }
    }
}
