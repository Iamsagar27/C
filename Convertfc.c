#include<stdio.h>

float ConvertFC(float iDegree)
{
    float fRet = 0;

    fRet = 5.0/9.0 *(iDegree - 32);

    return fRet;
}

int main()
{
    float fFahrenheit = 0,fRet = 0;

    printf("Enter the degree in fahrenheit :\t");
    scanf("%f",&fFahrenheit);

    fRet = ConvertFC(fFahrenheit);

    printf("Degree in Celcius : %2f",fRet);

    return 0;
}