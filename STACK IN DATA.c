#include<stdio.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;
int count=0;
int main()
{
    printf("1.Add items.\n");
    printf("2.Delete items.\n");
    printf("3.Show the number of items.\n");
    printf("4.Show min and max items.\n");
    printf("5.Find an item.\n");
    printf("6.Print all items.\n");
    printf("7.Count how many items are there.\n");
    printf("8.Exit.\n\n\n");
    while(1)
    {
        switch(menu())
        {
            case 1: add();
            break;
            case 2: del();
            break;
            case 3:display();
            break;
            case 4:max();
            break;
            case 5: find();
            break;
            case 6: display();
            break;
            case 7: printf("TOTAL:%d\n",total());
            break;
            case 8: exit(0);
            break;
            default:printf("check your choice.");
            break;
        }
    }
}
int menu()
{
    printf("Enter your choice:\n");
    int ch;
    scanf("%d",&ch);
    return(ch);
}
void add()
{
    printf("\nAdd a item:\n");
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
}
void del()
{
    struct node *t;
    t=top;
    if(top==NULL)
    {
        printf("List is Empty.\n");
    }else
    {
        top=top->link;
        free(t);
    }
}
void display()
{
    struct node *d;
    d=top;
    if(top==NULL)
    {
        printf("List is empty.\n");
    }else
    {
        while(d!=NULL)
        {
            printf("%d ",d->data);
            d=d->link;
        }
    }
    printf("\n");
}
void max()
{
    int max=0,min=0;
    struct node *m;
    m=top;
    if(top==NULL)
    {
        printf("List is empty.\n");
    }else
    {
        while(m!=NULL)
        {
            if(m->data>max)
            {
                max=m->data;
            }else
            {
                min=m->data;
            }
                m=m->link;
        }
    }
    printf("max is:%d  and min is %d.\n",max,min);
}
void find()
{
    int n,l,c=1;
    l=total();
    printf("Which element?");
    scanf("%d",&n);
    struct node *f;
    f=top;
    if(top==NULL)
    {
        printf("List is empty.\n");
    }else
    {
        f=top;
        while(f!=NULL)
        {
            if(f->data==n)
            {
                printf("%d no element.\n",c);
                break;
            }else
            {
                c++;
            }
            f=f->link;
        }
        if(l<c)
        {
            printf("This element is not exist.\n");
        }
    }
}
int total()
{
    struct node *cont;
    int k=1;
    cont=top;
    if(top==NULL)
    {
        printf("List is empty.\n");
    }else
    {
        while(cont->link!=NULL)
        {
            cont=cont->link;
            k++;
        }
    }
    return(k);
}
