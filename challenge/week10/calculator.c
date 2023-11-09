#include <stdio.h>

double summation(double *a, double *b);
double subtraction(double *a, double *b);
double multiplication(double *a, double *b);
double division(double *a, double *b);

int main()
{
    double a = 2, b = 3;
    printf("%.0lf + %.0lf = %.2lf \n", a, b, summation(&a, &b));
    printf("%.0lf - %.0lf = %.2lf \n", a, b, subtraction(&a, &b));
    printf("%.0lf * %.0lf = %.2lf \n", a, b, multiplication(&a, &b));
    printf("%.0lf / %.0lf = %.2lf \n", a, b, division(&a, &b));

    return 0;
}

double summation(double *a, double *b)
{
    return *a + *b;
}

double subtraction(double *a, double *b)
{
    return *a - *b;
}

double multiplication(double *a, double *b)
{
    return *a * *b;
}

double division(double *a, double *b)
{
    return *a / *b;
}
