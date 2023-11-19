#include <stdio.h>
#define STUDENT 5 // 학생 수를 상수로 정의

// 학생 성적을 분류하여 출력하는 함수 정의
void classifyStudent(int *scores, char targetGrade)
{
    printf("학생 성적 분류: \n");

    char grade = ' '; // 변수를 선언하고 초기값을 공백문자로 설정

    for (int i = 0; i < STUDENT; i++) // 학생의 성적을 학점으로 변환
    {
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
        // 입력된 학점과 목표 학점을 비교하여 동일한 경우 출력
        if (targetGrade == grade)
        {
            printf("%d 학생은 %c 학점을 받았습니다.\n", i + 1, targetGrade);
        }
    }
}

// 학생 성적의 총합을 계산하는 함수
int sumScores(int *scores)
{
    int total = 0;
    for (int i = 0; i < STUDENT; i++)
    {
        total += scores[i];
    }
    return total;
}

// 학생 성적의 평균을 계산하는 함수
double averageScore(int *scores)
{
    int total = sumScores(scores);
    return (double)total / STUDENT;
}

// 학생 성적 순위를 계산하고 출력하는 함수
void printfRanks(int *scores)
{
    int ranks[STUDENT];
    for (int i = 0; i < STUDENT; i++)
    {
        ranks[i] = 1;
        for (int j = 0; j < STUDENT; j++)
        {
            if (scores[i] < scores[j])
            {
                ranks[i]++;
            }
        }
        printf("학생 %d의 성적 순위는 %d입니다.\n", i + 1, ranks[i]);
    }
}

int main() // 메인 함수 (함수 정의가 위에 있기 때문에 선언이 필요없는 프로그램)
{
    int scores[STUDENT]; // 학생들의 성적을 저장할 배열 선언

    for (int i = 0; i < STUDENT; i++) // 학생들의 성적 입력 받기
    {
        printf("학생 %d의 성적을 입력하세요: ", i + 1);
        scanf("%d", &scores[i]);
    }

    getchar(); // 버퍼 임시 저장 변수

    char target;
    printf("특정 학점 (A, B, C, D, F)을 입력하세요: ");
    scanf(" %c", &target); // 입력값 앞의 공백 문자 처리

    // 학생들의 성적 분류 및 출력
    classifyStudent(scores, target);

    // 학생들의 성적 총합과 평균값을 계산하고 출력
    int sum = sumScores(scores);
    double average = averageScore(scores);
    printf("학생들 점수의 총 합은 %d이고, 평균값은 %.2lf입니다.\n", sum, average);

    // 학생 성적 순위를 계산하고 출력
    printfRanks(scores);

    return 0;
}
