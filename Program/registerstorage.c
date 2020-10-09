#include<stdio.h>

void fun()
{
    int i ;
    auto int j;
    auto int k = 11;
    register int x;
    register int y = 21;

    printf("%d\n",i);
    printf("%d\n",j);
    printf("%d\n",k);
    printf("%d\n",x);
    printf("%d\n",y);
}

int main()
{
    fun();

    return 0;
}