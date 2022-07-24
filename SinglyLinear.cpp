#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLinear
{
    private:
    PNODE Head;
    int Count;

    public:
    SinglyLinear();
    void Display();
    int CountNode();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    
};

SinglyLinear::SinglyLinear()
{
    Head= NULL;
    Count=0;
}
 int SinglyLinear::CountNode()
{
    return Count;
}

void SinglyLinear::Display()
{
    PNODE temp=Head;
    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void SinglyLinear::InsertFirst(int iNo)
{
    PNODE newn=NULL;
    newn= new NODE;

    newn->data=iNo;
    newn->next=NULL;
    
    if(Head==NULL)
    {
      Head=newn;

    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    Count++;
}

void SinglyLinear::InsertLast(int iNo)
{
    PNODE newn=NULL;
    newn= new NODE;
    newn->next=NULL;
    newn->data=iNo;

    if(Head==NULL)
    {
        Head= newn;
    }
    else
    {
        PNODE temp= Head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next= newn;
    }
    Count++;
}

void SinglyLinear:: InsertAtPos(int iPos,int iNO)
{
    int iSize=CountNode();
    if(iPos < 1  || iPos>iSize+1)
    {
        cout<<"Invalid Pos";
        return ;
    }
    else if (iPos==1)
    {
        InsertFirst(iNO);
        return;
    }
    else if(iPos ==iSize+1)
    {
        InsertLast(iNO);
    }
    else
    {
        PNODE newn=NULL;
        newn=new NODE;
        
        newn->next=NULL;
        PNODE  temp= Head;
        newn->data= iNO;
       
       for(int i=1;i<iPos-1;i++)
       {
             temp= temp->next;
       }
       newn->next=temp->next;
        temp->next= newn;

    }
    Count++;
}
void SinglyLinear:: DeleteFirst()
{
    if(Head== NULL)
    {
         cout<<"Linked list is already empty";
        return;
    }
    else
    {
        PNODE temp=Head;
        Head=Head->next;
        delete temp;
    }
    Count--;
}

void SinglyLinear::DeleteLast()
{   
    if(Head== NULL)
    {
         cout<<"Linked list is already empty";
        return;
    }
    else
    {
        PNODE temp=Head;
        while (temp->next->next!= NULL )
        {
            temp= temp->next;
        }
        delete (temp->next);
        temp->next=NULL;


        
    }

    Count--;
}
void SinglyLinear:: DeleteAtPos(int iPos)
{
    int size=CountNode();
    if(iPos<1 ||  iPos>size+1)
    {
        cout<<"Invalid position";
    }
    else if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==size+1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp= Head;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        PNODE tempdel= temp->next;
        temp->next=temp->next->next;
        delete (tempdel);
    }
    Count--;

} 

int main()
{
    SinglyLinear sl;

    int CountOfNode=0;
    sl.InsertLast(110);
    sl.InsertLast(120);
    sl.InsertFirst(100);
    sl.InsertFirst(90);
    sl.InsertFirst(80);
    sl.InsertFirst(70);

    CountOfNode=sl.CountNode();
    cout<<"Number of nodes in LL are:"<<CountOfNode<<endl;
    sl.Display();
    cout<<endl;

    sl.DeleteFirst();
    sl.DeleteFirst();
    
    CountOfNode=sl.CountNode();
    cout<<endl;
    cout<<"Number of nodes in LL are:"<<CountOfNode<<endl;
    sl.Display();
    
    sl.DeleteAtPos(2);
    CountOfNode=sl.CountNode();
    cout<<endl;
    cout<<"Number of nodes in LL are:"<<CountOfNode<<endl;
    sl.Display();
    

    return 0;
}



