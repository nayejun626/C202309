#include <stdio.h>

double summation(int *a, int *b);
double subtraction(int *a, int *b);
double multiplication(int *a, int *b);
double division(int *a, int *b);

int main()
{
    double a = 2, b = 3;
    printf("%.0lf + %.0lf = %.2lf \n", a, b, summation(&a, &b));
    printf("%.0lf - %.0lf = %.2lf \n", a, b, subtraction(&a, &b));
    printf("%.0lf * %.0lf = %.2lf \n", a, b, multiplication(&a, &b));
    printf("%.0lf / %.0lf = %.2lf \n", a, b, division(&a, &b));

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

double multiplication(int *a, int *b)
{
    return *a * *b;
}

double division(int *a, int *b)
{
    return *a / *b;
}
