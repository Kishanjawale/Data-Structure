#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Queue
{
    private:
        int Count;
        PNODE Head;
    public:
        Queue();
        void Enqueue(int);
        void Dequeue();
        void Display();
        int CountNode();
};

Queue::Queue()
{
    Head= NULL;
    Count=0;
}

int Queue :: CountNode()
{
    return Count;
}

void Queue :: Enqueue(int iNo)
{
    PNODE newn= NULL;
    newn = new NODE;
    newn->data=iNo;
    newn->next=NULL;
    if(Head==NULL)
    {
        Head= newn;
    }
    else
    {
        newn->next= Head;
        Head=newn;
    }
    Count++;
}
void Queue::Display()
{
    if(Count==-1)
    {
        cout<<"Queue is Empty ..Nothing to show";
    }
    else
    {
        cout<<"\nElements in the Queue are:\n";
        PNODE temp= Head;
        while (temp != NULL )
        {
            cout<<"|"<<temp->data<<"|";
            temp=temp->next;
        }
    }
}
void Queue::Dequeue()
{
    if(Head==NULL)
    {
        cout<<"\nQueue is empty..\n";
    }
    else
    {
        PNODE temp= Head;
    
        while (temp->next->next!= NULL)
        {
            temp=temp->next;
        }
           delete(temp->next);
            temp->next=NULL;
    }
    Count--;
}

int main()
{
    Queue ss;
    int Data;
    ss.Enqueue(10);
    ss.Display();
    ss.Enqueue(20);
    ss.Display();
    ss.Enqueue(30);
    ss.Display();
    ss.Enqueue(40);
    ss.Display();
    ss.Dequeue();
    ss.Display();
    ss.Dequeue();
    ss.Display();
       return 0;
}