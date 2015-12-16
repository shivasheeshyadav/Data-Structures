//LINKED LISTS-To find the reverse using reccusrion
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
    append(&p,4);
    append(&p,5);
    append(&p,8);
    append(&p,12);
    display(&p);
    printf("\n");

    reverse(&p);
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
    {
        temp=*q;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        {
            r=malloc(sizeof(struct node));
            r->data=num;
            r->link=NULL;
            temp->link=r;
        }
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


}

reverse(struct node **q)
{
 struct node *temp;
 temp=malloc(sizeof(struct node));
 temp=*q;
   rd(temp);
}
rd(struct node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {

        rd((temp)->link);
        printf("%d ",(temp)->data);
    }
}
