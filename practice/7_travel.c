#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10]; // 여행자 이름을 저장하는 배열
char cities[NUMCITY][10];  // 도시 이름을 저장하는 배열

void calculateTravelDays(); // 여행 일수를 계산하는 함수 선언

int main()
{
    // 사용자로부터 도시 이름 입력받기
    printf("%d개의 도시명을 차례대로 입력해주세요.\n", NUMCITY);
    for (int i = 0; i < NUMCITY; i++)
    {
        scanf("%s", cities[i]); // 각 도시 이름을 입력받음
    }

    // 사용자로부터 사람 이름 받기
    printf("%d개의 여행자 이름을 차례대로 입력해주세요.\n", NUMPEOPLE);
    for (int i = 0; i < NUMPEOPLE; i++)
    {
        scanf("%s", names[i]); // 각 여행자 이름을 입력받음
    }

    // 함수호출: 여행 일수 계산 함수 호출
    calculateTravelDays();

    return 0;
}

void calculateTravelDays()
{
    int travelDays[NUMCITY][NUMPEOPLE]; // 각 도시에서 각 사람이 보낸 여행 일수를 저장하는 배열

    // 각 도시에서 각 사람이 보낸 일 수 입력받기
    for (int i = 0; i < NUMCITY; i++)
    {
        for (int j = 0; j < NUMPEOPLE; j++)
        {
            printf("도시 %s에서 사람 %s가 보낸 일 수를 입력하세요: ", cities[i], names[j]);
            scanf("%d", &travelDays[i][j]); // 각 도시 및 여행자의 여행 일수를 입력받기
        }
    }

    // 각 도시별 총 일 수 및 평균 일 수 계산 후 출력
    for (int i = 0; i < NUMCITY; i++)
    {
        int totalDays = 0; // 각 도시별 총 여행 일수 초기화
        for (int j = 0; j < NUMPEOPLE; j++)
        {
            totalDays += travelDays[i][j]; // 각 도시에서 각 여행자의 여행 일수를 누적
        }
        float averageDays = (float)totalDays / NUMPEOPLE; // 평균 여행 일수 계산
        printf("도시 %s에서 보낸 총 일수: %d, 평균 일 수: %f\n", cities[i], totalDays, averageDays);
    }
}
