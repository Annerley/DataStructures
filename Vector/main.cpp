#include "MyVector.h"
#include <iostream>
using namespace std;
int main()
{

	MyVector Vector(5, 5);
	Vector.insert(2, 1);
	Vector.popBack();
	Vector.erase(0, 2);
	
	for (int i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << " ";
	}
	Vector.resize(10, 0);
	cout << endl;
	for (int i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << " ";
	}
	return 0;
}