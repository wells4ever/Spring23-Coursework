#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

long long fibo(int n)
{
	if (n <= 1)
		return n;
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n; 
	cout << "Which position of the Fibonacci sequence would you like to see? (input a positive integer. max 71.)" << endl;
	cin >> n;
	if (n >= 40)
	{
		cout << "This will take a significant amount of time... are you sure you want to proceed? (y or n)";
		char yesNo;
		cin >> yesNo;
		if (yesNo == 'n')
		{
			cout << "\n\nWhich position would you like to see then?";
			cin >> n;
			cout << fibo(n);
		}
		else if (yesNo == 'y')
		{
			cout << fibo(n);
		}
	}
	else
	{
		cout << fibo(n);
	}

	return 0;
}