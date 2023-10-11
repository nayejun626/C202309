#include <stdio.h>
#define STUDENT 5

// 학생을 입력받아 특정학점과 비교하고 출력하는 함수
void classifyStudent(int scores[], char targetGrade)
{
    printf("학생 성적 분류: \n");
    char grade = ' ';
    for (int i = 0; i < STUDENT; i++)
    {
        // 학점 계산하기
        if (scores[i] >= 90)
        {
            grade = 'A';
        }
        else if (scores[i] >= 80)
        {
            grade = 'B';
        }
        else if (scores[i] >= 70)
        {
            grade = 'C';
        }
        else if (scores[i] >= 60)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
        // 입력된 학점과 타겟학점 비교 후 출력
        if (targetGrade == grade)
        {
            printf("%d 학생은 %c 학점을 받았습니다.\n", i + 1, targetGrade);
        }
    }
}

int main()
{
    // 학생들의 성적을 저장할 배열 선언
    int scores[STUDENT];

    // 학생들의 성적 입력 받기
    for (int i = 0; i < STUDENT; i++)
    {
        printf("학생 %d의 성적을 입력하세요: ", i + 1);
        scanf("%d", &scores[i]);
    }

    char ch = getchar(); // 버퍼 임시 저장 변수

    char target;
    printf("특정 학점 (A, B, C, D, F)을 입력하세요: ");
    scanf(" %c", &target);

    // 학생들의 성적 분류 및 출력
    classifyStudent(scores, target);

    return 0;
}
