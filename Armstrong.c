/*
Accept number form user and check whether that number is armstong or not
input 	: 153
output	: true (1^3 + 5^3 + 3^3) = 153 

input	: 2145
output	: false (2^4 + 1^4 + 4^4 +5^4) != 2145

*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

int Count(int iNo)
{ 
    int iCnt = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    while(iNo != 0)
    {
        iCnt++;
        iNo /= 10;
    }
    return iCnt;
}

BOOL Armstrong(int iNo)
{
    int iDigit = 0 , iSum = 0 , iCnt= 0 , iMult =1 ;
    int i = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }
    int temp = iNo;

    int Cnt = Count(iNo);
    
    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iMult = 1;
        for(i = 1 ; i <=Cnt ; i++)
        {
            iMult = iMult * iDigit;
        }
        iSum = iSum + iMult;

        if(iSum > temp)
        {
            break;
        }
        iNo /= 10;    
    }

    if(iSum == temp)
    {
        return TRUE;;
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

    bRet = Armstrong(number); 
    if(bRet == TRUE)
    {
        printf("The number is Armstrong");
    }
    else
    {
        printf("The number is not Armstrong");
    }

    return 0;
}




