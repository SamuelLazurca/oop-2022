#include "Ford.h"

Ford::Ford()
{
	this->fuel_capacity = 250;
	this->fuel_consumption = 5;
	this->average_speed_rain = 55;
	this->average_speed_snow = 45;
	this->average_speed_sunny = 105;
}

void Ford::SetTime(float time)
{
	this->time = time;
}

unsigned Ford::Get_Rain_Speed()
{
	return this->average_speed_rain;
}

unsigned Ford::Get_Sunny_Speed()
{
	return this->average_speed_sunny;
}

unsigned Ford::Get_Snow_Speed()
{
	return this->average_speed_snow;
}

float Ford::Get_Time()
{
	return time;
}

unsigned Ford::Get_Fuel_Consumption()
{
	return fuel_consumption;
}

unsigned Ford::Get_Fuel_Capacity()
{
	return fuel_capacity;
}

char* Ford::Get_Name()
{
	return name;
}