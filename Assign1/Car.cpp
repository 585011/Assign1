#include <wtypes.h>
#include "Car.h"

class Cars
{
public:
	int n, x, y;
	Cars(int _n, int _x, int _y) : n(_n), x(_x), y(_y)
	{
	}
	void Draw(HDC hdc)
	{
		Rectangle(hdc, x, y, x + 1, y + 1);
	}
};


//class CarList 
//{
////public:
//	Car* c[100];
//	int i;
//	CarList() 
//	{
//		i = 0;
//	}
//	~CarList() {
//		Clear();
//	}
//	void push(Car* aCar) 
//	{
//		c[i++] = aCar;
//	}
//	void Draw(HDC hdc)
//	{
//		for (int j = 0; j < i; j++)
//			c[j]->Draw(hdc);
//	}
//	// Bruker denne for både x og y
//	void MoveX(int dx) 
//	{
//		for (int j = 0; j < i; j++)
//			c[j]->x += dx;
//	}
//	void MoveY(int dy)
//	{
//		for (int j = 0; j < i; j++)
//			c[j]->y += dy;
//	}
//	void Clear() 
//	{
//		for (int j = 0; j < i; j++)
//			delete c[j];
//		i = 0;
//	}
//};