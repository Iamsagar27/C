/* Write a program to display below patterm

input 	: 6		6
output	:

		&	*	*	*	*	*
		*	&	1	2  	3	*
		*  	A  	&	4	5	*
		*	B 	C   &	6	*
		*   D   E   F	&	*
		*   *   *	*	*	&
*/

#include<stdlib.h>
#include<stdio.h>

void Pattern(int iRow , int iCol)
{
    int i = 0 ,j = 0 ,iCnt = 1;
    char ch = 'A';

    if(iRow != iCol || iRow <= 0 || iCol <= 0)
    {
        return ;
    }

    for(i = 1 ; i<=iRow ; i++)
    {
        for(j = 1 ; j<=iCol ; j++)
        {
            if(i == j)
            {
                printf("&\t");
            }
            else if((j == 1) || ( i == 1) || (j == iCol) || (i == iRow) )
            {
                printf("*\t");
            }
            else if(i< j)
            {
                printf("%d\t",iCnt);
                iCnt++;
            }
            else if(i> j)
            {
                printf("%c\t",ch);
                ch++;
            }
        }
        printf("\n");
    }


}

int main()
{
    int row = 0  , col = 0;

    printf("Enter the row :\t");
    scanf("%d",&row);

    printf("Enter the col :\t");
    scanf("%d",&col);

    Pattern(row,col);

    return 0;
}