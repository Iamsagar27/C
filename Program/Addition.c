#include<stdio.h>

int Addition(int iNo1,int iNo2)
{
    int iRet = 0;

    iRet = iNo1 + iNo2;

    return iRet;

}

int main()
{
    int iValue1 = 0 ,iValue2 = 0 , iResult = 0;

    printf("Enter the first number :\t");
    scanf("%d",&iValue1); 

    printf("Enter the second number :\t");
    scanf("%d",&iValue2);

    iResult = Addition(iValue1,iValue2);

    printf("The addition is \t\t%d ",iResult); 

    return 0;
}