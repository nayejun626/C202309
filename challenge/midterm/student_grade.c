#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

char subjectNames[SUBJECTS][CHARNUM] = {"퀴즈", "중간고사", "기말고사"};
char studentNames[STUDENTS][CHARNUM] = {""};      // 학생 이름이 저장될 배열
double studentScores[STUDENTS][SUBJECTS] = {0.0}; // 학생의 시험 별 성적이 점수가 저장될 배열
// 학생별 평균 및 과목별 평균 함수화
void printaverageStudents();
void printaverageSubject();

int main()
{
    /* char subjectNames[SUBJECTS][CHARNUM] = {"퀴즈", "중간고사", "기말고사"};
    char studentNames[STUDENTS][CHARNUM] = {""};      // 학생 이름이 저장될 배열
    double studentScores[STUDENTS][SUBJECTS] = {0.0}; // 학생의 시험 별 성적이 점수가 저장될 배열 */
    printf("학생 %d명의 이름의 입력을 시작합니다: \n", STUDENTS);
    // TODO 1.1: 학생 이름을 입력받는 코드 블록 작성
    for (int i = 0; i < STUDENTS; i++)
    {
        scanf("%s", studentNames[i]);
    }

    // 입력된 학생 이름이 잘 저장되었는지 확인하는 코드 블록
    printf("학생 이름이 모두 입력되었습니다. \n");
    printf("입력된 학생 이름은 다음과 같습니다. \n");
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("%s", studentNames[i]);
        if (i != STUDENTS - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
    printf("--------------------\n");
    printf("각 학생의 %s, %s, %s 점수를 차례대로 입력해주세요. (띄어쓰기 구분)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);

    // TODO 1.2: 학생들의 시험 별 점수를 입력받는 코드 블록 작성
    for (int i = 0; i < STUDENTS; i++)
    {
        for (int j = 0; j < SUBJECTS; j++)
        {
            printf("시험 %s에서 학생 %s가 받은 점수를 입력하세요: \n", subjectNames[j], studentNames[i]);
            scanf("%lf", &studentScores[i][j]);
        }
    }

    printf("학생들의 시험 점수가 모두 입력 되었습니다.\n");

    printf("--------------------\n");
    printf("학생 별 성적은 다음과 같습니다 \n");
    printaverageStudents();

    // TODO 1.3: 학생 별 평균 점수를 출력하는 코드 블록 작성 >> 이후 함수화
    // HINT1: 2중 for문: (1) 학생별 (2) 과목들의 점수 합과 평균을 구하고 출력
    // HINT2: 출력문 코드 = printf("\t%s의 평균 점수: %.2lf\n", studentNames[i], finalScore);
    /* for (int i = 0; i < STUDENTS; i++)
    {
        double studentsTotal = 0;
        for (int j = 0; j < SUBJECTS; j++)
        {
            studentsTotal += studentScores[i][j];
        }
        double averageStudents = (double)studentsTotal / SUBJECTS;
        printf("학생 %s이 받은 점수의 평균: %lf\n", studentNames[i], averageStudents);
    } */

    printf("--------------------\n");
    printf("과목 별 평균 점수는 아래와 같습니다. \n");
    printaverageSubject();

    // TODO 1.4: 과목 별 평균 점수를 출력하는 코드 블록 작성 >> 이후 함수화
    // HINT1: 2중 for문으로 (1) 과목별 (2) 학생들의 점수 합과 평균을 구하고 출력
    // HINT2: 출력문 코드 = printf("\t%s의 평균 점수는 %.2lf 입니다.\n", subjectNames[i], subjectScore);
    // 과목 별 평균 점수를 출력하는 코드
    /* for (int i = 0; i < SUBJECTS; i++)
    {
        double subjectTotal = 0;
        for (int j = 0; j < STUDENTS; j++)
        {
            subjectTotal += studentScores[i][j];
        }
        double averageSubject = (double)subjectTotal / STUDENTS;
        printf("과목 %s의 평균: %lf\n", subjectNames[i], averageSubject);
    } */
    printf("프로그램을 종료합니다. \n");
    return 0;
}

void printaverageStudents()
{
    for (int i = 0; i < STUDENTS; i++)
    {
        double studentsTotal = 0;
        for (int j = 0; j < SUBJECTS; j++)
        {
            studentsTotal += studentScores[i][j];
        }
        double averageStudents = (double)studentsTotal / SUBJECTS;
        printf("학생 %s이 받은 점수의 평균: %lf\n", studentNames[i], averageStudents);
    }
}

void printaverageSubject()
{
    for (int i = 0; i < SUBJECTS; i++)
    {
        double subjectTotal = 0;
        for (int j = 0; j < STUDENTS; j++)
        {
            subjectTotal += studentScores[i][j];
        }
        double averageSubject = (double)subjectTotal / STUDENTS;
        printf("과목 %s의 평균: %lf\n", subjectNames[i], averageSubject);
    }
}
