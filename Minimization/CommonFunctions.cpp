#include "CommonFunctions.h"

int StringToInteger(const string &strToInt)
{
	return atoi(strToInt.c_str() + 1);
}

vector<int> GenerateSequence(const int &topsCount)
{
	vector<int> output;
	for (int i = 1; i < topsCount + 1; ++i)
	{
		output.push_back(i);
	}
	return output;
}

void OutputSomeVectors(vector<int> vector) 
{
	for (unsigned int k = 0; k < vector.size(); ++k)
	{
		cout << vector[k] << " ";
	}
}

int DeletedIndex(const int itemValue, const int item)
{
	return (itemValue - (itemValue - item));
}

bool CompareTwoColumns(const vector<vector<int>> &groupsTable, const int firstColumn, const int secondColumn, const int &inpSymbCount)
{
	for (int i = 0; i < inpSymbCount; ++i)
	{
		if (groupsTable[i][firstColumn] != groupsTable[i][secondColumn])
		{
			return false;
		}
	}
	return true;
}

bool CheckColumnsForEqual(const vector<vector<int>> &groupsTable, const int &inpSymbCount, const int &topsCount, const int &groupIndex, const vector<int> &outputSymbols, const vector<int> &divideForGroups)
{
	for (int newGroupIndex = 1; newGroupIndex < groupIndex + 1; ++newGroupIndex)
	{
		for (unsigned int i = 0; i < outputSymbols.size(); ++i)
		{
			if (divideForGroups[outputSymbols[i] - 1] == newGroupIndex)
			{
				for (unsigned int j = i + 1; j < outputSymbols.size(); ++j)
				{
					if (divideForGroups[outputSymbols[j] - 1] == newGroupIndex)
					{
						if (!(CompareTwoColumns(groupsTable, outputSymbols[i] - 1, outputSymbols[j] - 1, inpSymbCount)))
						{
							return false;
						}
					}
					else
						continue;
				}
			}
			else
				continue;
		}
	}
	return true;
}