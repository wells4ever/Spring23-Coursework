#include <iostream>
#include <assert.h>
#include "MyVector.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ostream;


class Grades
{
private:
	char letter;
	int value;

public:
	char getletter()
	{
		return letter;
	}

	int getvalue()
	{
		return value;
	}

	friend ostream& operator<<(ostream& os, const Grades& gr);

	Grades()
		:letter('N'), value(0)
	{
		//empty 
	}

	Grades(char letter, int value)
		:letter(letter) , value(value)
	{
		//empty
	}
};

ostream& operator<<(ostream& os, const Grades& gr)
{
	os << gr.letter << "/" << gr.value;
	return os;
}

int main()
{
	// 2 arrays of different types, one has to be an object of a defined class (Grades)

	MyVector <int> EvenNums;
	

	cout << "Initial EvenNums vector: " << endl;
	for (int i = 0; i < EvenNums.getSize(); i++)
	{
		cout << EvenNums[i] << "\t";
	}

	cout << "\nInitial EvenNums Capacity: " << EvenNums.getCapacity() << endl;

	EvenNums.pushBack(2);
	EvenNums.pushBack(4);
	EvenNums.pushBack(6);

	cout << "Edited EvenNums vector: " << endl;
	for (int i = 0; i < EvenNums.getSize(); i++)
	{
		cout << EvenNums[i] << "\t";
	}



	EvenNums.popBack();

	cout << "\nEvenNums vector after popBack: " << endl;
	for (int i = 0; i < EvenNums.getSize(); i++)
	{
		cout << EvenNums[i] << "\t";
	}

	cout << "\nClearing EvenNums vector... " << endl;
	EvenNums.clear();

	MyVector <Grades> GradesVect;

	cout << "\nInitial Grades vector: " << endl;
	for (int i = 0; i < GradesVect.getSize(); i++)
	{
		cout << GradesVect[i] << "\t";
	}



	Grades A('A', 90);
	Grades B('B', 80);
	Grades C('C', 70);
	Grades D('D', 60);
	Grades F('F', 0);

	GradesVect.pushBack(A);
	GradesVect.pushBack(B);
	GradesVect.pushBack(C);
	GradesVect.pushBack(D);
	GradesVect.pushBack(F);

	cout << "\nEdited Grades Vector: " << endl;
	for (int i = 0; i < GradesVect.getSize(); i++)
	{
		cout << GradesVect[i] << "\t";
	}


	GradesVect.popBack();
	GradesVect.popBack();

	cout << "\nGrades vector after popBack x2: " << endl;
	for (int i = 0; i < GradesVect.getSize(); i++)
	{
		cout << GradesVect[i] << "\t";
	}

	cout << "\nClearing Grades Vector..." << endl;
	GradesVect.clear();


}