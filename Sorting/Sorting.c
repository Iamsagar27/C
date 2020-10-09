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
    int size = 0 , i = 0 , ch = 0;
    int *Arr = NULL;

    do
    {
        printf("\n1.BubbleSort");
        printf("\n2.SelectionSort");
        printf("\n3.InsertionSort");
        printf("\n4.Exit");
        
        printf("\nEnter your choice :\t");
        scanf("%d",&ch); 

        switch(ch)
        {
                case 1:
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
                    
                        break;

                case 2:
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
                    
                        break;
                
                case 3:
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
                    
                        break;
            }
            
    }while(ch != 4);
    return 0 ;

}
