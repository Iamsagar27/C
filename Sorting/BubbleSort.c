#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void BubbleSort(int arr[], int n) 
{     
    int i = 0, j = 0, temp = 0 ; 

    for(i = 0; i < n; i++)     
    {         
        for(j = 0; j < n-i-1; j++)         
        {             
            if( arr[j] > arr[j+1])             
            {                 
                temp = arr[j];                 
                arr[j] = arr[j+1];                
                arr[j+1] = temp;             
            }          
        } 
    } 

    printf("\nAfter sorting :\n");
    for(i = 0; i < n; i++)     
    { 
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int size = 0 , i = 0;
    int *Arr = NULL;

    printf("How many elements in an array:\t");
    scanf("%d",&size);

    Arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements :");
    for(i = 0 ; i < size ; i++)
    {
        scanf("%d",&Arr[i]);
    }

    printf("The elements in array:\n");
    for(i = 0 ; i < size ; i++)
    {
        printf("%d\t",Arr[i]);
    }

    BubbleSort(Arr,size);

    free(Arr);

    return 0 ;

}


