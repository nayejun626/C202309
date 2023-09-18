#include <stdio.h>

int main()
{
    int i = 0;     // i 에 0저장
    while (i < 10) // i가  10 미만일 때
    {
        i++;            // 증감연산자
        if (i % 2 == 0) // i가 짝수일 때
        {
            continue;
        }
        printf("Hello world%d\n", i); // 출력
    }
    return 0;
}
