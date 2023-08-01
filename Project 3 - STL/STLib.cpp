#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Standard Template Library
//  Description     :   Library which contains generic implementations of all major types of data structures
//  Author          :   Vaidehi Vishwanath Kale
//  Date            :   31/07/2023
//  
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS    //since it is generic we cant use typedef
{
    T data;
    struct NodeS *next;
};

template <class T>
struct NodeD    //since it is generic we cant use typedef
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

//////////////////////////////////////////////////////////////////
//
// Singly Circular Linked List
//
//////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public: 
        struct NodeS<T> *first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    T Minimum();
    T Maximum();
    T Summation();
    int FirstOccurance(T);
    int LastOccurance(T);
    int Frequency(T);

};  

template <class T>
SinglyLL<T> :: SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T> ::Display()
{
    cout<<"Elements of Singly Linear Linked List are : "<<"\n";

    NodeS<T> *temp = first;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";

}

template <class T>
int SinglyLL<T> ::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> ::InsertFirst(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else{
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> ::InsertLast(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else{
        NodeS<T> *temp = first;

        while (temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> ::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next ==NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp=first;

        first= first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> ::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next ==NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp=first;

        while (temp->next->next !=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next = NULL;  
        
    }
    iCount--;
}

template <class T>
void SinglyLL<T> ::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = No;
        newn->next =NULL;

        for(int iCnt = 1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next = temp->next;
        temp->next =newn;

        iCount++;
    }
}
template <class T>
void SinglyLL<T> ::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for(int iCnt = 1;iCnt<iPos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next->next;
        delete temp1->next;
        temp1->next =temp2;
        
        iCount--;
    }
}

template <class T>
T SinglyLL<T> :: Minimum()
{
    T iMin=0;
    NodeS<T> *temp = first;
    if(temp == NULL)
    {
        return -1;
    }
    iMin = temp->data;
    
    while(temp != NULL)
    {
        if((temp->data) < iMin)
        {
            iMin=temp->data;
        }
        temp=temp->next;
    }
    return iMin;
}

template <class T>
T SinglyLL<T> :: Maximum()
{
    T iMax=0;
    NodeS<T> *temp =first;
    if(temp == NULL)
    {
        return -1;
    }
    iMax = temp->data;
    
    while(temp != NULL)
    {
        if((temp->data) > iMax)
        {
            iMax=temp->data;
        }
        temp=temp->next;
    }
    return iMax;
}

template <class T>
T SinglyLL<T> :: Summation()
{
    T iSum=0;
    NodeS<T> *temp =first;
    while(temp != NULL)
    {
        iSum=iSum + (temp->data);
        temp=temp->next;
    }
    return iSum;
}

template <class T>
int SinglyLL<T> :: FirstOccurance(T No)
{
    int iCnt = 1;
    NodeS<T> *temp = first;
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            break;
        }
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}
template <class T>
int SinglyLL<T> :: LastOccurance(T No)
{
    int iCnt = 1;
    int index = 0;
    NodeS<T> *temp = first;
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            index = iCnt;
        }
        iCnt++;
        temp=temp->next;
    }
    return index;
}
template <class T>
int SinglyLL<T> :: Frequency(T No)
{
    int iCnt = 0;

    NodeS<T> *temp = first;
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iCnt++;
        }
        temp=temp->next;
    }
    return iCnt;
}

//////////////////////////////////////////////////////////////////
//
// Singly Circular Linked List
//
//////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public: 
        struct NodeS<T> *first;
        struct NodeS<T> *last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    T Minimum();
    T Maximum();
    T Summation();
    int FirstOccurance(T);
    int LastOccurance(T);
    int Frequency(T);
};  

template <class T>
SinglyCL<T> :: SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T> ::Display()
{
    cout<<"Elements of Singly Linear Linked List are : "<<"\n";
    NodeS<T> *temp = first;
    do{
        cout<<"| "<<temp->data<<" | -> ";
        temp=temp->next;
    }while(temp != last->next);

    cout<<"NULL"<<"\n";

}

