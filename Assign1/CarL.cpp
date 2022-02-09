//#include "Car.h"
//
//class CarLs 
//{
//public:
//	Car* c[100];
//	int i;
//	CarLs() 
//	{
//		i = 0;
//	}
//	~CarLs() {
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