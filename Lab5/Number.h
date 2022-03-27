#pragma once

class Number
{
	char* value;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& n);             // copy constructor
	Number(Number&& n);                  // move constructor
	Number(int value);
	~Number();
	
	// add operators and copy/move constructor
	
	bool operator>(Number& n2);
	bool operator<(Number& n2);
	bool operator>=(Number& n2);
	bool operator<=(Number& n2);
	bool operator==(Number& n2);
	bool operator!=(Number& n2);

	Number& operator=(Number n);
	Number& operator=(int value);
	Number& operator=(const char* value);

	friend Number operator+(Number n1, Number n2);
	friend Number operator-(Number n1, Number n2);

	Number& operator+=(Number n);
	Number& operator--();
	Number& operator--(int);
	char operator[](int index);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};