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


class DoublyLinear
{
    private:
     int Count;
     PNODE Head;
     public:
     DoublyLinear();
     void Display();
     int CountNodes();
     void InsertFirst(int);
     void InsertLast(int);
     void InsertAtPos(int ,int);
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int);

};

DoublyLinear:: DoublyLinear()
{
    Head=NULL;
    Count=0;
}


void DoublyLinear:: Display()
{
    PNODE temp= Head;
    
    cout<<"Elements in the liked list are:"<<endl;
    cout<<"<->";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int DoublyLinear:: CountNodes()
{
    return Count;
}


void DoublyLinear:: InsertFirst(int iNo)
{
    PNODE newn= NULL;
    newn= new NODE;
    newn->data= iNo;
    newn->next= NULL;
    newn->prev= NULL;
    cout<<"Insert";
    if(Count==0)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head= newn;
    }
    Count++;
}

void DoublyLinear:: InsertLast(int iNo)
{
    PNODE newn= NULL;
    newn= new NODE;
    newn->next=NULL;
    newn->prev=NULL;
    newn->data= iNo;
    
    if(Count==0)
    {
        Head=newn;
    }
    else
    {
        PNODE temp = Head;
        while (temp->next!= NULL)
        {
            temp= temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    Count++;
}
void DoublyLinear:: InsertAtPos(int iPos,int iNo)
{
    int size=CountNodes();

    if(iPos<0 || iPos > size + 1 )
    {
        cout<<"Invalid Position Entered";
    }
    else if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==size+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn=NULL;
        newn= new NODE;
        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;
        int i = 0;

        PNODE temp=Head;
        for(i = 1; i < iPos - 1 ; i++)
        {
            temp = temp -> next;
        }
        newn->next= temp->next;

        temp->next->prev= newn;  
        temp -> next =  newn;
        newn->prev= temp;
    }
    Count ++;
}

void DoublyLinear:: DeleteFirst()
{
    if(Count==0)
    {
        cout<<"Linked List is already empty";
        return;
    }
    if(Count==1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head=Head->next;
        delete Head->prev;
        Head->prev= NULL;
    }
    Count--;
}
void DoublyLinear:: DeleteLast()
{
    if(Count==0)
    {
        cout<<"Linked List is already empty";
        return;
    }
    if(Count==1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp=Head;
        while (temp->next->next!=NULL)
        {
            temp= temp->next;
        }
        delete(temp->next);
        temp->next =NULL;
    }
    Count--;
}


void DoublyLinear:: DeleteAtPos(int iPos)
{
    
    int size=CountNodes();

    if(iPos<0 || iPos > size + 1 )
    {
        cout<<"Invalid Position Entered";
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
        PNODE temp=Head;
        for(int i=1;i < iPos-1 ; i++)
        {
            temp= temp->next;
        }
        temp->next= temp->next->next;
        delete (temp->prev);
        temp->next->prev = temp;
    }
    Count --;
}
int main()
{
    DoublyLinear dl;
    dl.InsertFirst(10);
    dl.InsertLast(200);
    dl.InsertAtPos(2,100);
    int CountOfNodes= dl.CountNodes();
    cout<<"number of nodes in linked list are:"<<CountOfNodes<<endl;
    dl.Display();  


    dl.DeleteAtPos(2);
    dl.DeleteFirst();
    dl.DeleteLast();

    CountOfNodes= dl.CountNodes();
    cout<<"number of nodes in linked list are:"<<CountOfNodes<<endl;
    dl.Display(); 

    return 0;

}