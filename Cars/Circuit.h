#pragma once

#include "Car.h"
#include "Dacia.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Toyota.h"
#include "Mazda.h"
#include "Weather.h"

class Circuit {
	unsigned lenght;
	unsigned nr_of_cars = 0;
	Weather W;
	Car* car[7];
	float final_time[7];
public:
	void SetLength(unsigned l);
	void SetWeather(Weather W);
	void AddCar(Car* new_car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void ComputeTime();
	void SortByTime();
};
