#include <stdio.h>
int hapf(int value); // 합함수 선언

void main() // 메인 함수
{
    printf("1부터 10까지의 합은 %d\n", hapf(10));     // 1~10까지 더하고 출력
    printf("1부터 100까지의 합은 %d\n", hapf(100));   // 1~100까지 더하고 출력
    printf("1부터 1000까지의 합은 %d\n", hapf(1000)); // 1~1000까지 더하고 출력
}

int hapf(int value) // 합함수
{
    int i = 1; // 변수 i 초기화
    int hap = 0;

    while (i <= value) // i가 valie보다 작거나 같을때 까지
    {
        hap = hap + i; // 합에 i 더하기
        i = i + 1;
    }
    return hap;
}
