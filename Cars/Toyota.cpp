#include "Toyota.h"

Toyota::Toyota()
{
	this->fuel_capacity = 300;
	this->fuel_consumption = 5;
	this->average_speed_rain = 75;
	this->average_speed_snow = 50;
	this->average_speed_sunny = 120;
}

void Toyota::SetTime(float time)
{
	this->time = time;
}

unsigned Toyota::Get_Rain_Speed()
{
	return this->average_speed_rain;
}

unsigned Toyota::Get_Sunny_Speed()
{
	return this->average_speed_sunny;
}

unsigned Toyota::Get_Snow_Speed()
{
	return this->average_speed_snow;
}

float Toyota::Get_Time()
{
	return time;
}

unsigned Toyota::Get_Fuel_Consumption()
{
	return fuel_consumption;
}

unsigned Toyota::Get_Fuel_Capacity()
{
	return fuel_capacity;
}

char* Toyota::Get_Name()
{
	return name;
}