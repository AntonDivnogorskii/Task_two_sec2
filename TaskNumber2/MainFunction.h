#pragma once

enum testingOrSolution
{
	testing = 0, solution = 1
};

enum entryPoints
{
	endOfInput = 0, manually, fromTheFile, saveDataInAFile
};

enum outputOrOutput
{
	quit = 0, output, newData, addData
};

enum trackingForInputFromAFile
{
	firstValue = 1, secondValue, thirdValue, fourthValue, fifthValue, sixValue
};

enum correctValues
{
	nothing = 0, symbol, number
};

int mainFunction(const int choice);