#include "MealyMachineMinimization.h"
#include "MooreMachineMinimization.h"
#include "CommonFunctions.h"
#include <set>

using namespace std;

int inpSymbCount = 0, outpSymbCount = 0, topsCount = 0;
string automaticType;

void MinimizationMealy(ifstream &inputFile, ofstream &outputFile)
{
	vector<vector<vectorItem>> mainTable;

	FillMainTableMealy(inputFile, mainTable, inpSymbCount, topsCount);

	vector<int> outputSymbols = GenerateSequence(topsCount);
	vector<int> divideForGroups(topsCount);

	int groupNumber = 1;
	for (unsigned int i = 0; i < outputSymbols.size(); ++i)
	{
		for (unsigned int j = i + 1; j < outputSymbols.size(); ++j)
		{
			if (CompareTwoColumns(mainTable, outputSymbols[i] - 1, outputSymbols[j] - 1, inpSymbCount))
			{
				divideForGroups[outputSymbols[j] - 1] = groupNumber;
				outputSymbols.erase(outputSymbols.begin() + DeletedIndex(outputSymbols[j], j));
				j -= 1;
			}
		}
		divideForGroups[outputSymbols[i] - 1] = groupNumber;
		outputSymbols.erase(outputSymbols.begin() + DeletedIndex(outputSymbols[i], i));
		i -= 1;
		groupNumber += 1;
	}

	vector<vector<int>> groupsTable(inpSymbCount);
	for (int i = 0; i < inpSymbCount; ++i)
	{
		groupsTable[i].resize(topsCount);
	}

	FillMainTableDividedByGroupsMealy(groupsTable, mainTable, divideForGroups, inpSymbCount, topsCount);

	outputSymbols = GenerateSequence(topsCount);

	bool compareFlag = false;
	while (!compareFlag)
	{
		compareFlag = true;
		int groupIndex = 1;
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
							if (CompareTwoColumns(groupsTable, outputSymbols[i] - 1, outputSymbols[j] - 1, inpSymbCount))
							{
								divideForGroups[outputSymbols[j] - 1] = groupIndex;
								outputSymbols.erase(outputSymbols.begin() + DeletedIndex(outputSymbols[j], j));
								j -= 1;
							}
						}
						else
							continue;
					}
					divideForGroups[outputSymbols[i] - 1] = groupIndex;
					outputSymbols.erase(outputSymbols.begin() + DeletedIndex(outputSymbols[i], i));
					i -= 1;
					groupIndex += 1;
				}
				else
				{
					continue;
				}
			}
		}
		outputSymbols = GenerateSequence(topsCount);
		FillMainTableDividedByGroupsMealy(groupsTable, mainTable, divideForGroups, inpSymbCount, topsCount);
		compareFlag = CheckColumnsForEqual(groupsTable, inpSymbCount, topsCount, groupIndex, outputSymbols, divideForGroups);
		groupNumber = groupIndex;
	}


	OutputSomeVectors(divideForGroups);
	cout << endl;

	FillMainTableDividedByGroupsMealy(groupsTable, mainTable, divideForGroups, inpSymbCount, topsCount);

	//вывод в консоль миним-ого автомата
	for (int i = 0; i < inpSymbCount; ++i)
	{
		for (int j = 0; j < topsCount; ++j)
		{
			cout << groupsTable[i][j] << " ";
		}
		cout << endl;
	}

	vector<vector<vectorItem>> minimizeTable;
	FillMinimizeTableMealy(minimizeTable, inpSymbCount, groupNumber, divideForGroups, mainTable);
	WriteMealyToFile(outputFile, minimizeTable, inpSymbCount, minimizeTable[0].size());
}

