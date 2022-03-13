#include "Canvas.h"
#include <iostream>

using std::cout;
using std::endl;

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int left = x - ray;
	int right = x + ray;
	int top = y - ray;
	int bottom = y + ray;

	for (int X = left; X <= right; X++)
		for (int Y = top; Y <= bottom; Y++)
		{
			int d = (X - x) * (X - x) + (Y - y) * (Y - y);
			if (d <= ray * ray + 4 && d >= ray * ray -4)
				SetPoint(X, Y, ch);
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int left = x - ray;
	int right = x + ray;
	int top = y - ray;
	int bottom = y + ray;

	for (int X = left + 1; X < right; X++)
		for (int Y = top + 1; Y < bottom; Y++)
		{
			int d = (X - x) * (X - x) + (Y - y) * (Y - y);
			if (d < ray * ray - 4) SetPoint(X, Y, ch);
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int x = left; x <= right; x++)
	{
		SetPoint(x, top, ch);
		SetPoint(x, bottom, ch);
	}
	for(int y = top + 1; y < bottom; y++)
	{
		SetPoint(left, y, ch);
		SetPoint(right, y, ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top + 1; i < bottom; i++)
		for (int j = left + 1; j < right; j++)
			SetPoint(j,i, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, p, x = x1, y = y1;
	dx = x2 - x;
	dy = y2 - y;
	p = 2 * (dy)-(dx);
	while (x <= x2)
	{
		if (p < 0)
		{
			p = p + 2 * (dy);
		}
		else
		{
			y = y + 1;
			p = p + 2 * (dy - dx);
		}
		x = x + 1;
		SetPoint(x, y, '*');
	}
}

void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		cout << endl;
		for (int j = 0; j < width; j++)
			cout << matrix[i][j] << ' ';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			SetPoint(i, j, ' ');
}
