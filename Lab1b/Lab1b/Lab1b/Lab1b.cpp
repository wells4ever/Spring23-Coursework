#include <iostream>
#include "MyArray.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
	MyArray<int, 5> Mult5;
	MyArray<int, 10> Numbers;
	MyArray<char, 6> AlphaA2F;

	
	for (int i = 0; i < 5; i++)
	{
		Mult5.ModifyElement(i, i * 5);
	};

	cout << "Multiples of 5 array: " << endl;
	Mult5.print();

	for (int i = 0; i < 10; i++)
	{
		Numbers.ModifyElement(i, i + 1);
	};
	
	cout << "Numbers array: " << endl;
	Numbers.print();

	AlphaA2F.ModifyElement(0, 'a');
	AlphaA2F.ModifyElement(1, 'b');
	AlphaA2F.ModifyElement(2, 'c');
	AlphaA2F.ModifyElement(3, 'd');
	AlphaA2F.ModifyElement(4, 'e');
	AlphaA2F.ModifyElement(5, 'f');

	cout << "Char array: " << endl;
	AlphaA2F.print();
	
	cout << "Element at index 4: "
		<< AlphaA2F.getElementAt(4) << endl;




}