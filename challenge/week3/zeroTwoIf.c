#include <stdio.h>

int main()
{
    int num = 0;
    printf("숫자를 입력하시오: ");
    scanf("%d", &num); // 숫자 받기

    if (num == 0) // num이 0이면
    {
        printf("num(%d)은 zero입니다.", num); // num은 zero라 출력
    }
    else if (num == 1) // num이 1이면
    {
        printf("num(%d)은 one입니다.", num); // num은 one이라 출력
    }
    else if (num == 2) // num이 2이면
    {
        printf("num(%d)는 two입니다.", num); // num은 two라 출력
    }
    else // 0, 1, 2 셋 다 아니면
    {
        printf("not 0~2"); // 범위에 없다고 출력
    }
}