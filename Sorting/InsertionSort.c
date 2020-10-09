#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void InsertionSort(int arr[], int n) 
{      
    int i = 0, key = 0, j = 0; 
   
    for (i = 1; i < n; i++)     
    {         
        key = arr[i];         
        j = i-1; 
        
        while (j >= 0 && arr[j] > key)         
        {             
            arr[j+1] = arr[j];             
            j = j-1;         
        }         
        arr[j+1] = key;     
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

    InsertionSort(Arr,size);

    free(Arr);

    return 0 ;

}

