#include <stdio.h>

double summation(int *a, int *b);
double subtraction(int *a, int *b);
double multification(int *a, int *b);
double division(int *a, int *b);

int main()
{
    double a = 2, b = 3;
    double result;
    summation(&a, &b, &result);
    printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

    subtraction(&a, &b, &result);
    printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

    multification(&a, &b, &result);
    printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

    division(&a, &b, &result);
    printf("%.0lf / %.0lf = %.2lf \n", a, b, result);

    return 0;
}

double summation(int *a, int *b)
{
    return *a + *b;
}
double subtraction(int *a, int *b)
{
    return *a - *b;
}
double multification(int *a, int *b)
{
    return *a * *b;
}
double division(int *a, int *b)
{
    return *a / *b;
}