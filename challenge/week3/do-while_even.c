#include <stdio.h>

int main()
{
    int i = 0; // i 에 0저장
    do
    {
        i++;            // 1증가
        if (i % 2 == 0) // i가 짝수일 때
        {
            continue;
        }
        printf("Hello world%d\n", i);
    } while (i < 10); // i가 10미만일 때 반복문 실행
    return 0;
}
