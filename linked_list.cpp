#include<iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};

class linkedList
{
    node *head,*tail;
public:
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void insertLast(int data)
    {
        node *temp=new node;
        temp->item=data;
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    void insertBegin(int data)
    {
        node *temp=new node;
        temp->item=data;
        temp->next=head;
        head=temp;
        if (tail==NULL)
        {
            tail=temp;
            temp=NULL;
        }
    }
    void deleteItemAtBegin()
    {
        if (head==NULL)
        {
            cout<<"\nNo item in Linked List.";
        }
        else
        {
            head=head->next;
        }
    }
    void deleteItemAtLast()
    {
        node *temp=new node;
        node *hold=new node;
        temp=head;
        if (head==NULL)
        {
            cout<<"\nNo item in Linked List.";
        }
        else if (temp->next==NULL)
        {
            head=NULL;
            tail=NULL;
        }
        else
        {
            while(temp->next!=NULL)
            {
                hold=temp;
                temp=temp->next;
            }
            tail=hold;
            tail->next=NULL;
        }
    }
    void deleteNodeWithValue(int value)
    {
        node *temp=new node;
        node *prev=new node;
        temp=head;
        prev=NULL;
        if (head==NULL)
        {
            cout<<"\nNo item in Linked List.";
        }
        ///item at head
        else if (head->item==value)
        {
            head=head->next;
        }
        else
        {
            ///search through list
            while(temp!=NULL && temp->item!=value)
            {
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL)
            {
                cout<<"\nNot found.";
            }
            else
            {
                prev->next=temp->next;
                temp=NULL;
            }
        }
    }
    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->item<<",";
            temp=temp->next;
        }
    }
};
int main()
{
    int x,choice,item,value;
    linkedList obj;
    x=1;
    while(x!=0)
    {
    cout<<"\n\n Menu ";
    cout<<"\n-------------------------";
    cout<<"\n*  1.Insert At Begin    *";
    cout<<"\n*  2.Insert At Last     *";
    cout<<"\n*  3.Delete At Begin    *";
    cout<<"\n*  4.Delete At Last     *";
    cout<<"\n*  5.Delete Node        *";
    cout<<"\n*  6.Show               *";
    cout<<"\n*  0.Exit               *";
    cout<<"\n-------------------------";
    cout<<"\n\nEnter choice number - ";
    cin>>choice;
    switch(choice)
    {
    case(1):
        {
            cout<<"\nEnter value - ";
            cin>>item;
            obj.insertBegin(item);
            break;
        }
    case(2):
        {
            cout<<"\nEnter value - ";
            cin>>item;
            obj.insertLast(item);
            break;
        }

    case(3):
        {
            obj.deleteItemAtBegin();
            break;
        }
    case(4):
        {
            obj.deleteItemAtLast();
            break;
        }
    case(5):
        {
            cout<<"\nEnter node - ";
            cin>>value;
            obj.deleteNodeWithValue(value);
            break;
        }
    case(6):
        {
            obj.display();
            break;
        }
    case(0):
        {
            x=0;
            break;
        }
    default:
        {
            cout<<"\nInvalid Choice!!!";
        }
    }
    }
}
