#pragma once

#include <iostream>
#include <fstream>
#include<sstream>

using std::string;


/// <param name="filePath">ex:"C:/Users/Work/Desktop/helloWorld.cpp"</param>
/// <returns>a string variable containing all text of file</returns>
string readFile(string filePath)
{
	std::ifstream inputFile;

	inputFile.open(filePath);

	if (inputFile.fail())
	{
		return "File not found!";
	}

	std::stringstream buffer;

	buffer << inputFile.rdbuf();

	string fileContents;

	fileContents = buffer.str();

	inputFile.close();

	return fileContents;
}