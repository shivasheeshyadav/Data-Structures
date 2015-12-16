//LINKED LISTS-To reverse a linked list
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
    display(&p);
    printf("\n");

    reverse(&p);
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


reverse(struct node **q)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp=*q;
    int i,count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    temp=*q;
    int k=count,j;
    for(i=1;i<=count;++i)
    {
    for(j=1;j<=k;++j)
    {
        if(j==k)
        {
            printf("%d ",temp->data);
            temp=*q;
            --k;
        }
        else
        {
            temp=temp->link;
        }
    }
    }
}
