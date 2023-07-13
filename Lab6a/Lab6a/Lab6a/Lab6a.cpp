#include <iostream>
#include "fileReading.h"
#include <stack>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

bool isMatch(char openSymbol, char closeSymbol)
{
	if (openSymbol == '(' && closeSymbol == '}')
	{
		return false;
	}
	else if (openSymbol == '{' && closeSymbol == ')')
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool isBalanced(string inputString)
{
	std::stack<char> openSymbolStack;
	for (auto& currentChar : inputString) {
		//check if current char is opening symbol
		if (currentChar == '(' || currentChar == '{') {
			openSymbolStack.push(currentChar);
		}
		if (currentChar == ')' || currentChar == '}')
		{
			if (isMatch(openSymbolStack.top(), currentChar))
			{
				openSymbolStack.pop();
			}
			else 
			{
				return false;
			}
		}
	}
	if (!openSymbolStack.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}




int main()
{
	string filePath1 = "C:\\Users\\a00573952\\source\\repos\\Lab6a\\Lab6a\\balanced.txt";
	string filePath2 = "C:\\Users\\a00573952\\source\\repos\\Lab6a\\Lab6a\\Unbalanced.txt";
	string filePath3 = "C:\\Users\\a00573952\\source\\repos\\Lab6a\\Lab6a\\OtherUnbalanced.txt";

	string f1Content = readFile(filePath1);
	string f2Content = readFile(filePath2);
	string f3Content = readFile(filePath3);
	
	cout << "File 1 content: " << endl;
	cout << f1Content;
	cout << "\n\nIs file balanced (closing brace/parentheses for every open one)?" << endl;
	cout << std::boolalpha;
	cout << isBalanced(f1Content);


	cout << "\n\nFile 2 content: " << endl;
	cout << f2Content;
	cout << "\n\nIs file balanced (closing brace/parentheses for every open one)?" << endl;
	cout << std::boolalpha;
	cout << isBalanced(f2Content);

	cout << "\n\nFile 3 content: " << endl;
	cout << f3Content;
	cout << "\n\nIs file balanced (closing brace/parentheses for every open one)?" << endl;
	cout << std::boolalpha;
	cout << isBalanced(f3Content) << endl;

}

