#include "FIsh.h"
#include <string>
#include <iostream>
#include <fstream>

void Fish::load(std::istream& ist){
    std::string buffer;
    while(ist >> buffer){
        NameOfFish.append(buffer);
        if (buffer.back() == '"'){
            break;
        }
        NameOfFish.append(" ");
    }
    if (buffer.empty()){
        throw (std::runtime_error("Пустое поле"));
    }

    if(NameOfFish[0] != '"' or buffer.back() != '"'){
        throw (std::runtime_error("Ошибка формата данных"));
    }
    std::string Alphabet = "QWERTYUIOPASDFGHJKLZXCVBNMËЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ-";
    std::transform(NameOfFish.begin(), NameOfFish.end(), NameOfFish.begin(), ::toupper);
    for (int i = 0; i < NameOfFish.size(); i++){
        if (Alphabet.find(NameOfFish[i])){
            throw (std::runtime_error("Использование недопустимого символа в названии рыбы"));
        }
    }
}

void Fish::print(std::ostream& ost){
    ost << NameOfFish  << "/n";
    ost << sea.NameOfSea << "/n"; 
}