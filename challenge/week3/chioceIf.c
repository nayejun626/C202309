#include <stdio.h>

int main()
{
    int choice;
    printf("1. 파일저장\n");       // 사용자에게 보일 문장 1 입력
    printf("2. 저장 없이 닫기\n"); // 사용자에게 보일 문장 2 입력
    printf("3. 종료\n");           // 사용자에게 보일 문장 3 입력
    scanf("%d", &choice);          // choice라는 변수에 정수d 줌

    if (choice == 1) // 문장 1이라면
    {
        printf("파일을 저장합니다.\n"); // 파일을 저장한다고 출력
    }
    else if (choice == 2) // 문장2이면
    {
        printf("저장 없이 닫습니다.\n"); // 저장없이 닫는 다고 출력
    }
    else if (choice == 3) // 문장 3 이면
    {
        printf("종료합니다.\n"); // 종료한다고 출력
    }
    else // 셋 다 아니면
    {
        printf("잘못 입력하셨습니다."); // 잘못 입력 했다고 출력
    }
}