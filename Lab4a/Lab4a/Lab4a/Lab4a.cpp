#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class BethesdaGames
{
public: 
	string name;
	int completionHours;

	BethesdaGames(string name, int completionHours)
		: name(name), completionHours(completionHours)
	{}

	void print()
	{
		cout << "Name: " << name << "\t" << "Hours to complete(100%): " << completionHours << endl;
	}

	friend std::ostream& operator<<(std::ostream& output, const BethesdaGames& g)
	{
		output << "Name " << g.name << "\tHours to completion: " << g.completionHours;
		return output;
	}
	
};

const int ARRAY_SIZE = 3;



int main()
{
	BethesdaGames game1("Skyrim", 233);
	BethesdaGames game2("Fallout 4", 157);
	BethesdaGames game3("New Vegas", 133);

	BethesdaGames games[ARRAY_SIZE] =
	{
		game1, game2, game3
	};


	cout << "List pre-sort: " << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << games[i] << endl;

	}

	std::sort(games, games + 2,
		[](const BethesdaGames& current, const BethesdaGames& next)
		{
			return current.name < next.name;
		});

	cout << "List post-sort (name): " << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		
		cout << games[i] << endl;
		
	}
	cout << "///I'm unsure why this is not sorting correctly, as it isn't putting 'N' before 'S'" << endl;
	
	std::sort(games, games + 2,
		[](const BethesdaGames& current, const BethesdaGames& next)
		{
			return current.completionHours > next.completionHours;
		}); 

	cout << "\nList post-sort (descending hours to complete): " << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		
		cout << games[i] << endl;

	}


}

