#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void OneDimensional()
{
    int size = 0 , i = 0;
    int *Arr = NULL;

    printf("Enter the size :\t");
    scanf("%d",&size);

    Arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements :\n");
    for(i = 0 ; i<size ; i++)
    {
        scanf("%d",&Arr[i]);
    }

    printf("Entered elements :\n");
    for(i = 0 ; i<size ; i++)
    {
        printf("| %d |\t",Arr[i]);
    }

    free(Arr);

}

void TwoDimensional()
{
    int row = 0 , col = 0;
    int **Arr = NULL;                              //step 1                     
    int i = 0 ,j = 0;
    
    printf("Enter the row :\t");
    scanf("%d",&row);

    printf("Enter the col :\t");
    scanf("%d",&col);

    Arr = (int **)malloc(row *sizeof(int *));     //step 2

    for(i = 0 ; i<row ; i++)
    {
        Arr[i] =(int *)malloc(col * sizeof(int));  //step 3
    }

    printf("Enter the elements :\n");
    for(i = 0 ; i<row ; i++)
    {
        for(j = 0 ; j<col ; j++)
        {
            scanf("%d",&Arr[i][j]);
        }
    }

    printf("Entered elements :\n");
    for(i = 0 ; i<row ; i++)
    {
        for(j = 0 ; j<col ; j++)
        {
            printf("| %d |\t",Arr[i][j]);
        }
        printf("\n");
        printf("------------------------------\n");
    }

    //Memory deallocation of step 3
    for(i = 0 ; i<row ; i++)
    {
        free(Arr[i]); 
    }

    //Memory deallocation of step 2
    free(Arr);

}

void ThreeDimensional()
{
    int first = 0 , second = 0 , third = 0 ;
    int i = 0 , j = 0 , k = 0 ;
    int ***Arr = NULL;  //step 1

    printf("Enter the values of three dimensions:\t");
    scanf("%d%d%d",&first,&second,&third);

    //step 2
    Arr = (int ***)malloc(first * sizeof(int**));

    //step 3
    for( i = 0; i<first ; i++) 
    {
        Arr[i] = (int **)malloc(second * sizeof(int *));
    }  

    //step 4
    for( i = 0; i<first ; i++) 
    {
        for( j = 0; j<second ; j++) 
        {
            Arr[i][j] = (int *)malloc(third * sizeof(int));
        }
    }

    //Accept the values
    printf("Enter the elements  :\n");
    for(i = 0 ; i <first ; i++)
    {
        for(j = 0 ; j <second ; j++)
        {
            for(k = 0 ; k <third ; k++)
            {
                scanf("%d",&Arr[i][j][k]);
            }
        }   
    }

    printf("Entered elements  :\n");
    for(i = 0 ; i <first ; i++)
    {
        for(j = 0 ; j <second ; j++)
        {
            for(k = 0 ; k <third ; k++)
            {
                printf("| %d |\t",Arr[i][j][k]);
            }
            printf("\n");
        }  
        printf("\n"); 
        printf("------------------------------\n");
    }


    //Deallocation of step 4
    for( i = 0; i<first ; i++) 
    {
        for( j = 0; j<second ; j++) 
        {
            free(Arr[i][j]);
        }
    }

    //Deallocation of step 3
    for( i = 0; i<first ; i++) 
    {
       free(Arr[i]);
    }

    //Deallocation of step 2
    free(Arr);

}

int main()
{
    int choice = 0;

    printf("Enter the choice :\t");
    printf("\n1: One Dimensional\n2:Two Dimensional\n3:Three Dimensional\n");
    printf("The choice :\t");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
                OneDimensional();
                break;

        case 2:
                TwoDimensional();
                break;

        case 3:
                ThreeDimensional();
                break;
       
        default:
                printf("Wrong Choice\n");
                break;
    }

    return 0;
}



















