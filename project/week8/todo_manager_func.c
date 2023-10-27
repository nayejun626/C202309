#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define CHAR_NUM 100

char tasks[MAX_TASKS][CHAR_NUM] = {""}; // 할 일 목록을 저장하기 위한 2차원 배열
int taskCount = 0;                      // 할 일의 수를 저장하기 위한 변수

void addTask()
{
    if (taskCount < MAX_TASKS) // 최대 허용 개수 보다 작을 경우만큼만 입력받기 위한 조건
    {
        printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
        char task[CHAR_NUM];                                        // 새로운 문자열을 저장하기 위한 임시 배열
        scanf(" %99s", task);                                       // 사용자로부터 99자 이하의 문자열 입력받기
        strncpy(tasks[taskCount], task, CHAR_NUM - 1);              // 문자열을 할 일 목록에 복사하기(널 종료 문자 고려)
        tasks[taskCount][CHAR_NUM - 1] = '\0';                      // 널 종료 문자 추가
        printf("할 일 %s 가 저장되었습니다\n\n", tasks[taskCount]); // 할 일이 추가되면 카운트 증가
        taskCount++;
    }
    else
    {
        printf("할 일 목록이 꽉 찼습니다.\n");
    }
}

void delTask()
{
    int delIndex;
    printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작): ");
    scanf("%d", &delIndex);
    if (delIndex > taskCount || delIndex <= 0) // 삭제할 일범위가 카운트보다 크거나 0이하이면
    {
        printf("삭제 범위가 벗어났습니다.\n");
    }
    else
    {
        printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);

        // 할 일 삭제 후 뒤에 있는 할 일을 땡김
        for (int i = delIndex - 1; i < taskCount - 1; i++)
        {
            strncpy(tasks[i], tasks[i + 1], CHAR_NUM);
        }

        tasks[taskCount - 1][0] = '\0'; // 마지막 할일 항목은 비움
        taskCount--;                    // 할 일이 삭제되면 카운트 감소
    }
}

void printTask() // 사용자가 3번을 선택 시 printTask함수가 호출된다.
{
    printf("할 일 목록\n");
    for (int i = 0; i < taskCount; i++)
    {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
    printf("\n");
}

int main() // 메인함수, 사용자에게 메뉴를 출력하고 선택(1번~5번)에 따른 호출
{
    printf("TODO 리스트 시작!\n");

    while (1)
    {
        int choice = -1; // 사용자 입력 메뉴를 저장하기 위한 변수
        int terminate = 0;

        // 사용자에게 메뉴를 출력하고, 메뉴를 입력받기
        printf("------------------\n");
        printf("메뉴를 입력해주세요.\n");
        printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5. 할 일 수정\n");
        printf("현재 할 일 수 = %d\n", taskCount);
        printf("------------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            delTask();
            break;
        case 3:
            printTask();
            break;
        case 4:
            terminate = 1; // 4를 선택하면 프로그램이 종료돼야함
            break;
        case 5:
            printf("수정할 할 일의 번호를 입력해주세요. (1부터 시작): ");
            int modifyIndex;
            scanf("%d", &modifyIndex);
            if (modifyIndex > taskCount || modifyIndex <= 0)
            {
                printf("수정 범위가 벗어났습니다.\n");
            }
            else
            {
                printf("%d. 현재 할 일: %s\n", modifyIndex, tasks[modifyIndex - 1]);
                printf("새로운 할 일을 입력하세요: ");
                char task[CHAR_NUM];
                scanf(" %99s", task); // 사용자로부터 안전하게 문자열 입력받기
                strncpy(tasks[modifyIndex - 1], task, CHAR_NUM - 1);
                tasks[modifyIndex - 1][CHAR_NUM - 1] = '\0'; // 널 종료 문자 추가
                printf("%d. 할 일이 수정되었습니다.\n", modifyIndex);
            }
            break;
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }

        if (terminate == 1)
        {
            printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n");
            break;
        }
    }

    return 0;
}
