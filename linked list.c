#include<stdio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void insertatbeg()
{
    struct node *newnode;
    int data;
    newnode=malloc(sizeof(newnode));
    if(newnode==NULL)
    {
        printf("Llist is overflow\n");
        exit(1);
    }
    printf("enter data:");
    scanf("%d",&data);
    newnode->data=data;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insertatend()
{
    struct node *newnode,*temp;
    int data;
    newnode=malloc(sizeof(newnode));
    if(newnode==NULL)
    {
       printf("list is overflow\n");
       exit(1);
    }
    printf("enter data:\n");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp->next=newnode;
    }
}
void insertatspecific()
{
    struct node *newnode,*temp;
    int value,value1;
    newnode=malloc(sizeof(newnode));
    if(newnode==NULL);
    {
        printf("lLIST IS overflow");
        exit(1);
    }
    printf("Enter value 1:");
    scanf("%d",&value1);
    printf("enter value:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->data!=value1)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    }
    void deleteatbeg()
    {
        struct node *temp;
        int data;
        if(head==NULL)
        {
            printf("List is underflow\n");
            exit(1);
        }
        temp=head;
        data=temp->data;
        printf("deleted value is %d",data);
        head=head->next;
        free(temp);
        temp==NULL;
    }
    void deleteatend()
    {
        struct node *temp,*temp1;
        int data;
        if(head==NULL)
        {
            printf("Llist is underflow\n");
            exit(1);
        }
        temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        data=temp->data;
        printf("deleted value is %d",data);
        temp1->next=NULL;
        free(temp);
    }
    void deleteatspecific()
    {
        struct node *temp1,*temp2;
        int data;
        if(head==NULL)
        {
            printf("Llist is underflow\n");
            exit(1);
        }
        printf("enter the specific value to delete from specific location:");
        scanf("%d",&data);
        temp1=head;
        while(temp1->data!=data)
        {
            if(temp1->next==NULL)
            {
                printf("given node is not found");
                return;
            }
            temp2->temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        free(temp1);
    }
    void display()
    {
        struct node *temp;
        temp=head;
        if(head==NULL)
        {
            printf("list is underflow\n");
            exit(1);
        }
        else
        {
            printf("the list of elements are\n");
            while(temp!=NULL)
            {
                printf("%d",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
    }
    void main()
    {
        int choice;
        printf("implementation of a singly linked list");
        while(1)
        {
            printf("\n1.insertion at begginning\n2.insertion at the end\n3.insertion at a specific location\n4.deletion at begging\n5.deletion at ending\n6.deletion at specific location\n7.display\n");
            printf("enter your choice:");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:insertatbeg();
                break;
            case 2:insertatend();
                break;
            case 3:insertatspecific();
                break;
            case 4:deleteatbeg();
                break;
            case 5:deleteatend();
                break;
            case 6:deleteatspecific();
                break;
            case 7:display();
                break;
            default:printf("Enter the correct choice\n");
                break;
            }
        }
    }
