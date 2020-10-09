#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Eno;
    char EName[40];
    char EAddress[50];
    char PName[40];
    int PSalary;
    struct Node* next;
}emp[100];

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;


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

void InsertFirst(PPNODE Head)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    //newn->next=NULL;
    printf("Enter employee id :\t");
    scanf("%d",&(newn->Eno));
    
    printf("Enter the name :\t");
    scanf(" %[^'\n']s",newn->EName);

    printf("Enter the address :\t");
    scanf(" %[^'\n']s",newn->EAddress);

    printf("Enter project name :\t");
    scanf(" %[^'\n']s",newn->PName);

    printf("Enter salary :\t");
    scanf("%d",&(newn->PSalary));
    
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


void InsertLast(PPNODE Head)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->next=NULL;
    printf("Enter employee id :\t");
    scanf("%d",&(newn->Eno));
    
    printf("Enter the name :\t");
    scanf(" %[^'\n']s",newn->EName);

    printf("Enter the address :\t");
    scanf(" %[^'\n']s",newn->EAddress);

    printf("Enter project name :\t");
    scanf(" %[^'\n']s",newn->PName);

    printf("Enter salary :\t");
    scanf("%d",&(newn->PSalary));
    
    if(*Head == NULL)   
    {
        *Head = newn;
    }
    else        
    {
        PNODE temp = NULL;
        temp = *Head;       

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        
    }
}

void InsertAtPos(PPNODE Head, int pos)
{
    int size = 0, i = 0;
    PNODE temp = *Head;
    size = Count(*Head);

    PNODE newn= (PNODE)malloc(sizeof(NODE));
        
        printf("Enter employee id :\t");
        scanf("%d",&(newn->Eno));
        
        printf("Enter the name :\t");
        scanf(" %[^'\n']s",newn->EName);

        printf("Enter the address :\t");
        scanf(" %[^'\n']s",newn->EAddress);

        printf("Enter project name :\t");
        scanf(" %[^'\n']s",newn->PName);

        printf("Enter salary :\t");
        scanf("%d",&(newn->PSalary));

    
    
    if((pos < 1) || (pos > (size + 1)))      
    {
        return;
    }
    else if(pos == 1)       
    {
        InsertFirst(Head);
    }
    else if(pos == size + 1)    
    {
        InsertLast(Head);
    }
    else
    {    
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }        
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp  = *Head;
    
    if(*Head != NULL)
    {
        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    
    if(*Head == NULL)   
    {
        return;
    }
    else if((*Head) -> next == NULL)   
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

void DeleteAtPos(PPNODE Head, int pos)
{
    int size = 0,i = 0;
    size = Count(*Head);
    PNODE temp, temp2;
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
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("\n");
        printf("\n");
        printf("Emplyee number       : %d\n",Head->Eno);
        printf("Emplyee name         : %s\n",Head->EName);
        printf("Emplyee address      : %s\n",Head->EAddress);
        printf("Emplyee project name : %s\n",Head->PName);
        printf("Emplyee salary       : %d\n",Head->PSalary);
        Head = Head->next;
        printf("\n");
        printf("\n");
    }
}

int MaxSalary(PNODE Head)
{
    int iMax = 0;
    iMax = Head->PSalary;

    while(Head != NULL)
    {
        if(iMax < Head->PSalary)
        {
            iMax = Head->PSalary;
        }
        Head = Head ->next; 
    }
    return iMax;
}

int MinSalary(PNODE Head)
{
    int iMin = 0;
    iMin = Head->PSalary;

    while(Head != NULL)
    {
        if(iMin > Head->PSalary)
        {
            iMin = Head->PSalary;
        }
        Head = Head ->next; 
    }
    return iMin;
}

void Search(PNODE Head,int id)
{
    while(Head != NULL)
    {
        if(Head->Eno == id)
        {
            printf("\n");
            printf("\n");
            printf("Emplyee number       : %d\n",Head->Eno);
            printf("Emplyee name         : %s\n",Head->EName);
            printf("Emplyee address      : %s\n",Head->EAddress);
            printf("Emplyee project name : %s\n",Head->PName);
            printf("Emplyee salary       : %d\n",Head->PSalary);
            printf("\n");
            printf("\n");
        }
        Head = Head->next;   
    }
}
int main()
{
    PNODE First = NULL;
    int ch=0 , n=0 , pos=0 , iCnt=0 , iNo = 0;
    int i = 0,num;
    char name,pname;
    int sal;

    do
	{
		printf("\nMENU\n1.InsertFirst\n2.InsertLast\n3.DeleteFirst\n4.DeleteLast\n5.InsertAtPos\n6.DeleteAtPos\n7.Display\n8.Count\n");
        printf("9.MaxSalary\n10.MinSalary\n11.Search\n12.Exit\n");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
                    printf("Enter the count :\t");
                    scanf("%d",&n);
                    for(i = 1 ; i <=n; i++)
                    {
                        InsertFirst(&First);
                    }
                    break;
			break;

			case 2:
                    printf("Enter the count :\t");
                    scanf("%d",&n);
                    for(i = 1 ; i <=n; i++)
                    {
                        InsertLast(&First);
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
                    InsertAtPos(&First,num);
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
			
            case 9:
                    iCnt = MaxSalary(First);
                    printf("Maximum Salary : %d",iCnt);
                    break;

            case 10:
                    iCnt = MinSalary(First);
                    printf("Minmum Salary : %d",iCnt);
                    break;        
            
            case 11:
                    printf("Enter id :\t");
                    scanf("%d",&iNo);
                    Search(First,iNo);
                    break;

            }
	}while(ch!=12);
}









