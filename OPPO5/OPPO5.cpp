// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <string>
#include <fstream>
#include <iostream>
#include "Sea.h"
#include "FIsh.h"
#include <vector>

using namespace std;

void load_txt(vector<Sea>& data, istream& ist)
{
    while (ist.good() && !ist.eof()) // Используем ist.good() и !ist.eof() в условии
    {
        Sea d = Sea::load_txt(ist);
        data.push_back(d);
    }
}

void print_data(vector<Sea>& data, ofstream& ost)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i].print_txt(ost);
        cout << endl;
    }
}

int main()
{
    vector<Sea> data;
    ifstream in("ist.txt");
    ofstream ost("ost.txt");
    load_txt(data, in);
    print_data(data, ost);
    return 0;
}