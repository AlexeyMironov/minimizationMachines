#include "MealyMachineMinimization.h"
#include "CommonFunctions.h"

bool CompareTwoColumns(const vector<vector<vectorItem>> &mainTable, const int firstColumn, const int secondColumn, const int &inpSymbCount)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		if (mainTable[i][firstColumn].outputSymbol != mainTable[i][secondColumn].outputSymbol)
		{
			return false;
		}
	}
	return true;
}

void FillMainTableDividedByGroupsMealy(vector<vector<int>> &groupsTable, const vector<vector<vectorItem>> &mainTable, const vector<int> &divideForGroups, const int &inpSymbCount, const int &topsCount)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		for (int j = 0; j < topsCount; ++j)
		{
			int index, groupIndex;
			index = StringToInteger(mainTable[i][j].condition);
			groupIndex = divideForGroups[index - 1];
			groupsTable[i][j] = groupIndex;
		}
	}
}

void FillMainTableMealy(ifstream &inputFile, vector<vector<vectorItem>> &mainTable, int &inpSymbCount, int &topsCount)
{
	mainTable.resize(inpSymbCount);
	for (int i = 0; i < inpSymbCount; ++i)
	{
		mainTable[i].resize(topsCount);
		vectorItem currNode;
		for (int j = 0; j < topsCount; ++j)
		{
			inputFile >> currNode.condition >> currNode.outputSymbol;
			mainTable[i][j] = currNode;
		}
	}
}

void WriteMealyToFile(ofstream &outputFile, const vector<vector<vectorItem>> &mainTable, const int &inpSymbCount, const int &topsCount)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		for (int j = 0; j < topsCount; ++j)
		{
			outputFile << mainTable[i][j].condition << " " << mainTable[i][j].outputSymbol << " ";
		}
		outputFile << endl;
	}
}

void FillMinimizeTableMealy(vector<vector<vectorItem>> &minimizeTable, const int &inpSymbCount, const int &groupNumber, vector<int> &divideForGroups, const vector<vector<vectorItem>> &mainTable)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		vector<vectorItem> curr;
		for (int index = 1; index < groupNumber + 1; ++index)
		{
			for (unsigned int j = 0; j < divideForGroups.size(); ++j)
			{
				if (divideForGroups[j] == index)
				{
					vectorItem currItem;
					currItem = mainTable[i][j];
					curr.push_back(currItem);
					break;
				}
			}
		}
		minimizeTable.push_back(curr);
	}
}