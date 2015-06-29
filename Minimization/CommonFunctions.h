#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int StringToInteger(const string &strToInt);
vector<int> GenerateSequence(const int &topsCount);
void OutputSomeVectors(vector<int> vector);
int DeletedIndex(const int itemValue, const int item);
bool CompareTwoColumns(const vector<vector<int>> &groupsTable, const int firstColumn, const int secondColumn, const int &inpSymbCount);
bool CheckColumnsForEqual(const vector<vector<int>> &groupsTable, const int &inpSymbCount, const int &topsCount, const int &groupIndex, const vector<int> &outputSymbols, const vector<int> &divideForGroups);