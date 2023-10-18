#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10];
char cities[NUMCITY][10];

void calculateTravelDays();

int main()
{

	printf("%d. \n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++)
	{
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}

	printf("%d \n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++)
	{
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}

	calculateTravelDays(names);

	return 0;
}

void calculateTravelDays()
{
	int travelDays[NUMCITY][NUMPEOPLE];
}