template <class T>
int SinglyCL<T> ::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T> ::InsertFirst(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else{
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T> ::InsertLast(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else{
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T> ::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> ::DeleteLast()
{
    NodeS<T> *temp = first;
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp=temp->next;
        }
        delete last;
        last = temp;
        last->next =first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> ::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = No;
        newn->next =NULL;

        for(int iCnt = 1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next = temp->next;
        temp->next =newn;

        iCount++;
    }
}
template <class T>
void SinglyCL<T> ::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for(int iCnt = 1;iCnt<iPos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;

        temp1->next = temp1->next->next;
        delete temp2;
        
        iCount--;
    }
}

template <class T>
T SinglyCL<T> :: Minimum()
{
    T iMin=0;
    NodeS<T> *temp = first;
    if(temp == NULL)
    {
        return -1;
    }

    iMin = temp->data;

    do{
        if((temp->data) < iMin)
        {
            iMin=temp->data;
        }
        temp=temp->next;
    }while(temp != last->next);

    return iMin;
}

template <class T>
T SinglyCL<T> :: Maximum()
{
    T iMax=0;
    NodeS<T> *temp = first;
    if(temp == NULL)
    {
        return -1;
    }

    iMax = temp->data;

    do{
        if((temp->data) < iMax)
        {
            iMax=temp->data;
        }
        temp=temp->next;
    }while(temp != last->next);

    return iMax;
}

template <class T>
T SinglyCL<T> :: Summation()
{
    T iSum=0;
    NodeS<T> *temp =first;
    do{
        iSum=iSum + (temp->data);
        temp=temp->next;
    }while(temp != last->next);
   
    return iSum;
}

template <class T>
int SinglyCL<T> :: FirstOccurance(T No)
{
    int iCnt = 1;
    NodeS<T> *temp = first;
    do{
        if(temp->data == No)
        {
            break;
        }
        iCnt++;
        temp=temp->next;
    }while(temp != last->next);
    return iCnt;
}

template <class T>
int SinglyCL<T> :: LastOccurance(T No)
{
    int iCnt = 1;
    int index = 0;
    NodeS<T> *temp = first;
    do{
        if(temp->data == No)
        {
            index = iCnt;
        }
        iCnt++;
        temp=temp->next;
    }while(temp != last->next);

    return index;
}

template <class T>
int SinglyCL<T> :: Frequency(T No)
{
    int iCnt = 0;

    NodeS<T> *temp = first;
    do
    {
        if(temp->data == No)
        {
            iCnt++;
        }
        temp=temp->next;
    }while(temp != last->next);

    return iCnt;
}

//////////////////////////////////////////////////////////////////
//
// Doubly Linked List
//
//////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> *First;
        int iCount;
    public:
        DoublyLL();

        void InsertFirst(T ino);
        void InsertLast(T ino);
        void InsertAtPos(T ino,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();

        T Minimum();
        T Maximum();
        T Summation();
        int FirstOccurance(T);
        int LastOccurance(T);
        int Frequency(T);
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> ::Display()
{
    NodeD<T> *temp=First;

    cout<<"Elements of Linked List are: "<<"\n";
    cout<<"NULL <=>";
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";

}

template <class T>
int DoublyLL<T> ::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T> ::InsertFirst(T No)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
  
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> ::InsertLast(T No)
{
    NodeD<T> *newn = new NodeD<T>;
    NodeD<T> *temp = First;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
   
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        
    }
    iCount++;
}

template <class T>
void DoublyLL<T> ::DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First; 
    }
    else
    {
        First = First->next;
        delete First->prev;      //delete First->prev;

        First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> ::DeleteLast()
{
    NodeD<T> *temp = First;

    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First = NULL;    
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        
    }
    iCount--;
}

template <class T>
void DoublyLL<T> ::InsertAtPos(T No,int iPos)
{

    
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD<T> *newn = new NodeD<T>;
        NodeD<T> *temp=First;
         
        for(int iCnt =1;iCnt <iPos-1;iCnt++)
        {
            temp = temp->next;
        }
        

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next->prev =newn;

        temp->next=newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyLL<T> ::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp=First;
         
        for(int iCnt =1;iCnt <iPos-1;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}


template <class T>
T DoublyLL<T> :: Minimum()
{
    T iMin=0;
    NodeD<T> *temp=First;

    if(temp == NULL)
    {
        return -1;
    }
    iMin = temp->data;

    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if((temp->data) < iMin)
        {
            iMin = temp->data;
        }
        temp=temp->next;
    }
    return iMin;
}

template <class T>
T DoublyLL<T> :: Maximum()
{
    T iMax=0;
    NodeD<T> *temp =First;
    if(temp == NULL)
    {
        return -1;
    }
    iMax = temp->data;
    
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if((temp->data) > iMax)
        {
            iMax=temp->data;
        }
        temp=temp->next;
    }
    return iMax;
}

