#include <stdio.h>

int main()
{
    int floor;                              // 사용자로부터 입력받을 층수
    printf("몇 층으로 쌓을까요?: (5~100)"); // 5에서 100까지 받기
    scanf("%d", &floor);

    for (int i = 0; i < floor; i++) // 층수만큼 반복
    {
        for (int j = 0; j < floor - 1 - i; j++) // 공백(s)출력
        {
            printf("s");
        }
        for (int k = 0; k < (i * 2) + 1; k++) // 별 출력
        {
            printf("*");
        }
        printf("\n"); // 개행 출력
    }
    return 0;
}
