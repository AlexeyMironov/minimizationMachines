#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void FillMainTableMoore(ifstream &inputFile, vector<vector<string>> &mainTable, vector<string> &outputSymbols, int &inpSymbCount, int &topsCount);
bool CheckOutputSymbolsForEqual(vector<string> outputSymbols, const int firstColumn, const int secondColumn, const int &inputSymbolsCount);
void FillMainTableDividedByGroupsMoore(vector<vector<int>> &groupsTable, const vector<vector<string>> &mainTable, const vector<int> &divideForGroups, const int &inputSymbolsCount, const int &topsCount);
void OutputMainTableMoore(const vector<vector<string>> &mainTable, const int &inputSymbolsCount, const int &topsCount);
void FillMinimizeTableMoore(vector<vector<string>> &minimizeTable, const int &inputSymbolsCount, const int &groupNumber, const vector<int> &divideForGroups, const vector<vector<string>> &mainTable, const vector<string> &outputSymbols, vector<string> &newOutputSymbols);
void WriteMooreToFile(ofstream &outputFile, const vector<vector<string>> &minimizeTable, const int &inputSymbolsCount, const int &topsCount, const vector<string> &outputSymbols);