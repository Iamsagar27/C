#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head, PPNODE Tail, int value)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((*Head ==NULL) && (*Tail == NULL))       // Linked list is empty
    {
        *Head = newn;
        *Tail = newn;
    }
    else            // Linked list contains atleast one node
    {
        newn->next = *Head;
        (*Head)->prev = newn;
        *Head = (*Head)->prev;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

int Frequency(PNODE Head, PNODE Tail , int iNo) 
{  
    PNODE temp = Head ;
    int iCnt = 0;

    while (temp != NULL)
    {
        if( temp->data == iNo)
        {
            iCnt++;
        }
        temp = temp->next;
    }
    return iCnt;    
}

int main() 
{  
    PNODE First = NULL;  
    PNODE Last = NULL; 
 
    int iRet = 0; 
 
    InsertFirst(&First,&Last,101);  
    InsertFirst(&First,&Last,51);  
    InsertFirst(&First,&Last,21);  
    InsertFirst(&First,&Last,11);  
    InsertFirst(&First,&Last,51);  
    InsertFirst(&First,&Last,21);  
    InsertFirst(&First,&Last,11);  
    InsertFirst(&First,&Last,51);  
    InsertFirst(&First,&Last,11);    
    
    iRet = Frequency(First,Last,51); 
 
    printf("Frequency of 51 is %d", iRet);

    return 0; 
}










