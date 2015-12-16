//Circular Linked Lists
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
    append(&p,3);
    append(&p,4);
    append(&p,5);
    display(&p);


}

append(struct node **q,int num)
{
    struct node *temp,*r;
    temp=*q;
    if(*q==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->data=num;
        temp->link=temp;
        *q=temp;
    }
    else
    {
        temp=*q;
        while(temp->link!=*q)
        {
            temp=temp->link;
        }

        r=malloc(sizeof(struct node));
        r->data=num;
        r->link=*q;
        temp->link=r;
    }
}

display(struct node **q)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp=*q;
     if (*q != NULL)
    {
        // Keep printing nodes till we reach the first node again
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        while (temp != *q);
    }
    printf("\n");
}
