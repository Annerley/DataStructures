#include "MyVector.h"
#include <iostream>
#include <algorithm>  

using namespace std;
int main()
{

		MyVector Vector(1,-9);
	
	Vector.pushBack(-5);
	Vector.pushBack(-5);
	Vector.resize(2);
	
	for (size_t i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << " ";
	}
	
	
	return 0;
}