#ifndef FISH_H
#define FISH_H

#include "Sea.h"

#include <string>
#include <iostream>
#include <fstream>

struct Fish {
    std::string NameOfFish;
    Sea sea;
    void load(std::istream& ist);
    void print(std::ostream& ost);
};



#endif // RATE_H