#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Sea.h"
#include "FIsh.h"

using namespace std;

void load_txt(vector<Sea>& data, istream& ist)
{
    while (!ist.eof())
    {
        Sea d;
        d.load_txt(ist);
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
    vector <Sea> data;
    ifstream in("ist.txt");
    ofstream ost("ost.txt");
    if(!in.is_open()){
        cout << "Ошибка, файл для считывания не открыт";
    }
    if(!ost.is_open()){
        cout << "Ошибка, файл для записи не открыт";
    }
    try {
        load_txt(data, in);
    }
    catch (std::runtime_error &e){
        cout << e.what();
    }

    try {
        print_data(data, ost);
    }
    catch (std::runtime_error &e){
        cout << e.what();
    }
    return 0;
}
