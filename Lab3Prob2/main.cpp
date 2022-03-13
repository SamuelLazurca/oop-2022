#include <iostream>
#include "Canvas.h"

int main()
{
	Canvas Picture(20,30);
	Picture.DrawCircle(12, 8, 7, '*');
	Picture.FillCircle(12, 8, 7, '*');
	Picture.FillCircle(12, 8, 6, ' ');
	
	Picture.DrawRect(5, 17, 19, 19,'*');
	Picture.FillRect(5,17, 19, 19, '*');
	Picture.Print();
	Picture.Clear();

	Picture.SetPoint(0, 1, '?');
	Picture.DrawLine(0, 0, 19, 19,'*');

	Picture.Print();
	
	return 0;
}