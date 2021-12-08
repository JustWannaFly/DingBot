#include "advent/Input.h"

vector<string> readInputFile(string filename) {
    string line;
    vector<string> lines;
    string fileDir = "C:/aocInput/";
    ifstream myfile(fileDir + filename + ".txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            lines.push_back(line);
        }
        myfile.close();
    }

    else cout << "Unable to open file";
    return lines;
}

vector<int> parseInts(vector<string> strings)
{
    vector<int> ints;
    for (string str : strings) {
        ints.push_back(stoi(str));
    }
    return ints;
}

vector<int> parseCSVInts(string s)
{
    s = s + ","; // so last number is grabbed
    vector<int> nums;
    int pos;
    while ((pos = s.find(",")) != string::npos) {
        string part = s.substr(0, pos);
        if (part != "") {
            nums.push_back(stoi(part));
        }
        s.erase(0, pos + 1);
    }
    return nums;
}

vector<string> parseStrVector(string str, string seperator) {
    vector<string> strings;
    int pos;
    str += seperator;
    while ((pos = str.find(" ")) != string::npos) {
        if (str.substr(0, pos) != "") {
            strings.push_back(str.substr(0, pos));
        }
        str.erase(0, pos + seperator.size());
    }
    return strings;
}

