#include <stdio.h>

#define NUMCITY 3	// 도시 수를 상수로 정의
#define NUMPEOPLE 2 // 사람 수를 상수로 정의

// 사람명과 도시명을 저장하는 배열 선언
char name[NUMPEOPLE][10];
char cities[NUMCITY][10];

// 함수 프로토타입 선언
void calculateTravelDays();
int getSum(int numArray[], int length);
double getAverage(int numArray[], int length);
void getFamousCity(double dayArray[], int length);

int main() // 메인 함수
{
	printf("%d개의 도시명을 차례대로 입력해주세요.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++)
	{
		scanf("%s", cities[i]); // 도시명 입력
	}

	printf("%d명의 사람명을 차례대로 입력해주세요.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++)
	{
		scanf("%s", name[i]); // 사람명 입력
	}

	calculateTravelDays(); // 여행 일수 계산 함수 호출

	return 0;
}

void calculateTravelDays() // 여행일자 계산 함수 정의
{
	int travelDays[NUMCITY][NUMPEOPLE];

	for (int i = 0; i < NUMCITY; i++)
	{
		for (int j = 0; j < NUMPEOPLE; j++)
		{
			printf("도시 %s에서 %s가 보낸 일 수를 입력하세요.:\n", cities[i], name[j]);
			scanf("%d", &travelDays[i][j]); // 도시별로 사람들의 여행 일수 입력
		}
	}

	double averageDays[NUMCITY];

	for (int i = 0; i < NUMCITY; i++)
	{
		int totalDay = getSum(travelDays[i], NUMPEOPLE);		  // 각 도시의 여행 일수 총합 계산
		double averageDay = getAverage(travelDays[i], NUMPEOPLE); // 각 도시의 평균 여행 일수 계산
		printf("도시 %s에서 보낸 총 일수: %d, 평균 일 수: %.2f\n", cities[i], totalDay, averageDay);
		averageDays[i] = averageDay;
	}

	getFamousCity(averageDays, NUMCITY); // 인기 있는 도시 찾는 함수 호출
}

int getSum(int numArray[], int length)
{
	int totalDays = 0;
	for (int i = 0; i < length; i++)
	{
		totalDays += numArray[i]; // 배열 요소의 합을 계산
	}
	return totalDays;
}

double getAverage(int numArray[], int length) // 평균 계산 함수 정의
{
	int totalDays = getSum(numArray, length);		 // 배열 요소의 합 계산
	double averageDays = (double)totalDays / length; // 평균 계산
	return averageDays;
}

void getFamousCity(double dayArray[], int length) // 가장 인기 있던 도시함수 정의
{
	double maxDay = 0;
	int maxDayIndex = 0;
	for (int i = 0; i < length; i++)
	{
		if (dayArray[i] > maxDay)
		{
			maxDay = dayArray[i]; // 최대값 갱신
			maxDayIndex = i;	  // 최대값의 인덱스 저장
		}
	}
	printf("평균일 기준으로 가장 인기 있었던 도시는 %s입니다. (평균머문일: %.2f)\n", cities[maxDayIndex], maxDay);
}
