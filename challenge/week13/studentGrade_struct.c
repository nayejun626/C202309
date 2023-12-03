#include <stdio.h>
#include <stdlib.h>

// 학생들의 정보를 담는 구조체 정의하기
struct StudentGrade_struct
{
    char name[10]; // 이름 멤버
    int score;     // 점수 멤버
};

// 학생 성적을 분류하여 출력하는 함수 정의 (학생수를 입력 받기때문에 기존 매개변수에서 'int 학생수'를 추가해준다. 다른 함수도 마찬가지로 해주a)
void classifyStudent(struct StudentGrade_struct *students, char targetGrade, int 학생수)
{
    printf("학생 성적 분류: \n");

    char grade = ' ';

    for (int i = 0; i < 학생수; i++)
    {
        if (students[i].score >= 90) // 기존 함수의 score[i]를 students[i].score로 변경해줌으로써 멤버함수를 불러옴.
        {
            grade = 'A';
        }
        else if (students[i].score >= 80)
        {
            grade = 'B';
        }
        else if (students[i].score >= 70)
        {
            grade = 'C';
        }
        else if (students[i].score >= 60)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
        if (targetGrade == grade)
        {
            printf("%s 학생은 %c 학점을 받았습니다.\n", students[i].name, targetGrade);
        }
    }
}

// 학생 성적의 총합을 계산하는 함수
int sumScores(struct StudentGrade_struct *students, int 학생수)
{
    int total = 0;
    for (int i = 0; i < 학생수; i++)
    {
        total += students[i].score;
    }
    return total;
}

// 학생 성적의 평균을 계산하는 함수
double averageScore(struct StudentGrade_struct *students, int 학생수)
{
    int total = sumScores(students, 학생수);
    return (double)total / 학생수;
}

// 학생 성적 순위를 계산하고 출력하는 함수
void printfRanks(struct StudentGrade_struct *students, int 학생수)
{
    int ranks[학생수];
    for (int i = 0; i < 학생수; i++)
    {
        ranks[i] = 1;
        for (int j = 0; j < 학생수; j++)
        {
            if (students[i].score < students[j].score)
            {
                ranks[i]++;
            }
        }
        printf("%s 학생의 성적 순위는 %d입니다.\n", students[i].name, ranks[i]);
    }
}

int main()
{
    int 학생수;
    printf("학생 수를 입력하세요:\n");
    scanf("%d", &학생수);

    // 구조체 배열 동적 할당하기
    struct StudentGrade_struct *students = (struct StudentGrade_struct *)malloc(학생수 * sizeof(struct StudentGrade_struct));

    // 학생 정보 입력 받기
    for (int i = 0; i < 학생수; i++)
    {
        printf("학생 %d의 이름을 입력하세요: ", i + 1);
        scanf("%s", students[i].name); // 문자열을 입력받는 거라서 &를 붙이지 않아도된다.
        printf("학생 %d의 성적을 입력하세요: ", i + 1);
        scanf("%d", &students[i].score);
    }

    getchar();

    char target;
    printf("특정 학점 (A, B, C, D, F)을 입력하세요: ");
    scanf(" %c", &target);

    // 학생들의 성적 분류 및 출력
    classifyStudent(students, target, 학생수);

    // 학생들의 성적 총합과 평균값을 계산하고 출력
    int sum = sumScores(students, 학생수);
    double average = averageScore(students, 학생수);
    printf("학생들 점수의 총 합은 %d이고, 평균값은 %.2lf입니다.\n", sum, average);

    // 학생 성적 순위를 계산하고 출력
    printfRanks(students, 학생수);

    // 할당된 배열 메모리 해제하기
    free(students);

    return 0;
}
