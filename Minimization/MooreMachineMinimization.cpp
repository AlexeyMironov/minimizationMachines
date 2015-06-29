#include "MooreMachineMinimization.h"
#include "CommonFunctions.h"

void FillMainTableMoore(ifstream &inputFile, vector<vector<string>> &mainTable, vector<string> &outputSymbols, int &inpSymbCount, int &topsCount)
{
	outputSymbols.resize(topsCount);
	int i = 0;
	while (i < topsCount)
	{
		inputFile >> outputSymbols[i];
		++i;
	}
	mainTable.resize(inpSymbCount);
	for (int i = 0; i < inpSymbCount; ++i)
	{
		mainTable[i].resize(topsCount);
		string condition;
		for (int j = 0; j < topsCount; ++j)
		{
			inputFile >> condition;
			mainTable[i][j] = condition;
		}
	}
}

bool CheckOutputSymbolsForEqual(vector<string> outputSymbols, const int firstColumn, const int secondColumn, const int &inpSymbCount)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		if (outputSymbols[firstColumn] != outputSymbols[secondColumn])
		{
			return false;
		}
	}
	return true;
}

void FillMainTableDividedByGroupsMoore(vector<vector<int>> &groupsTable, const vector<vector<string>> &mainTable, const vector<int> &divideForGroups, const int &inpSymbCount, const int &topsCount)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		for (int j = 0; j < topsCount; ++j)
		{
			int index, groupIndex;
			index = StringToInteger(mainTable[i][j]);
			groupIndex = divideForGroups[index - 1];
			groupsTable[i][j] = groupIndex;
		}
	}
}

void OutputMainTableMoore(const vector<vector<string>> &mainTable, const int &inpSymbCount, const int &topsCount)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		for (int j = 0; j < topsCount; ++j)
		{
			cout << mainTable[i][j] << " ";
		}
		cout << endl;
	}
}

void FillMinimizeTableMoore(vector<vector<string>> &minimizeTable, const int &inpSymbCount, const int &groupNumber, const vector<int> &divideForGroups, const vector<vector<string>> &mainTable, const vector<string> &outputSymbols, vector<string> &newOutputSymbols)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		vector<string> currLine;
		for (int index = 1; index < groupNumber + 1; ++index)
		{
			for (unsigned int j = 0; j < divideForGroups.size(); ++j)
			{
				if (divideForGroups[j] == index)
				{
					string currItem;
					currItem = mainTable[i][j];
					if (i == 0)
					{
						newOutputSymbols.push_back(outputSymbols[j]);
					}
					currLine.push_back(currItem);
					break;
				}
			}
		}
		minimizeTable.push_back(currLine);
	}
}

void WriteMooreToFile(ofstream &outputFile, const vector<vector<string>> &minimizeTable, const int &inpSymbCount, const int &topsCount, const vector<string> &outputSymbols)
{
	for (auto element : outputSymbols)
	{
		outputFile << element << " ";
	}

	outputFile << endl;

	for (int i = 0; i < inpSymbCount; ++i)
	{
		for (int j = 0; j < topsCount; ++j)
		{
			outputFile << minimizeTable[i][j] << " ";
		}
		outputFile << endl;
	}
}