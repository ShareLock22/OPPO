#ifndef SEA_H
#define SEA_H

#include <string>
#include <iostream>
#include <fstream>

struct Sea {
    std::string NameOfSea;
    float salty, deep;
    void load_txt(std::istream& ist);
    void print_txt(std::ostream& ost);
};

#endif // RATE_H