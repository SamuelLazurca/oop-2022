#pragma once

#include "Car.h"

class Dacia : public Car {
public:
	char name[10] = "Dacia";
	Dacia();
	void SetTime (float time);
	unsigned Get_Rain_Speed();
	unsigned Get_Sunny_Speed();
	unsigned Get_Snow_Speed();
	unsigned Get_Fuel_Capacity();
	unsigned Get_Fuel_Consumption();
	float Get_Time();
	char* Get_Name();
};