//Linked Lists-To Delete a node when only its pointer is given
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
    display(&p);
    printf("\n");

    delnode(&p);
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

delnode(struct node **q)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp=(*q)->link;
    (*q)->data=temp->data;
    (*q)->link=temp->link;
    free(temp);
    return;
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