template <class T>
T DoublyLL<T> :: Summation()
{
    T iSum=0;
    NodeD<T> *temp =First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        iSum=iSum + (temp->data);
        temp=temp->next;
    }
    return iSum;
}

template <class T>
int DoublyLL<T> :: FirstOccurance(T No)
{
    int iCnt = 1;
    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            break;
        }
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}
template <class T>
int DoublyLL<T> :: LastOccurance(T No)
{
    int iCnt = 1;
    int index = 0;
    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            index = iCnt;
        }
        iCnt++;
        temp=temp->next;
    }
    return index;
}
template <class T>
int DoublyLL<T> :: Frequency(T No)
{
    int Freq = 0;

    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            Freq++;
        }
        temp=temp->next;
    }
    return Freq;
}

//////////////////////////////////////////////////////////////////
//
// Doubly Circular Linked List
//
//////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> *First;
        struct NodeD<T> *Last;
        int iCount;
    public:
        DoublyCL();

        void InsertFirst(T ino);
        void InsertLast(T ino);
        void InsertAtPos(T ino,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();

        T Minimum();
        T Maximum();
        T Summation();
        int FirstOccurance(T);
        int LastOccurance(T);
        int Frequency(T);
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> ::Display()
{
    NodeD<T> *temp=First;

            cout<<"Elements of Linked List are: "<<"\n";

            for(int iCnt=1;iCnt <= iCount;iCnt++)
            {
                cout<<"| "<<temp->data<<" |<=> ";
                temp=temp->next;
            }
            cout<<"NULL"<<"\n";

}

template <class T>
int DoublyCL<T> ::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T> ::InsertFirst(T No)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
  
    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
    }
    Last ->next = First;
    First ->prev = Last;
    First = newn;
    iCount++;
}

template <class T>
void DoublyCL<T> ::InsertLast(T No)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
   
    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev=Last;
        Last=Last->next;
    }
    Last ->next = First;
    First ->prev = Last;
    iCount++;
}

template <class T>
void DoublyCL<T> ::DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
        
    }
    else
    {
        First = First->next;
        delete Last->next;      //delete First->prev;

        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> ::DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
        
    }
    else
    {
        Last = Last->prev;
        delete Last->next;      

        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> ::InsertAtPos(T No,int iPos)
{
    
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD<T> *temp=First;
         
        for(int iCnt =1;iCnt <iPos-1;iCnt++)
        {
            temp = temp->next;
        }
        NodeD<T> *newn = new NodeD<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next->prev =newn;

        temp->next=newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyCL<T> ::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp=First;
         
        for(int iCnt =1;iCnt <iPos-1;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}


template <class T>
T DoublyCL<T> :: Minimum()
{
    T iMin=0;
    NodeD<T> *temp = First;
    if(temp == NULL)
    {
        return -1;
    }
    iMin = temp->data;
    
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if((temp->data) < iMin)
        {
            iMin=temp->data;
        }
        temp=temp->next;
    }
    return iMin;
}

template <class T>
T DoublyCL<T> :: Maximum()
{
    T iMax=0;
    NodeD<T> *temp =First;
    if(temp == NULL)
    {
        return -1;
    }
    iMax = temp->data;
    
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if((temp->data) > iMax)
        {
            iMax=temp->data;
        }
        temp=temp->next;
    }
    return iMax;
}

template <class T>
T DoublyCL<T> :: Summation()
{
    T iSum=0;
    NodeD<T> *temp =First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        iSum=iSum + (temp->data);
        temp=temp->next;
    }
    return iSum;
}

template <class T>
int DoublyCL<T> :: FirstOccurance(T No)
{
    int iCnt = 1;
    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            break;
        }
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}

template <class T>
int DoublyCL<T> :: LastOccurance(T No)
{
    int iCnt = 1;
    int index = 0;
    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            index = iCnt;
        }
        iCnt++;
        temp=temp->next;
    }
    return index;
}

template <class T>
int DoublyCL<T> :: Frequency(T No)
{
    int Freq = 0;

    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            Freq++;
        }
        temp=temp->next;
    }
    return Freq;
}

