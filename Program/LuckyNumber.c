/*
Accept N number and display all lucky member from that N munber .
Lucky member is a number whose value is addition of its neighbor.

input	: N = 10
	5	8	12	4	-8	8  10	2	2	0

output	: 12	4	10	 2

*/

#include<stdio.h>
#include<stdlib.h>

void Lucky(int arr[],int iSize)
{
    int i = 0;
    int first = 0 , second = 0 , third = 0;

    printf("The elements : \t");
    for( i = 1 ; i<=iSize ; i++)
    {
        first = arr[i];
        second = arr[i+1];
        third = arr[i+2];
        if(second == (first + third))
        {
            printf("%d\t",second);
        }
    }
}

int main()
{
    int number = 0 , i = 0;
    int *Arr = NULL;

    printf("Enter number of elements:\t");
    scanf("%d",&number);

    Arr = (int *)malloc(number * sizeof(int));

    printf("Enter the elements : \t");
    for( i = 1 ; i<= number ; i++)
    {
        scanf("%d",&Arr[i]);
    }

    Lucky(Arr,number);

    return 0; 
}