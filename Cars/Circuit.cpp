#include "Circuit.h"
#include "Weather.h"
#include <cstdio>
#include <cstdlib>

void Circuit::SetLength(unsigned l)
{
	this->lenght = l;
}

void Circuit::SetWeather(Weather W)
{
	this->W = W;
}

void Circuit::AddCar(Car* new_car)
{
	if (nr_of_cars < 7)
	{
		car[nr_of_cars] = new_car;
		new_car = nullptr;
		nr_of_cars++;
	}
}

void Circuit::Race()
{
	if (nr_of_cars > 0) {
		if (lenght != 0)
		{
			this->ComputeTime();
			this->SortByTime();
		}
	}
}

void Circuit::ShowFinalRanks()
{
	printf("Final Ranks:\n");
	if (this->nr_of_cars > 0)
	{
		for (unsigned i = 0; i < nr_of_cars; i++)
		{
			if (car[i]->Get_Time() > 0) printf("%s   Time: %f\n", car[i]->Get_Name(), car[i]->Get_Time());
		}
	}
	else {
		printf("No car took part in the race!\n");
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("Who did not finish:\n");
	for (unsigned i = 0; i < nr_of_cars; i++)
	{
		if (car[i]->Get_Time() == 0)printf("%s\n", car[i]->Get_Name());
	}
}

void Circuit::ComputeTime()
{
	for (unsigned index = 0; index < nr_of_cars; index++)
	{
		unsigned speed;
		if (this->W == Weather::Rain) speed = car[index]->Get_Rain_Speed();
		else if(this->W == Weather::Sunny) speed = car[index]->Get_Sunny_Speed();
		else speed = car[index]->Get_Snow_Speed();
		
		if(car[index]->Get_Fuel_Capacity() < car[index]->Get_Fuel_Consumption()*lenght) car[index]->SetTime(0);
		else car[index]->SetTime((float)lenght / (float)speed);
	}
}

void Circuit::SortByTime()
{
	unsigned ultim, n1, i;
	ultim = nr_of_cars - 1;
	while (ultim > 0)
	{
		n1 = ultim - 1;
		ultim = 0;
		for (i = 0; i <= n1; i++)
			if (car[i]->Get_Time() > car[i + 1]->Get_Time())
			{
				Car* Aux;
				Aux=car[i];
				car[i]=car[i+1];
				car[i+1]=Aux;
				ultim = i;
			}
	}
}
