#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>

void Student::Init()
{
	this->name[0] = '\0';
	this->maths_grade = 1;
	this->english_grade = 1;
	this->history_grade = 1;
}

void Student::set_name(char* name)
{
	strcpy(this->name, name);
}

bool Student::set_maths_grade(float grade)
{
	if (grade >= 1 && grade <= 10) {
		this->maths_grade = grade;
		return true;
	}
	return false;
}

bool Student::set_history_grade(float grade)
{
	if (grade >= 1 && grade <= 10) {
		this->history_grade = grade;
		return true;
	}
	return false;
}

bool Student::set_english_grade(float grade)
{
	if (grade >= 1 && grade <= 10) {
		this->english_grade = grade;
		return true;
	}
	return false;
}

char* Student::get_name()
{
	return this->name;
}

float Student::get_maths_grade()
{
	return this->maths_grade;
}

float Student::get_history_grade()
{
	return this->history_grade;
}

float Student::get_english_grade()
{
	return this->english_grade;
}

float Student::get_average_grade()
{
	return (this->maths_grade + this->history_grade + this->english_grade) / 3.0;
}
