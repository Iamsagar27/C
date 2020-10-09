#include<stdio.h>

int HappyNumber(int num)
{
    int rem = 0, sum = 0;

    while(sum != 1 && sum !=4)
    {
        sum = 0;
        while (num > 0)
        {
            rem = num % 10;
            sum = sum + (rem * rem);
            num /=10;
        }
        num = sum;
    }
    if(sum == 1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
}

int main()
{
    int iNum = 0,iResult = iNum;

    printf("Enter the number :");
    scanf("%d",&iNum);

    iResult = HappyNumber(iNum);

    if(iResult == 1)
    {
        printf("Happy number");
    }
    else
    {
        printf("Not a happy number");
    }
    
    
    return 0;
}