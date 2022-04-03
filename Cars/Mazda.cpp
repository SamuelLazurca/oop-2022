#include "Mazda.h"

Mazda::Mazda()
{
	this->fuel_capacity = 280;
	this->fuel_consumption = 7;
	this->average_speed_rain = 65;
	this->average_speed_snow = 50;
	this->average_speed_sunny = 130;
}

void Mazda::SetTime(float time)
{
	this->time = time;
}

unsigned Mazda::Get_Rain_Speed()
{
	return this->average_speed_rain;
}

unsigned Mazda::Get_Sunny_Speed()
{
	return this->average_speed_sunny;
}

unsigned Mazda::Get_Snow_Speed()
{
	return this->average_speed_snow;
}

float Mazda::Get_Time()
{
	return time;
}

unsigned Mazda::Get_Fuel_Consumption()
{
	return fuel_consumption;
}

unsigned Mazda::Get_Fuel_Capacity()
{
	return fuel_capacity;
}

char* Mazda::Get_Name()
{
	return name;
}