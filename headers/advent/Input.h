#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readInputFile(string filename);
vector<int> parseInts(vector<string> strings);
vector<int> parseCSVInts(string s);