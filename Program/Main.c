#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

/*
    Allocate memory for node
    Initialize that node
    Check whether linkedlist is emptty or not
    Insert th node accordingly
*/

void InsertFirst(PPNODE Head , int value)
{   
    PNODE newn =NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = value;
    newn->next = NULL;

    if(*Head == NULL)   // IF linked list is empty
    {
        *Head = newn;
    }
    else                //If linked list contains one element
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    printf("\n");
    while(Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head ->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt=0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head ->next;
    }
    return iCnt;
}

void InsertLast(PPNODE Head , int value)
{   
    PNODE newn =NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = value;
    newn->next = NULL;

    if(*Head == NULL)   // IF linked list is empty
    {
        *Head = newn;
    }
    else                //If linked list contains one element
    {
        temp = *Head; // Store address of first node
        //travel till last node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head != NULL)
    {
        *Head = (*Head)->next;
        free(temp);
    }
}


void DeleteLast(PPNODE Head)
{
    PNODE temp = NULL;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        temp = *Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;    
    }
}


void InsertAtPos(PPNODE Head ,int value ,int pos)
{
    int i = 0,size = 0;
    PNODE temp = *Head;
    PNODE newn = NULL;

    size = Count(*Head);

    if((pos < 1) || (pos > (size+1)))
    {
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(Head , value);
    }
    else if(pos == (size + 1))
    {
        InsertLast(Head , value);
    }
    else
    {
        newn= (PNODE)malloc(sizeof(NODE));
        newn->data = value;

        for(i = 1 ; i< pos-1 ;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next=newn;
    }
}

void DeleteAtPos(PPNODE Head ,int pos)
{
    int i = 0,size = 0;
    PNODE temp = NULL;
    PNODE temp2 = NULL;
   
    size = Count(*Head);

    if((pos < 1) || (pos > size))
    {
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(pos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        temp = *Head;

        for(i = 1 ; i< pos-1 ;i++)
        {
            temp = temp->next;
        }
        temp2 =temp->next; 
        temp->next=temp2->next;
        free(temp2);   
    }
}

int main()
{
    PNODE First = NULL;
    int no=0;
    int iRet =0;

    printf("Enter the number :\t");
    scanf("%d",&no);
    InsertFirst(&First,no);

    printf("Enter the number :\t");
    scanf("%d",&no);
    InsertFirst(&First,no);

    printf("Enter the number :\t");
    scanf("%d",&no);
    InsertFirst(&First,no);

    Display(First);

    iRet = Count(First);
    printf("\nNumber of elements : %d\n",iRet);

    printf("\nEnter the number :\t");
    scanf("%d",&no);
    InsertLast(&First,no);

    printf("Enter the number :\t");
    scanf("%d",&no);
    InsertLast(&First,no);

    Display(First);

    iRet = Count(First);
    printf("\nNumber of elements : %d\n",iRet); 

    DeleteFirst(&First);   

    Display(First);

    iRet = Count(First);
    printf("\nNumber of elements : %d\n",iRet);

    DeleteLast(&First);   

    Display(First);

    iRet = Count(First);
    printf("\nNumber of elements : %d\n",iRet); 

    printf("Enter the number :\t");
    scanf("%d",&no);
    InsertAtPos(&First,no,3);

    Display(First);

    DeleteAtPos(&First,2);

    Display(First);

    
    return 0;
}










