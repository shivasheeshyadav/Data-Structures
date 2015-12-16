//Linked Lists
#include<stdio.h>
struct node
{
    struct node *link1;
    int data;
    struct node *link2;
};

main()
{
    struct node *p;
    p=NULL;

    struct node *s;
    s=NULL;
    append(&p,&s,1);
    append(&p,&s,2);
    append(&p,&s,3);
    append(&p,&s,4);
    append(&p,&s,5);
    append(&p,&s,6);
    append(&p,&s,7);
    append(&p,&s,8);
    append(&p,&s,9);
    append(&p,&s,10);
    //append(&p,&s,5);
    display(&p);
    //dis(s);

    //addatbeg(&p,100);
    //display(&p);

    //addafter(&p,3,25);
    //display(&p);


    /*delnode(&p,&s,&p);
    display(&p);
    delnode(&p,&s,&(p)->link2);
    display(&p);
    delnode(&p,&s,&s);
    //dis(&p);
    display(&p);*/

    swap(&p,&s,0);
    display(&p);
}

append(struct node **q,struct node **t,int num)
{
    struct node *temp,*r;
    temp=*q;
    if(*q==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->data=num;
        temp->link1=NULL;
        temp->link2=NULL;
        *q=temp;
        *t=temp;
    }
    else
    {
        temp=*q;
        while(temp->link2!=NULL)
        {
            temp=temp->link2;
        }
        r=malloc(sizeof(struct node));
        r->data=num;
        r->link2=NULL;
        temp->link2=r;
        r->link1=temp;
        *t=r;
    }
}

/*addatbeg(struct node **q,int num)
{
    struct node *temp;
    temp=*q;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->link=*q;
    *q=temp;

}

addafter(struct node **q,int loc,int num)
{
    struct node *temp,*r;
    temp=malloc(sizeof(struct node));
    temp= *q;
    int i;
        for(i=0;i<loc;++i)
        {
            temp=temp->link;
        }
        r=malloc(sizeof(struct node));
        r->data=num;
        r->link=temp->link;
        temp->link=r;
}*/

delnode(struct node **q,struct node **s,struct node **d)
{
    struct node *temp;


    if(*d==*q)
    {
       temp=malloc(sizeof(struct node));
    temp=*q;
        *q=temp->link2;
        (*q)->link1=NULL;
        free(temp);
    }
    else
    {
        temp=malloc(sizeof(struct node));
        temp=(*q)->link2;
        (*q)->link2=temp->link2;
        //temp->link2->link1=(*q)->link2;
        free(temp);
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
    temp=temp->link2;
    }
    printf("\n");
}

dis(struct node *s)
{
    while(s!=NULL)
    {
        printf("%d ",s->data);
    s=s->link1;
    }
    printf("\n");
}

swap(struct node **p,struct node **s,int n)
{
    int i=0;
    struct node *t,*y,*r1,*r2,*r3,*r4,*q;
    q=*p;
    t=*p;
    y=*s;
    do
    {
        r1=t;
        r2=t->link2->link2;
        t=t->link2;
        r3=y;
        r4=y->link1->link1;
        y=y->link1;
        ++i;
    }while(i<n);

    r1->link2=y;
    y->link1=r1;
    y->link2=r2;
    r2->link1=y;

    r3->link1=t;
    t->link2=r3;
    t->link1=r4;
    r4->link2=t;

    *p=q;
    *s=q->link1;


}
