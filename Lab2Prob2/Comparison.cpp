#include "Comparison.h"
#include <cstring>

int compare_maths(Student S1, Student S2)
{
	float grade1 = S1.get_maths_grade(), grade2 = S2.get_maths_grade();

	if (grade1 == grade2) return 0;
	else if (grade1 > grade2) return 1;
	else return -1;
}

int compare_history(Student S1, Student S2)
{
	float grade1 = S1.get_history_grade(), grade2 = S2.get_history_grade();

	if (grade1 == grade2) return 0;
	else if (grade1 > grade2) return 1;
	else return -1;
}

int compare_english(Student S1, Student S2)
{
	float grade1 = S1.get_english_grade(), grade2 = S2.get_english_grade();

	if (grade1 == grade2) return 0;
	else if (grade1 > grade2) return 1;
	else return -1;
}

int compare_name(Student S1, Student S2)
{
	if (strcmp(S1.get_name(), S2.get_name()) == 0) return 0;
	else if (strcmp(S1.get_name(), S2.get_name()) > 0) return 1;
	else return -1;
}

int compare_average(Student S1, Student S2)
{
	float grade1 = S1.get_average_grade(), grade2 = S2.get_average_grade();

	if (grade1 == grade2) return 0;
	else if (grade1 > grade2) return 1;
	else return -1;
}
