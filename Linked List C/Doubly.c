#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}NODE , *PNODE , **PPNODE;

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d | <->",Head->data);
        Head = Head->next;
    }
    printf("NULL");
    printf("\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void InsertFirst(PPNODE Head , int value)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = value ;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head , int value)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else 
    {
        while(temp->next != NULL)
        {
            temp = temp->next ;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

void InsertAtPos(PPNODE Head , int value , int pos)
{
    int size= 0 , i = 0 ;
    size = Count(*Head);
    PNODE temp = *Head;
    PNODE newn = NULL;

    if((pos < 1) || (pos >(size+1)))
    {
        return;
    }

    if(pos == 1)
    {
        InsertFirst(Head,value);
    }
    else if(pos == (size+1))
    {
        InsertLast(Head,value);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = value;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1 ; i< pos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn ;
        newn->prev = temp ;
    }
}

void DeleteFirst(PPNODE Head)
{
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
        (*Head)=(*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

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
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE Head , int pos)
{
    int size = 0 , i = 0 ;
    size = Count(*Head);
    PNODE temp = NULL ;

    if((pos < 1) || (pos > size))
    {
        return;
    }

    if(pos == 1)
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

        for(i = 1 ; i<pos-1 ; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE First = NULL;

    int choice = 0 ,node = 0 , i = 0 , data = 0 , pos = 0 , ret = 0;

    
    do
    {
        printf("\n1.InsertFirst");
        printf("\n2.InsertLast");
        printf("\n3.InsertAtPos");
        printf("\n4.DeleteFirst");
        printf("\n5.DeleteLast");
        printf("\n6.DeleteAtPos");
        printf("\n7.Display");
        printf("\n8.Count");
        printf("\n9.Exit");

        printf("\nEnter your choice :\t");
        scanf("%d",&choice); 

        switch (choice)
        {
            case 1:
                    printf("How many nodes :\t");
                    scanf("%d",&node);
                    for(i = 1 ; i <= node ; i++)
                    {
                        printf("Enter the element :\t");
                        scanf("%d",&data);
                        InsertFirst(&First,data);
                    }
                    break;

            case 2:
                    printf("How many nodes :\t");
                    scanf("%d",&node);
                    for(i = 1 ; i <= node ; i++)
                    {
                        printf("Enter the element :\t");
                        scanf("%d",&data);
                        InsertLast(&First,data);
                    }
                    break;

            case 3:
                    printf("Enter the position :\t");
                    scanf("%d",&pos);
                    printf("Enter the element :\t");
                    scanf("%d",&data);
                    InsertAtPos(&First,data,pos);
                    break;

            case 4:
                    DeleteFirst(&First);
                    break;

            case 5:
                    DeleteLast(&First);
                    break;

            case 6:
                    printf("Enter the position :\t");
                    scanf("%d",&pos);
                    DeleteAtPos(&First,pos);
                    break;

            case 7:
                    Display(First);
                    break;

            case 8:
                    ret = Count(First);
                    printf("The number of nodes are : %d",ret);
                    break;
        
            default:
                    break;
        }
    }while(choice!=9);

    return 0;
}







