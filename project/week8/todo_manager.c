#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10 // 최대 할 일 개수 = 10개
#define CHAR_NUM 100 // 문자열의 최대 길이

int main()
{
    char tasks[MAX_TASKS][CHAR_NUM] = {""}; // 할 일 목록을 저장하는 2차원 배열
    int taskCount = 0;                      // 할 일의 수를 저장하는 변수

    printf("TODO 리스트 시작!\n");

    while (1)
    {
        int choice = -1;   // 사용자 입력 메뉴를 저장하는 변수
        int terminate = 0; // 종료를 위한 플래그
        int delIndex = -1; // 할 일 삭제를 위한 인덱스 저장 변수

        // 메뉴 출력
        printf("------------------\n");
        printf("메뉴를 입력해주세요.\n");
        printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5. 할 일 수정\n");
        printf("현재 할 일 수 = %d\n", taskCount);
        printf("------------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // 할 일 추가
            if (taskCount < MAX_TASKS)
            { // 할 일 목록이 일의 최대 개수 미만인 경우
                printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
                scanf(" %99s", tasks[taskCount]); // 사용자로부터 99자 이내의 문자열을 입력받기
                printf("할 일 %s 가 저장되었습니다\n\n", tasks[taskCount]);
                taskCount++; // 할 일이 추가되면 할 일 수 증가시키기
            }
            else
            {
                printf("할 일 목록이 꽉 찼습니다.\n");
            }
            break;
        case 2: // 할 일 삭제
            printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작): ");
            scanf("%d", &delIndex);
            if (delIndex > taskCount || delIndex <= 0)
            {                                          // 삭제 범위에 이상이 있을 시
                printf("삭제 범위가 벗어났습니다.\n"); // 벗어났음을 출력
            }
            else
            {
                printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);

                // 선택한 할 일을 삭제하고 뒤에 있는 할 일을 앞으로 끌어오기
                for (int i = delIndex - 1; i < taskCount - 1; i++)
                {
                    strcpy(tasks[i], tasks[i + 1]);
                }

                strcpy(tasks[taskCount - 1], ""); // 마지막 할 일 항목을 비움
                taskCount--;                      // 할 일이 삭제되면 할일 수 감소시키기
            }
            break;
        case 3: // 목록 보기
            printf("할 일 목록\n");
            for (int i = 0; i < taskCount; i++)
            {
                printf("%d. %s\n", i + 1, tasks[i]);
            }
            printf("\n");
            break;
        case 4: // 종료
            terminate = 1;
            break;
        case 5: // 할 일 수정
            printf("수정할 할 일의 번호를 입력해주세요. (1부터 시작): ");
            int modifyIndex;
            scanf("%d", &modifyIndex);
            if (modifyIndex > taskCount || modifyIndex <= 0) // modifyIndex가 카운트보다 크거나 0이하면
            {
                printf("수정 범위가 벗어났습니다.\n");
            }
            else
            {
                printf("%d. 현재 할 일: %s\n", modifyIndex, tasks[modifyIndex - 1]);
                printf("새로운 할 일을 입력하세요: ");
                scanf(" %99s", tasks[modifyIndex - 1]); // 사용자로부터 문자열 입력받기
                printf("%d. 할 일이 수정되었습니다.\n", modifyIndex);
            }
            break;
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }

        if (terminate == 1) // terminate 가 1이면 즉 case4일 때
        {
            printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n"); // 프로그램 종료
            break;
        }
    }

    return 0;
}
