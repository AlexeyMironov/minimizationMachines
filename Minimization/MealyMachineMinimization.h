#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct vectorItem
{
	string condition;
	string outputSymbol;
};

bool CompareTwoColumns(const vector<vector<vectorItem>> &mainTable, const int firstColumn, const int secondColumn, const int &inputSymbolsCount);
void FillMainTableDividedByGroupsMealy(vector<vector<int>> &groupsTable, const vector<vector<vectorItem>> &mainTable, const vector<int> &divideForGroups, const int &inputSymbolsCount, const int &topsCount);
void FillMainTableMealy(ifstream &inputFile, vector<vector<vectorItem>> &mainTable, int &inpSymbCount, int &topsCount);
void WriteMealyToFile(ofstream &outputFile, const vector<vector<vectorItem>> &mainTable, const int &inpSymbCount, const int &topsCount);
void FillMinimizeTableMealy(vector<vector<vectorItem>> &minimizeTable, const int &inputSymbolsCount, const int &groupNumber, vector<int> &divideForGroups, const vector<vector<vectorItem>> &mainTable);