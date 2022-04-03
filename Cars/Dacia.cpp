#include "Dacia.h"
#include <cstdio>
Dacia::Dacia()
{
	this->fuel_capacity = 200;
	this->fuel_consumption = 6;
	this->average_speed_rain = 80;
	this->average_speed_snow = 35;
	this->average_speed_sunny = 100;
}

void Dacia::SetTime(float time)
{
	this->time = time;
}

unsigned Dacia::Get_Rain_Speed()
{
	return this->average_speed_rain;
}

unsigned Dacia::Get_Sunny_Speed()
{
	return this->average_speed_sunny;
}

unsigned Dacia::Get_Snow_Speed()
{
	return this->average_speed_snow;
}

unsigned Dacia::Get_Fuel_Capacity()
{
	return fuel_capacity;
}

unsigned Dacia::Get_Fuel_Consumption()
{
	return fuel_consumption;
}

float Dacia::Get_Time()
{
	return time;
}

char* Dacia::Get_Name()
{
	return name;
}
