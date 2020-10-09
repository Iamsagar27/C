/*
Accept number from user and  check whther that number is strong number or not.
Strong number is such a number whose summation of factorial of digit is the number.

input	: 145
output	: 1! + 4! + 5! = 145

input	:190
output	:1! + 9! + 0! != 190

*/

#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

BOOL StrongNumber(int iNo)
{
    int iFact = 1 , iDigit = 0 , iSum = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }
    int temp = iNo;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        
        while(iDigit != 0)
        {
            iFact = iFact * iDigit;
            iDigit--;
        }
        iSum = iSum + iFact ;
        if(iSum > temp)
        {
            break;
        }
        iNo /=10;
        iFact = 1;
    }

    if(iSum == temp)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    



}

int main()
{
    int number  = 0 ;
    BOOL bRet = FALSE;
    printf("Enter the number :\t");
    scanf("%d",&number);

    bRet = StrongNumber(number); 
    if(bRet == TRUE)
    {
        printf("The number is Strong");
    }
    else
    {
        printf("The number is not Strong");
    }

    return 0;
}
