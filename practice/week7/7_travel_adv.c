#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10];
char cities[NUMCITY][10];

// 함수선언
int getSum(int numArray[], int length);
double getAverage(int numArray[], int length);
void printFamousCity(double dayArray[], int length);

void calculateTravelDays();

int main() // 메인함수
{
    printf("%d개의 도시명을 차례로 입력해주세요. \n", NUMCITY);
    for (int i = 0; i < NUMCITY; i++)
    {
        scanf("%s", cities[i]); // 각 도시 이름을 입력받기
    }

    printf("%d명의 여행자 이름을 차례로 입력해주세요. \n", NUMPEOPLE);
    for (int i = 0; i < NUMPEOPLE; i++)
    {
        scanf("%s", names[i]); // 각 여행자 이름을 입력받기
    }

    calculateTravelDays();

    return 0;
}

void calculateTravelDays() // 함수 정의
{
    int travelDays[NUMCITY][NUMPEOPLE];

    // 각 도시에서 각 사람이 보낸 일 수 입력받기
    for (int i = 0; i < NUMCITY; i++)
    {
        for (int j = 0; j < NUMPEOPLE; j++)
        {
            printf("도시 %s에서 사람 %s가 보낸 일 수를 입력하세요: ", cities[i], names[j]);
            scanf("%d", &travelDays[i][j]); // 각 도시 및 여행자의 여행 일수를 입력받기
        }
    }

    double averageDays[NUMCITY];

    // 각 도시별 평균 일 수 계산
    for (int i = 0; i < NUMCITY; i++)
    {
        int totalDays = getSum(travelDays[i], NUMPEOPLE);      // 각 도시에서의 총 일 수 계산
        averageDays[i] = getAverage(travelDays[i], NUMPEOPLE); // 각 도시에서의 평균 일 수 계산

        printf("도시 %s에서 보낸 총 일수: %d, 평균 일 수: %.2f\n", cities[i], totalDays, averageDays[i]); // 결과 출력
    }

    // 가장 평균 일수가 높은 도시 출력
    printFamousCity(averageDays, NUMCITY);
}

// 배열의 합을 계산하는 함수 정의
int getSum(int numArray[], int length)
{
    int totalDays = 0;
    for (int i = 0; i < length; i++)
    {
        totalDays += numArray[i];
    }
    return totalDays;
}

// 배열의 평균을 계산하는 함수
double getAverage(int numArray[], int length)
{
    int totalDays = getSum(numArray, length);
    double averageDays = (double)totalDays / length;
    return averageDays;
}

// 평균 여행 일수가 가장 많은 도시 계산하는 함수
void printFamousCity(double dayArray[], int length)
{
    double maxDay = 0;
    int maxDayIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if (dayArray[i] > maxDay)
        {
            maxDay = dayArray[i];
            maxDayIndex = i;
        }
    }
    printf("평균 일 기준으로 가장 인기 있었던 도시는 %s 입니다. (평균 머문 일: %.2f)\n", cities[maxDayIndex], maxDay);
}
