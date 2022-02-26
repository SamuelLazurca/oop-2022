#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int myatoi(char numar[])
{
	int i = 0, numarf = 0;

	while (numar[i] != '\0')
	{
		numarf = numarf * 10 + (numar[i] - '0');
		i++;
	}

	return numarf;
}

void deleteEndl(char sir[])
{
	int i = 0;
	while (sir[i] != '\0' && sir[i] != '\n')
	{
		i++;
	}
	
	sir[i] = '\0';
}
int main()
{
	char numar[100];
	int nr, sum = 0;

	FILE* pFile = fopen("in.txt", "r");

	if (pFile == NULL) {
		printf("Nu s-a deschis fisierul");
		return 0;
	}
	
	while (fgets(numar, 100, pFile) != NULL)
	{
		deleteEndl(numar);
		nr = myatoi(numar); 
		sum += nr;
	}

	printf("%d", sum);

	fclose(pFile);
	return 0;
}