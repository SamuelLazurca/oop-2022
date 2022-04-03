#pragma once

class Car {
protected:
	unsigned fuel_capacity = 0;
	unsigned fuel_consumption = 0;
	unsigned average_speed_rain = 0;
	unsigned average_speed_sunny = 0;
	unsigned average_speed_snow = 0;
	float time = 0;
public:
	char name[10] = "Car";
	virtual void SetTime(float time) = 0;
	virtual unsigned Get_Rain_Speed() = 0;
	virtual unsigned Get_Sunny_Speed() = 0;
	virtual unsigned Get_Snow_Speed() = 0;
	virtual unsigned Get_Fuel_Capacity() = 0;
	virtual unsigned Get_Fuel_Consumption() = 0;
	virtual float Get_Time() = 0;
	virtual char* Get_Name() = 0;
};
