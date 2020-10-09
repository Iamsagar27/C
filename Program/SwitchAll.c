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


void InsertFirst(PPNODE Head , int value)
{   
    PNODE newn =NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = value;
    newn->next = NULL;


    if(*Head == NULL)   
    {
        *Head = newn;
    }
    else                
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

    if(*Head == NULL)   
    {
        *Head = newn;
    }
    else                
    {
        temp = *Head; 
      
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
    int  ch = 0 ,n=0 , pos=0 , iCnt=0 , iNo = 0;
    int i = 0,num;
    char choice = 0 ;

    do
	{
		printf("\nMENU\n1.Singly Linear Linked List\n2.Doubly Linear Linked List\n3.Singly Circular Linked List\n4.Doubly Circular Linked List\n5.Exit\n");
		printf("Enter your choice");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'A':
                
                do
                {
                    printf("\nMENU\n1.InsertFirst\n2.InsertLast\n3.DeleteFirst\n4.DeleteLast\n5.InsertAtPos\n6.DeleteAtPos\n7.Display\n8.Count\n9.Exit\n");
                    printf("Enter your choice");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1:
                                printf("Enter the count :\t");
                                scanf("%d",&n);
                                for(i = 1 ; i <=n; i++)
                                {
                                    printf("Enter the element :\t");
                                    scanf("%d",&iNo);
                                    InsertFirst(&First,iNo);
                                }
                                break;
                        break;

                        case 2:
                                printf("Enter the count :\t");
                                scanf("%d",&n);
                                for(i = 1 ; i <=n; i++)
                                {
                                    printf("Enter the element :\t");
                                    scanf("%d",&iNo);
                                    InsertLast(&First,iNo);
                                }
                                break;

                        case 3:
                                DeleteFirst(&First);
                                break;
                    
                        case 4:
                                DeleteLast(&First);
                                break;
                        
                        case 5:
                                printf("Enter the pos :\t");
                                scanf("%d",&num);
                                printf("Enter the element :\t");
                                scanf("%d",&iNo);
                                InsertAtPos(&First,iNo,num);
                                break;

                        case 6:
                                printf("Enter the pos :\t");
                                scanf("%d",&iNo);
                                DeleteAtPos(&First,iNo);
                                break;

                        case 7:
                                Display(First);
                                break;

                        case 8:
                                iCnt = Count(First);
                                printf("Number of elements in list : %d \n",iCnt);
                                break;
                        }
                }while(ch!=9);
                break;            
		
            case 'B' :
	
    
    
        }
    }while(choice!=5);
}

































