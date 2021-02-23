#include <stdio.h>

extern const char* MajorColorNames[];
extern int numberOfMajorColors;
extern const char* MinorColorNames[];
extern int numberOfMinorColors;

void PrintColorCodingManual()
{
int PairNumber=0;
printf("PairNumber\tMajorColor\tMinorColor\n\n");
	for (int i=0; numberOfMajorColors>i;i++)
	{
		for (int j=0; numberOfMinorColors>j;j++)
		{
		     PairNumber++;
			printf("%d\t\t%s\t\t%s\n",PairNumber,MajorColorNames[i],MinorColorNames[j]);
		}
	}

}