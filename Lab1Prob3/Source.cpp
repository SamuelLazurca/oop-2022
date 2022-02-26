#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int create_vector_cuv(char cuvinte[50][50], char sir[])
{
	int index = 0, i = 0, j = 0;

	while (sir[index] != '\0')
	{
		if (sir[index] != ' ')
		{
			cuvinte[i][j] = sir[index];
			j++;
		}
		else if (sir[index - 1] != ' ')
			{
			cuvinte[i][j] = '\0';
			i++;
			j = 0;
			}
		index++;
	}
	cuvinte[i][j] = '\0';
	
	return i + 1;
}
int mystrlen(char cuvant[])
{
	int index = 0;

	while (cuvant[index] != '\0')
	{
		index++;
	}
	return index;
}
char myupper(char c)
{
	if (c >= 'a' && c <= 'z')  return c - 'a' + 'A';
	
	return c; 
}
int mystrcmp(char cuvant1[], char cuvant2[])
{
	int lungime = mystrlen(cuvant1), i = 0;

	while (i < lungime)
	{
		if(myupper(cuvant1[i]) < myupper(cuvant2[i])) return 1;
		if (myupper(cuvant1[i]) > myupper(cuvant2[i])) return -1;
		i++;
	}

	return 0;
}
void myswap(char cuvant1[], char cuvant2[])
{
	int lungime1 = mystrlen(cuvant1), lungime2 = mystrlen(cuvant2), i = 0 ,j = 0;
	char aux;

	while (i <= lungime1 && j <= lungime2)
	{
		aux = cuvant1[i];
		cuvant1[i] = cuvant2[j];
		cuvant2[j] = aux;
		i++;
		j++;
	}
	while(i <= lungime1)
	{
		cuvant2[j] = cuvant1[i];
		j++;
		i++;
	}
	while (j <= lungime2)
	{
		cuvant1[j] = cuvant2[i];
		j++;
		i++;
	}
}
void sortare(char cuvinte[50][50], int nrCuv)
{
	int ultim, nr, i;

	ultim = nrCuv - 1;
	while (ultim > 0)
	{
		nr = ultim - 1;
		ultim = 0;
		for (i = 0; i <= nr; i++)
		{
			if (mystrlen(cuvinte[i]) < mystrlen(cuvinte[i + 1]))
			{
				myswap(cuvinte[i], cuvinte[i + 1]);
				ultim = i;
			}
			else if (mystrlen(cuvinte[i]) == mystrlen(cuvinte[i + 1]) && mystrcmp(cuvinte[i], cuvinte[i + 1]) == 1)
				{
				myswap(cuvinte[i], cuvinte[i + 1]);
				ultim = i;
				}
		}
	}
}
void afisare(char cuvinte[50][50], int nrCuv)
{
	for (int i = 0; i < nrCuv; i++)
	{
		printf("%s\n", cuvinte[i]);
	}
}
int main()
{
	char cuvinte[50][50], sir[250];
	int nrCuv;

	scanf("%[^\n]s", sir);

	nrCuv = create_vector_cuv(cuvinte, sir);
	
	sortare(cuvinte, nrCuv);
	afisare(cuvinte, nrCuv);

	return 0;
}