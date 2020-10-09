#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head , PNODE Tail)
{
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }

    do
    {
        printf("| %d | ->",Head->data);
        Head = Head->next;
    }while(Head != Tail->next);
}

int Count(PNODE Head, PNODE Tail)
{
    int iCnt = 0;

    if((Head == NULL) && (Tail == NULL))
    {
        return -1;
    }

    do
    {
        iCnt++;
        Head = Head->next;
    }while(Head != Tail->next);

    return iCnt;
}

void InsertFirst(PPNODE Head , PPNODE Tail, int value)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = value;
    newn->next = NULL ;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next =*Head;
        (*Head)->prev = newn;
        *Head = (*Head)->prev;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

void InsertLast(PPNODE Head , PPNODE Tail, int value)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = value;
    newn->next = NULL ;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        newn->prev = *Tail;
        *Tail =(*Tail)->next;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

void InsertAtPos(PPNODE Head , PPNODE Tail, int value, int pos)
{
    int count = 0 , i = 0;
    PNODE newn = NULL;
    PNODE temp = *Head;

    count = Count(*Head,*Tail);

    if((pos < 1) || (pos >(count+1)))
    {
        return;
    }

    if(pos == 1)
    {
        InsertFirst(Head,Tail,value);
    }
    else if(pos == (count+1))
    {
        InsertLast(Head,Tail,value);
    }
    else
    {
       newn = (PNODE)malloc(sizeof(NODE));
       newn->data = value;
       newn->next =NULL;
       newn->prev = NULL;

        for(i = 0 ; i<pos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return ;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
        return;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);

        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }    
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = *Head;

    if((*Head == NULL) && (*Tail == NULL))
    {
        return ;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
        return;
    }
    else
    {
        *Tail = (*Tail)->prev;
        free((*Tail)->next);

        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}

void DeleteAtPos(PPNODE Head , PPNODE Tail, int pos)
{
    int i = 0 ,count = 0;
    PNODE temp = *Head;    

    count = Count(*Head,*Tail);

    if((pos < 1) || (pos > count))
    {
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(pos == count)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        for(i = 1 ; i < pos-1 ; i++)
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
    PNODE Last = NULL;

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
        printf("\n9.Exit\n");

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
                        InsertFirst(&First,&Last,data);
                    }
                    break;

            case 2:
                    printf("How many nodes :\t");
                    scanf("%d",&node);
                    for(i = 1 ; i <= node ; i++)
                    {
                        printf("Enter the element :\t");
                        scanf("%d",&data);
                        InsertLast(&First,&Last,data);
                    }
                    break;

            case 3:
                    printf("Enter the position :\t");
                    scanf("%d",&pos);
                    printf("Enter the element :\t");
                    scanf("%d",&data);
                    InsertAtPos(&First,&Last,data,pos);
                    break;

            case 4:
                    DeleteFirst(&First,&Last);
                    break;

            case 5:
                    DeleteLast(&First,&Last);
                    break;

            case 6:
                    printf("Enter the position :\t");
                    scanf("%d",&pos);
                    DeleteAtPos(&First,&Last,pos);
                    break;

            case 7:
                    Display(First,Last);
                    break;

            case 8:
                    ret = Count(First,Last);
                    printf("The number of nodes are : %d",ret);
                    break;
        
            default:
                    break;
        }
    }while(choice!=9);



    return 0;
}









