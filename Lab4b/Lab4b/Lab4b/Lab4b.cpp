#include <vector>
#include <iostream>
#include <algorithm>
#include "C:\Users\a00573952\Downloads\Timing.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

auto generateRandomVector(int elementCount)//a “utility” function
{
	std::vector<int> result;
	for (int i = 0; i < elementCount; i++)
	{
		result.push_back(rand() % elementCount);
		//should be easy to see if sorted
	}
	return result;
}

void print(const std::vector<int>& nums)
{
	for (auto& num : nums)
	{
		cout << num << " ";
	}
	//cout << "\n";
	//cout << "Press Enter for next update to array:";
	//cin.ignore();//adds a pause for algo visualization
}

void ascendingSort(std::vector<int>& nums, const int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (nums[i] > nums[j])//then swap
			{
				std::swap(nums[i], nums[j]);
				//print(nums); //print updated array for visualization:
			}
		}
		//cout << "Incrementing i to: " << i + 1 << endl;
	}
}

int main()
{
	auto vec10k = generateRandomVector(10000); //generate vector of 10,000 elements
	auto vec100 = generateRandomVector(100); //vector of 100 elements
	auto vec100k = generateRandomVector(100000); //vector of 100,000 elements

	auto copyVec10K = vec10k;
	auto copyVec100 = vec100;
	auto copyVec100k = vec100k;

	cout << "std::sort - 10k elements: " << endl;
	Timer* t10k = new Timer;
	std::sort(vec10k.begin(),vec10k.end());
	delete t10k; //4.05 ms

	cout << "ascendingSort - 10k elements: " << endl;
	Timer* copyT10k = new Timer;
	ascendingSort(copyVec10K, 10000);
	delete copyT10k; //1365.03 ms

	cout << "std::sort 100 elements: " << endl;
	Timer* t100 = new Timer;
	std::sort(vec100.begin(), vec100.end());
	delete t100; // 0.0214 ms

	cout << "ascendingSort - 100 elements: " << endl;
	Timer* copyT100 = new Timer;
	ascendingSort(copyVec100, 100);
	delete copyT100; // 0.1197 ms

	cout << "std::sort 100k elements: " << endl;
	Timer* t100k = new Timer;
	std::sort(vec100k.begin(), vec100k.end());
	delete t100k; // 50.9228 ms

	cout << "ascendingSort - 100k elements: " << endl;
	Timer* copyT100k = new Timer;
	ascendingSort(copyVec100k, 100000);
	delete copyT100k; // 87012.6 ms
}