//LINKED LISTS-To remove duplicate from unsorted list
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

   /* append(&p,4);
    append(&p,2);
    append(&p,1);
    append(&p,2);
    append(&p,4);
    append(&p,6);
    append(&p,8);
    append(&p,5);
    append(&p,8); */
    append(&p,12);
    append(&p,11);
    append(&p,12);
    append(&p,21);
    append(&p,41);
    append(&p,43);
    append(&p,21);

    display(p);
    printf("\n");

    int c=getmid(&p);

    rem(p,c);
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

getmid(struct node **q)
{   int count=0,i;
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp=*q;
    while(temp!=NULL)
    {
        count+=1;
        temp=temp->link;
    }
    return count;
}


rem(struct node *q,int c)
{
    /*struct node *m;
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
       */
        struct node *a,*b,*t;
        a=q;

        int d;
        int i=0;
        while(i<c)
        {
            ++i;
            d=a->data;
            b=a;
                while(b->link!=NULL)
                {
                    if(b->link->data==d)
                    {
                       t=b->link->link;
                       free(b->link);
                       b->link=t;
                       c--;

                    }
                    else
                    {
                        b=b->link;
                    }
                }
            a=a->link;

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
