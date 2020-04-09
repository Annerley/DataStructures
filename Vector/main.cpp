#include "MyVector.h"
#include <iostream>
using namespace std;
int main()
{

	MyVector Vector(5, 5);
	
	MyVector l(2, 1);

	Vector.insert(2, l);
	cout << Vector.find(1, 1);
	for (int i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << " ";
	}

	return 0;
}