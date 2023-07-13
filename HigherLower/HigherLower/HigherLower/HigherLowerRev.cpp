#include <iostream>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

void pause(int);

int main()
{
	int h; //upper bound
	int l = 0;		//lower bound
	int guess; //User guessed value
	char proceedChar; //user input to continue or stop game


	cout << "Let's play a guessing game." << endl;
	cout << "Please pick an integer to set as the highest possible number." << endl;
	cin >> h;
	
	cout << "Generating random number..." << endl;
	pause(1);
	cout << "..." << endl;
	pause(1);
	cout << "..." << endl;
	pause(1);
	cout << "..." << endl;
	pause(1);
	cout << "..." << endl;
	pause(1);
	

	int numToGuess = rand() % (h - l) + l; //generate random number between 0 and user input value

	do //game loop
	{

		cout << "Please enter your guess." << endl;
		cin >> guess;

		if (guess < numToGuess)
		{
			cout << "Your guess is low, try again" << endl;
		}
		if (guess > numToGuess)
		{
			cout << "Your guess is high, try again" << endl;
		}
		if (guess == numToGuess)
		{
			cout << "Correct! The number was: " << numToGuess << endl;
			break;
		}
		cout << "Do you want to keep guessing?" << endl;
		cout << "y - yes, n - No" << endl;
		cin >> proceedChar;

		if (proceedChar == 'n')
		{
			cout << "The number was: " << numToGuess << ". Better luck next time!" << endl;
		}
	} while (guess != numToGuess && proceedChar == 'y');

	return 0;

}

void pause(int dur) //function to delay program execution
{
	int temp = time(NULL) + dur;
	while (temp > time(NULL));
}