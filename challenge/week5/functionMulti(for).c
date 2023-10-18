#include <stdio.h>
int multi(int value); // 곱함수 선언

void main() // 메인 함수
{
    printf("1부터 2까지의 곱은 %d\n", multi(2)); // 1~2까지 곱하고 출력
    printf("1부터 3까지의 곱은 %d\n", multi(3)); // 1~3까지 곱하고 출력
    printf("1부터 5까지의 곱은 %d\n", multi(5)); // 1~5까지 곱하고 출력
}

int multi(int value) // 곱함수정의
{
    int multi = 1;

    for (int i = 1; i <= value; i++) // i가 valie보다 작거나 같을때 까지
    {
        multi = multi * i; // 지금까지의 멀티에 i곱하기
    }
    return multi;
}