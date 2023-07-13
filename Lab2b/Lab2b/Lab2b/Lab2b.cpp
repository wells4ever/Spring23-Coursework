#include <iostream>
#include <list>
#include <vector>
#include "C:\Users\a00573952\Downloads\Timing.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
	std::vector <int> vectorNums;
	for (int i = 0; i < 10; i++)
	{
		vectorNums.push_back(i);
	}
	

	std::list<int> listNums;
	for (int i = 0; i < 10; i++)
	{
		listNums.push_back(i);
	}

	cout << "\nVector 'front' timer: ";
	Timer* t1 = new Timer;
	int vectorResult = vectorNums.front(); // 200 nanosecs
	delete t1;

	cout << "\nList 'front' timer: ";
	Timer* t2 = new Timer;
	int listResult = listNums.front(); // 100 nanosecs
	delete t2;

	cout << "\nVector 'pop_back' timer: ";
	Timer* t3 = new Timer;
	vectorNums.pop_back(); // 400 nanosecs
	delete t3;
	
	cout << "\nList 'pop_back' timer: ";
	Timer* t4 = new Timer;
	listNums.pop_back(); // 1100 nanosecs
	delete t4;

	cout << "\nVector 'back' timer: ";
	Timer* t5 = new Timer;
	vectorResult = vectorNums.back(); // 200 nanosecs
	delete t5;

	cout << "\nList 'back' timer: ";
	Timer* t6 = new Timer;
	listResult = listNums.back(); // 100 nanosecs
	delete t6;

	//simple operations that output an element run much faster (such as 'front' or 'back') 
	// but operations that manipluate the structure take much longer to process realtive to the 
	//	time taken to process the simple outputs

	return 0;
}
