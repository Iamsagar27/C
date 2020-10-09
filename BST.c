#include<stdio.h>
#include<stdlib.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Root ,int value)
{
    PNODE newn = NULL;
    PNODE temp = *Root;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = value;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Root == NULL)
    {
        *Root = newn;
    }
    else
    {
        while(1)
        {
            if((temp->data) == value)
            {
                printf("Element already exist.");
                free(newn);
                break;
            }

            if(value < (temp->data))
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp= temp->lchild;
            }
            else if(value > (temp->data))
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
        }  
    }
}

BOOL Search(PNODE Root,int value)
{
    if(Root !=NULL)
    {
        if(Root->data == value)
        {
            break;
        }

        if(value < Root->data)
        {
            Root = Root->lchild;
        }
        else
        {
            Root = Root->rchild;
        }
    }

    if(Root == NULL)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

// 1.LDR  2.DLR  3.LRD

int Inorder(PNODE Root)
{
    if(Root != NULL)
    {
        Inorder(Root->lchild);
        printf("%d\t",Root->data);
        Inorder(Root->rchild);
    }
}

int Preorder(PNODE Root)
{
    if(Root != NULL)
    {
        printf("%d\t",Root->data);
        Preorder(Root->lchild);
        Preorder(Root->rchild);
    }
}

int Postorder(PNODE Root)
{
    if(Root != NULL)
    {
        Postorder(Root->lchild);
        Postorder(Root->rchild);
        printf("%d\t",Root->data);
    }
}

int main()
{
    PNODE First = NULL;
    BOOL bRet = FALSE;
    
    int choice = 1;
    int no = 0;
    
    while(choice != 0)
    {
        printf("Enter your choice : \n");
        printf("1 : Insert into BST\n");
        printf("2 : Search the element in BST\n");
        printf("3 : Inorder display\n");
        printf("4 : Preorder display\n");
        printf("5 : Postorder display\n");
        printf("0 : Exit the applcatoion\n");
        
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter number to insert\n");
                scanf("%d",&no);
                Insert(&First,no);
                break;
                
            case 2:
                printf("Enter the element to search\n");
                scanf("%d",&no);
                bRet = Search(First, no);
                if(bRet == TRUE)
                {
                    printf("Element is there in BST\n");
                }
                else
                {
                    printf("There is no element in BST\n");
                }
                break;
                
            case 3:
                Inorder(First);
                break;
                
            case 4:
                Preorder(First);
                break;
                
            case 5:
                Postorder(First);
                break;
            
            case 0:
                printf("Thank you for using the application\n");
                break;
                
            default:
                printf("Wrong choice");
                break;
        }
    }
    return 0;
} 













