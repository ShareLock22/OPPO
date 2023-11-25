#include "Sea.h"

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>

void Sea::load_txt(std::istream& ist)
{
        std::string buffer;
        while(ist >> buffer){
            NameOfSea.append(buffer);
            if (buffer.back() == '"'){
                break;
            }
            NameOfSea.append(" ");
        }
        if (buffer.empty()){
            throw (std::runtime_error("Пустое поле"));
        }

        if(NameOfSea[0] != '"' or buffer.back() != '"'){
            throw (std::runtime_error("Ошибка формата данных"));
        }

        ist >> deep;
        ist >> salty;

        if (deep < 0){
            throw (std::runtime_error("Глубина не может быть меньше нуля"));
        }
        if (0 >= salty && salty <= 100){
            throw (std::runtime_error("Соленость измерятеся в процентах (от 0 до 100)"));
        }

        std::string Alphabet = "QWERTYUIOPASDFGHJKLZXCVBNMËЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ-";
        std::transform(NameOfSea.begin(), NameOfSea.end(), NameOfSea.begin(), ::toupper);
        for (int i = 0; i < NameOfSea.size(); i++){
            if (Alphabet.find(NameOfSea[i])){
                throw (std::runtime_error("Использование недопустимого символа в названии моря"));
            }
        }


}

void Sea::print_txt(std::ostream& ost)
{
    ost << NameOfSea<< "/n";
    ost << deep << "/n";
    ost << salty << "/n";

}
