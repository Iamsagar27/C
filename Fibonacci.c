/*
	Accept number and display that number of elemnts from fibonacci series

input	: 10
output	: 0  1  1  2  3  5  8  13  21  34
*/

#include<stdio.h>
#include<stdlib.h>

void Fibonacci(int iNo)
{
    int first = 0 , second = 1, third = 0 , i = 0;

    for(i = 1 ; i <= iNo ; i++)
    {
        printf("%d\t",first);
        third = first + second;
        first = second;
        second = third;
    }
}


int main()
{
    int number = 0 ;

    printf("Enter the number :\t");
    scanf("%d",&number);

    Fibonacci(number);

    return 0;
}
