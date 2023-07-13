#include <iostream>
#include <vector>
#include <algorithm>

using std::endl;
using std::cout;
using std::cin;
using std::string;

int counterB = 0;
int counterS = 0;

int sequentialSearch(std::vector<int> nums, int searchValue)

{
	
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == searchValue)
		{
			return i;
		}
		counterS++;
	}
	
	return -1; 

}

int binarySearch(std::vector<int> sortedNums, int searchValue)
{
	bool found = false;
	int first = 0;
	int last = sortedNums.size() - 1;
	int middle = 0;
	
	

		while (first <= last and !found)
		{
			int middle = (first + last) / 2; 
			if (sortedNums[middle] == searchValue)
			{
				found = true;
			}
			else if (sortedNums[middle] > searchValue)
			{
				last = middle - 1;
			}
			else
			{
				first = middle + 1;
			}
			counterB++;
		}
	while (first <= last and !found)
	{
		int middle = (first + last) / 2; 
		if (sortedNums[middle] == searchValue)
		{
			found = true;
		}
		else if (sortedNums[middle] > searchValue)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
		counterB++;
	}
	
		if (found)
		{
			
			return middle;
			
		}
		else
		{
			
			return -1;
			
		}
}



void print(std::vector <int> const& v) {
	std::cout << "The vector elements are : ";

	for (int i = 0; i < v.size(); i++)
		std::cout << v.at(i) << ' ';
}

int main()
{

	
	std::vector<int> evenNums;
	for (int i = 0; i <= 50; i++)
	{
		if (i % 2 == 0)
		{
			evenNums.push_back(i);
		}
		else if (i % 2 !=0)
		{
			continue;
		}
	}

	print(evenNums);

	

	for (int i = 0; i < 5; i++)
	{
		int searchVal = (rand() % 26) * 2;
		cout << "\nSearching for: " << searchVal << endl;
		sequentialSearch(evenNums, searchVal);
		binarySearch(evenNums, searchVal);

		cout << "Guesses needed for sequentialSearch: " << counterS << endl;
		cout << "Guesses needed for binarySearch: " << counterB << endl;
		counterS = 0; //reset counters to 0 for next search iteration
		counterB = 0; //^^
	}


}