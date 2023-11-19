#include <stdio.h>

int main()
{
    /*
    int a = 5;
    int *a_ptr = &a;
    printf("a_ptr (a의 주소) = %p\n", a_ptr);
    printf("&a_ptr (a_ptr의 주소) = %p\n", &a_ptr);
    printf("\n");

    int **a_a_ptr = &a_ptr; // 이중 포인터
    printf("a_a_ptr (a_ptr의 주소) = %p\n", a_a_ptr);
    printf("a_a_ptr (a_a_ptr의 주소) = %p\n", &a_a_ptr);
    printf("a_a_ptr (a_a_ptr이 갖는 주소에 역참조 = a_ptr 주소의 역참조 = a의 주소) = %p\n", *a_a_ptr);
    printf("\n");

    printf("**a_a_ptr (p) = %p\n", **a_a_ptr);
    printf("**a_a_ptr (d) = %d\n", **a_a_ptr);
    return 0;
    */

    /* int a = 10;
    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;
    printf("***ppp = %d\n", ***ppp);
    printf("*p = %d\n", *p); */

    int *p[5];
    int a = 10;

    for (int i = 0; i < 5; i++)
    {
        p[i] = &a;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d: p[%d] = %p, *p[%d] = %d\n", i, i, p[i], i, *p[i]);
    }
    return 0;

    /*
     */
}