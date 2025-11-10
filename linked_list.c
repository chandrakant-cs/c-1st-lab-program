#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void createList(int n)
{
    struct node *newnode,*temp;
    int data,i;

    if(n<=0)
    {
        printf("number of nodes should be greater than 0!!\n");
        return;
    }

    for (i=1;i<=n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if (newnode==NULL)
        {
            printf("memory allocation failed!!\n");
            return;
        }
        printf("enter data for node %d:",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;

        if (head==NULL)
        {
            head=newnode;
        }
        else{
            temp->next=newnode;
        }
        temp=newnode;
    }
    printf("inserted successfully...\n");
}

void insert_first(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("node inserted \n");
}

void insert_at_pos(int data,int pos)
{
    int i;
    struct node *newnode,*temp=head;

    if (pos<1)
    {
        printf("invalid position!!\n");
        return;
    }
    if (pos==1)
    {
        insert_first(data);
        return;
    }
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;

    for (i=1;i<pos-1&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("position out of range!!\n");
        free(newnode);
    }
    else
    {
        newnode->next=temp->next;
        temp->next=newnode;
        printf("inserted\n");
    }
}

void insert_last(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("inserted\n");
}
void display()
{
    if (head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        struct node *temp=head;
        while (temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        
        
    }
}

int main()
{
    int ch,n,data,pos;

    while (1)
    {
        printf("--singly linked list operations--\n");
        printf("1.create list\n");
        printf("2.insert at first\n");
        printf("3.insert at position\n");
        printf("4.insert at end\n");
        printf("5.diplay\n");
        printf("6.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("enter number of nodes:");
            scanf("%d",&n);
            createList(n);
            break;
        
        case 2:
            printf("enter data:");
            scanf("%d",&data);
            insert_first(data);
            break;
        
        case 3:
            printf("enter data and position:");
            scanf("%d %d",&data,&pos);
            insert_at_pos(data,pos);
            break;

        case 4:
            printf("enter data:");
            scanf("%d",&data);
            insert_last(data);
            break;
        case 5:
            display();
            break;

        case 6:
            printf("exiting....\n");
            exit(0);
        

        default:
        printf("invalid choice..."); 
        }

    }
}
