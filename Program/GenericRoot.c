/*Accept number from user and  return generic root.

input	: 789
output : 6
		7+8+9 = 24 -> 2+4 = 6

input	:	8
output	:	8
*/

#include<stdio.h>
#include<stdlib.h>

int GenericRoot(int iNo)
{
    int iSum = 0;
    iSum = iNo;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    while(iSum > 9)
    {
        iNo = iSum;
        iSum = 0;
        while(iNo != 0)
        {
            iSum = iSum +(iNo % 10);
            iNo /= 10;
        }
        
    }
    return iSum;
}

int main()
{
    int number = 0  , iRet = 0;

    printf("Enter the number :\t");
    scanf("%d",&number);

    iRet = GenericRoot(number);

    printf("Generic root : %d",iRet);

    return 0;
}







