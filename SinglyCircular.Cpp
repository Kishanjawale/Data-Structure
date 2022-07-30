#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCircular
{
    private:
    int Count;
    PNODE Head;
    PNODE Tail;
    
    public:
    SinglyCircular();
    void InsertFirst(int);
    void InsertLast(int );
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int CountNodes();
    void Display();
};
SinglyCircular::SinglyCircular()
{
      Head= NULL;
      Tail= NULL;
      Count=0;
}

int SinglyCircular::CountNodes()
{
    return Count;
}

void SinglyCircular::Display()
{
    PNODE temp=Head;
    do
    {
        cout<<"|->"<<temp->data<<"|->";
        temp= temp->next;
    }while(temp != Head);
}

void SinglyCircular::InsertFirst(int iNo)
{
    PNODE newn= NULL;
    newn= new NODE;
    newn->next=NULL;
    newn->next=NULL;
    newn->data=iNo;

    if( Head==NULL && Tail == NULL )
    {
        Head=newn;
        Tail= newn;
    }
    else
    {
        newn->next=Head;
        Head= newn;
    }
    Tail->next= Head;
    Count++;
}

void SinglyCircular::InsertLast(int iNo)
{
    PNODE newn= NULL;
    newn  = new NODE;

    newn->next=NULL;
    newn->data= iNo;

    if(Head== NULL&& Tail== NULL)
    {
        Head= newn;
        Tail= newn;
    }
    else
    {
        Tail->next=newn;
        Tail= newn;
    }
    Tail->next= Head;
    Count++;
}

void SinglyCircular::InsertAtPos(int iNo ,int iPos)
{
    int isize=CountNodes();

    if(iPos <=0 || iPos >= isize+1 )
    {
        cout<<"Invalid Position entered";
        return;
    }
    else if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==isize+1)
    {
        InsertLast(iNo);
    
    }
    else
    {
        PNODE newn= NULL;
        newn= new NODE;
        newn->next=NULL;
        newn->data=iNo;
        PNODE temp = Head;
        int iCnt=0;
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next= temp->next;
        temp->next = newn;

        Count++;
    }
}
void SinglyCircular::DeleteFirst()
{
    if(Head == NULL && Tail== NULL)
    {
        cout<<"Linked List is Already empty";
    }
    else if(Head -> next == Tail)
    {
        delete Head;
        Head= NULL;
        Tail= NULL;
    }
    else
    {
        Head=Head->next;
        delete (Tail->next);
    }
    Tail->next=Head;
    Count--;
}

void SinglyCircular::DeleteLast()
{
    if(Head == NULL && Tail==NULL)
    {
        cout<<"Linked List is already Empty";
    }
    else if(Head->next == Tail)
    {
        delete Head;
        Head= NULL;
        Tail= NULL;
    }
    else
    {
        PNODE temp=Head;
        while (temp->next->next !=Head )
        {
            temp=temp->next;
        }
        delete (temp->next);
        Tail= temp;    
    }
    Tail->next=Head;
    Count--;
}

void SinglyCircular:: DeleteAtPos(int iPos)
{
    int isize=CountNodes();

    if(iPos<=0 && iPos >isize+1)
    {
        cout<<"Invalid Position";
    }
    else if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==isize)
    {
        DeleteLast();
    }
    else 
    {
        int iCnt=0;
        PNODE temp= Head;
        PNODE tempDel= NULL;
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        tempDel=temp->next;
        temp->next= temp->next->next;
        delete (tempDel);
    }
    Count--;
}

int main()
{
    SinglyCircular sc;
    int CountOfNodes=0;
    CountOfNodes=sc.CountNodes();
    sc.InsertFirst(300);
    sc.InsertFirst(200);
    sc.InsertFirst(100);

    sc.InsertLast(400);
    sc.InsertLast(500);
    sc.Display();
    
    CountOfNodes=sc.CountNodes();
    cout<<"\nNumbers in Linked list:"<<CountOfNodes<<endl;
    sc.InsertAtPos(111,2);
    
    sc.Display();
    CountOfNodes=sc.CountNodes();
    cout<<"\nNumbers in Linked list:"<<CountOfNodes<<endl;

    sc.DeleteFirst();
    sc.DeleteFirst();
    
    sc.Display();
    CountOfNodes=sc.CountNodes();
    cout<<"\nNumbers in Linked list:"<<CountOfNodes<<endl;   
    
    sc.DeleteLast();
    sc.Display();
    CountOfNodes=sc.CountNodes();
    cout<<"\nNumbers in Linked list:"<<CountOfNodes<<endl;   
    
    sc.DeleteAtPos(2);
    sc.Display();
    CountOfNodes=sc.CountNodes();
    cout<<"\nNumbers in Linked list:"<<CountOfNodes<<endl;   
    return  0;
}