//////////////////////////////////////////////////////////////////
//
// Searching and Sorting
//
//////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int Size;

        ArrayX(int);
        ~ArrayX();

        void Accept();
        void Display();


        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);
        bool CheckSorted();
        void BubbleSort();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
ArrayX <T>::ArrayX(int iNo)
{
    cout<<"Inside constructor to allocate memory\n";
    this->Size = iNo;
    this->Arr = new T[Size];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    cout<<"Inside destructor to deallocate memory\n";
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Inside Accept method\n";

    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < Size; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{
    cout<<"Inside Display method\n";

    cout<<"Elements of array are : \n";
    for(int iCnt = 0; iCnt < Size; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool ArrayX<T> :: LinearSearch(T No)
{
    bool flag =  false;

    for(int iCnt = 0;iCnt < Size; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BidirectionalSearch(T No)
{
    bool flag =  false;
    int iStart = 0;
    int iEnd = Size - 1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == No || Arr[iEnd]==No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
template <class T>
bool ArrayX<T> :: BinarySearch(T No)
{
    bool flag =  false;
    int iStart = 0;
    int iEnd = Size - 1;
    int iMid = 0; 
    while(iStart <= iEnd)
    {
        // iMid = (iStart + iEnd)/2;
        iMid = iStart + (iEnd-iStart)/2;
        if (Arr[iMid]== No || Arr[iStart]== No || Arr[iEnd] == No)
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iEnd = iMid+1;
        }
        else if(Arr[iMid] > No)
        {
            iStart = iMid -1;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0;iCnt < Size-1;iCnt++)
    {
        if(Arr[iCnt] < Arr[iCnt + 1])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0,j = 0;
    for(i = 0; i < Size; i++)
    {
        for(j = 0; j < Size-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void ArrayX<T>::SelectionSort()
{
    int i=0, j=0,min_index =0;
    T temp=0;

    for(i=0;i< Size-1;i++)
    {
        min_index = 1;
        for(j= i+1;j < Size; j++)
        {
            if(Arr[j] <Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i]=Arr[min_index];
        Arr[min_index]=temp;
    }
}

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i =0, j = 0;
    T selected = 0;

    for(i=1; i<Size;i++)
    {
        for(j = i-1, selected = Arr[i]; ((j>=0) && (Arr[j]>selected)) ;j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1]=selected;
        cout<<"Pass no : "<<i;
        Display();
    }
}

//////////////////////////////////////////////////////////////////
//
// Stack
//
//////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    private:
        NodeS<T> *First;
        int iCount;

    public:
        Stack();
        void Push(T no);
        int Pop();
        void Display();
        int Count();
};

template <class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T> :: Push(T no)  //Insert Last
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else 
    {
        NodeS<T> *temp = First;

        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
int Stack<T> ::Pop()       //DeleteLast
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First ->data;
        delete First;
        First=NULL;
    }
    else
    {
        NodeS<T> *temp = First;
        
        while(temp->next->next != NULL)
        {
            temp=temp->next;

        }
        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
    return Value;
}

template <class T>
void Stack<T> ::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display as stack is empty \n";
        return ;
    }
    cout<<"Elements of stack are : \n";

    NodeS<T> *temp=First;

    for(int iCnt=1; iCnt<=iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    
}

template <class T>
int Stack<T> ::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////
//
// Queue
//
//////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    private:
        NodeS<T> *First;
        int iCount;

    public:
        Queue();
        void Enqueue(T no);   //Insert Last
        int Dequeue();          //Delete First
        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Queue<T> :: Enqueue(T no)  //Insert Last
{
    NodeS<T> *newn =new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else 
    {
        NodeS<T> *temp = First;

        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
int Queue<T> ::Dequeue()       //DeleteFirst
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First ->data;
        delete First;
        First=NULL;
    }
    else
    {
        Value = First->data;
        NodeS<T> *temp = First;
        First= First->next;
        delete temp;
    }
    iCount--;
    return Value;
}

template<class T>
void Queue<T> ::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display as queue is empty \n";
        return ;
    }
    cout<<"Elements of queue are : \n";

    NodeS<T> *temp=First;

    for(int iCnt=1; iCnt<=iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    
}

template<class T>
int Queue<T> ::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////
//
// Main Function
//
//////////////////////////////////////////////////////////////////

int main()
{

    return 0;
}
