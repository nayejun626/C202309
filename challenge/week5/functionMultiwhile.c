#include <stdio.h>

int multi(int value); // 곱함수 선언

int main() // 메인 함수
{
    printf("1부터 4까지의 곱은 %d\n", multi(4)); // 1~4까지 곱하고 출력, 멀티 함수 호출을 포함한다.
    printf("1부터 5까지의 곱은 %d\n", multi(5)); // 1~5까지 곱하고 출력
    printf("1부터 6까지의 곱은 %d\n", multi(6)); // 1~6까지 곱하고 출력
}

int multi(int value) // 곱함수정의
{
    int i = 1; // 변수 i 초기화
    int multi = 1;

    while (i <= value) // i가 valie보다 작거나 같을때 까지
    {
        multi = multi * i; // 지금까지의 멀티에 i곱하기
        i = i + 1;         // i에 1더하기
    }
    return multi;
}