void MinimizationMoore(ifstream &inputFile, ofstream &outputFile)
{
	vector<string> outputSymbols;
	vector<vector<string>> mainTable;

	FillMainTableMoore(inputFile, mainTable, outputSymbols, inpSymbCount, topsCount);

	OutputMainTableMoore(mainTable, inpSymbCount, topsCount);

	vector<int> divideForGroups(topsCount);
	vector<int> outputSymbols1 = GenerateSequence(topsCount);

	int groupNumber = 1;
	for (unsigned int i = 0; i < outputSymbols1.size(); ++i)
	{
		for (unsigned int j = i + 1; j < outputSymbols1.size(); ++j)
		{
			if (CheckOutputSymbolsForEqual(outputSymbols, outputSymbols1[i] - 1, outputSymbols1[j] - 1, inpSymbCount))
			{
				divideForGroups[outputSymbols1[j] - 1] = groupNumber;
				outputSymbols1.erase(outputSymbols1.begin() + DeletedIndex(outputSymbols1[j], j));
				j -= 1;
			}
		}
		divideForGroups[outputSymbols1[i] - 1] = groupNumber;
		outputSymbols1.erase(outputSymbols1.begin() + DeletedIndex(outputSymbols1[i], i));
		i -= 1;
		groupNumber += 1;
	}

	vector<vector<int>> groupsTable(inpSymbCount);
	for (int i = 0; i < inpSymbCount; ++i)
	{
		groupsTable[i].resize(topsCount);
	}

	FillMainTableDividedByGroupsMoore(groupsTable, mainTable, divideForGroups, inpSymbCount, topsCount);

	outputSymbols1 = GenerateSequence(topsCount);

	bool compareFlag = false;
	while (!compareFlag)
	{
		compareFlag = true;
		int groupIndex = 1;
		for (int newGroupIndex = 1; newGroupIndex < groupIndex + 1; ++newGroupIndex)
		{
			for (unsigned int i = 0; i < outputSymbols1.size(); ++i)
			{
				if (divideForGroups[outputSymbols1[i] - 1] == newGroupIndex)
				{
					for (unsigned int j = i + 1; j < outputSymbols1.size(); ++j)
					{
						if (divideForGroups[outputSymbols1[j] - 1] == newGroupIndex)
						{
							if (CompareTwoColumns(groupsTable, outputSymbols1[i] - 1, outputSymbols1[j] - 1, inpSymbCount))
							{
								divideForGroups[outputSymbols1[j] - 1] = groupIndex;
								outputSymbols1.erase(outputSymbols1.begin() + DeletedIndex(outputSymbols1[j], j));
		
								j -= 1;
							}
						}
						else
							continue;
					}
					divideForGroups[outputSymbols1[i] - 1] = groupIndex;
					outputSymbols1.erase(outputSymbols1.begin() + DeletedIndex(outputSymbols1[i], i));
					i -= 1;
					groupIndex += 1;
				}
				else
				{
					continue;
				}
			}
		}
		outputSymbols1 = GenerateSequence(topsCount);
		FillMainTableDividedByGroupsMoore(groupsTable, mainTable, divideForGroups, inpSymbCount, topsCount);
		compareFlag = CheckColumnsForEqual(groupsTable, inpSymbCount, topsCount, groupIndex, outputSymbols1, divideForGroups);
		groupNumber = groupIndex;
	}

	FillMainTableDividedByGroupsMoore(groupsTable, mainTable, divideForGroups, inpSymbCount, topsCount);

	vector<vector<string>> minimizeTable;
	vector<string> newOutputSymbols;

	FillMinimizeTableMoore(minimizeTable, inpSymbCount, groupNumber, divideForGroups, mainTable, outputSymbols, newOutputSymbols);
	WriteMooreToFile(outputFile, minimizeTable, inpSymbCount, minimizeTable[0].size(), newOutputSymbols);
}

int main(int argc, char* argv[])
{
	string fileInputName = "input.txt";
	string fileOutputName = "output.txt";
	ifstream inputFile(fileInputName, ifstream::in);
	if (!inputFile.good())
	{
		return 1;
	}
	ofstream outputFile(fileOutputName, ios::out);

	inputFile >> inpSymbCount >> outpSymbCount >> topsCount >> automaticType;
	if (automaticType == "MR")
	{
		MinimizationMoore(inputFile, outputFile);
	}
	else if (automaticType == "ML")
	{
		MinimizationMealy(inputFile, outputFile);
	}
	inputFile.close();
	outputFile.close();
	return 0;
}