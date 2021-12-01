#include "advent/Input.h"

vector<string> getInputStrings(string filename) {
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

vector<int> getInputInts(string filename)
{
    vector<int> ints;
    vector<string> strings = getInputStrings(filename);
    for (string str : strings) {
        ints.push_back(stoi(str));
    }
    return ints;
}

