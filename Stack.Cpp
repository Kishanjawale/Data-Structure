#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Stack
{
    private:
        int Count;
        PNODE Head;
    public:
        Stack();
        void Push(int);
        void Pop();
        void Display();
        int CountNode();
};

Stack::Stack()
{
    Head= NULL;
    Count=0;
}

int Stack :: CountNode()
{
    return Count;
}

void Stack :: Push(int iNo)
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
void Stack::Display()
{
    if(Count==-1)
    {
        cout<<"Stack is Empty ..Nothing to show";
    }
    else
    {
        cout<<"\nElements in the Stack are:\n";
        PNODE temp= Head;
        while (temp != NULL )
        {
            cout<<"|"<<temp->data<<"|";
            temp=temp->next;
        }
    }
}
void Stack::Pop()
{
    if(Head==NULL)
    {
        cout<<"\nStack is empty..\n";
    }
    else
    {
        PNODE temp= Head;
        Head= Head->next;
        delete(temp);
    }
    Count--;
}

int main()
{
    Stack ss;
    int Data;
    ss.Push(10);
    ss.Push(20);
    ss.Push(30);
    ss.Push(40);
    ss.Display();
    ss.Pop();
    ss.Pop();
    ss.Display();
       return 0;
}