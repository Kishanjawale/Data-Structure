#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node * next;
    struct node * prev;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyCircular
{
    private:
    int Count;
    PNODE Head;
    PNODE Tail;
    
    public:
    DoublyCircular();
    void Display();
    int CountNodes();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};
DoublyCircular::DoublyCircular()
{
    Count=0;
    Head= NULL;
    Tail= NULL;
}
void DoublyCircular::InsertFirst(int iNo)
{
    PNODE newn= NULL;
    newn=new NODE;
    newn->next=NULL;
    newn->data= iNo;
    newn->prev= NULL;
    
    if(Count==0)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev= newn;
        Head=newn;
    }
    Head->prev=Tail;
    Tail->next=Head;
    Count++;
    
}
void DoublyCircular::InsertLast(int iNo)
{
    PNODE newn= NULL;
    newn= new NODE;
    newn->next=NULL;
    newn->prev= NULL;
    newn->data =iNo;

    if(Count==0)
    {
        Head= newn;
        Tail= newn;
    }
    else
    {
        Tail->next= newn;
        newn->prev= Tail;
        Tail= newn;
    }
    Head->prev= Tail;
    Tail->next=Head;
    Count++;
}
void DoublyCircular::InsertAtPos(int iNo,int iPos)
{
    if(iPos <1 || iPos >=Count+1)
    {
        cout<<"Invalid Poistion";
    }
    else if(iPos==1)
    {
        InsertFirst(iNo);

    }
    else if(iPos== Count+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn = NULL;
        newn->next= NULL;
        newn->prev= NULL;
        newn->data= iNo;
        PNODE temp = Head;
        int iCnt=0;
        for(iCnt=1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp= temp->next;
        }
        newn->next=temp->next;
        newn->next->prev= newn;
        temp->next= newn;
        newn->prev= temp;
        Count++;
    }
}
void DoublyCircular::DeleteAtPos(int iPos)
{
    int iSize=CountNodes();
    if(iPos <1 || iPos >=Count+1)
    {
        cout<<"Invalid Poistion";
    }
    else if(iPos=1)
    {
        DeleteFirst(iNo);

    }
    else if(iPos== Count+1)
    {
        DeleteLast(iNo);
    }
    else
    {   
        PNODE temp= Head;
        for(int icnt=0; icnt<iPos-1;icnt++)
        {
            temp=temp->next;

        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev= temp;
        Count--;
    }

}
void DoublyCircular::DeleteFirst()
{
    if(Count==0)
    {
        cout<<"Linked list is empty"<<endl;
        
    }
    if(Count==1)
    {
        delete Head;
        Head= NULL;
        Tail= NULL;
    }
    else
    {
        Head= Head->next;
        delete Tail->next;
        Count--; 
    }
}
void DoublyCircular::DeleteLast()
{
     if(Count==0)
    {
        cout<<"Linked list is empty"<<endl;
        
    }
    if(Count==1)
    {
        delete Head;
        Head= NULL;
        Tail= NULL;
    }
    Head->prev= Tail;
    Tail->next=Head;
    Count--;

}

int DoublyCircular::CountNodes()
{
    return Count;
}
void DoublyCircular:: Display()
{
    PNODE temp= Head;
    cout<<"Data From the Linked List is:"<<endl;
    do
    {   
        cout<<"|"<<temp->data<<"|<=>";
        temp=temp->next;
    } while (temp!=Head);
    
    cout<<endl;
}

int main()
{
    DoublyCircular dl;
    dl.InsertFirst(70);
    
    dl.InsertFirst(80);

    dl.InsertFirst(90);
    dl.InsertFirst(100);
    dl.Display();
    cout<<endl;
    dl.InsertLast(200);
    dl.InsertLast(300);
    dl.InsertLast(400);
    cout<<endl;
    dl.Display();
    dl.InsertAtPos(900,3);
    dl.Display();
    

    return 0;
}