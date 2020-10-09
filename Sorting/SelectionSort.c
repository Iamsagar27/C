#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void SelectionSort(int arr[], int n) 
{      
    int index_of_min = 0; 
    int  i = 0 , j = 0;
    
    for( i = 0; i < n ; i++)  
    {       
        index_of_min = i;       
        for(int j = i; j < n; j++)       
        {             
            if(arr[index_of_min] > arr[j])            
            {                
                index_of_min = j;            
            }       
        }       
        int temp = arr[i];       
        arr[i] = arr[index_of_min];       
        arr[index_of_min] = temp;  
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

    SelectionSort(Arr,size);

    free(Arr);

    return 0 ;

}
