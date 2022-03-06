#pragma once

class Student {
	char name[50];
	unsigned maths_grade, english_grade, history_grade;
public:
	void Init();
	void set_name(char* name);
	bool set_maths_grade(float grade);
	bool set_history_grade(float grade);
	bool set_english_grade(float grade);

	char* get_name();
	float get_maths_grade();
	float get_history_grade();
	float get_english_grade();

	float get_average_grade();
};