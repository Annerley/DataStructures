#include "MyVector.h"
#include <iostream>
#include <algorithm>  

using namespace std;
int main()
{

	MyVector Vector(1,-9);
	
		Vector.pushBack(-5);
		Vector.pushBack(-3);
		Vector.pushBack(0);
		Vector.pushBack(1);
		Vector.pushBack(5);
		Vector.pushBack(8);
	
	for (size_t i = 0; i < Vector.size(); i++)
		{
		cout << Vector[i] << " ";
		}
	Vector.sortedSquares(Vector, SortedStrategy::Top);
	for (size_t i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << " ";
	}
	return 0;
}