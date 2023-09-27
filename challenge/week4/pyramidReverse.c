#include <stdio.h>

int main(void)
{
    int floor;                             // 사용자로부터 입력받을 층수
    printf("몇 층을 쌓겠습니까?(5~100):"); // 5에서 100까지 값 받기
    scanf("%d", &floor);

    for (int i = floor; i > 0; i--)
    {
        for (int j = 0; j < floor - i; j++) // j선언 j가 층수-1만큼
        {
            printf("s"); // s출력
        }
        for (int k = 0; k < (i * 2) - 1; k++) // k선언 k가 (i*2)-1 만큼
        {
            printf("*"); // 별 출력
        }
        printf("\n"); // 개행 출력
    }

    return 0;
}