#include "Mercedes.h"

Mercedes::Mercedes()
{
	this->fuel_capacity = 400;
	this->fuel_consumption = 8;
	this->average_speed_rain = 75;
	this->average_speed_snow = 55;
	this->average_speed_sunny = 125;
}

void Mercedes::SetTime(float time)
{
	this->time = time;
}

unsigned Mercedes::Get_Rain_Speed()
{
	return this->average_speed_rain;
}

unsigned Mercedes::Get_Sunny_Speed()
{
	return this->average_speed_sunny;
}

unsigned Mercedes::Get_Snow_Speed()
{
	return this->average_speed_snow;
}

float Mercedes::Get_Time()
{
	return time;
}

unsigned Mercedes::Get_Fuel_Consumption()
{
	return fuel_consumption;
}

unsigned Mercedes::Get_Fuel_Capacity()
{
	return fuel_capacity;
}

char* Mercedes::Get_Name()
{
	return name;
}