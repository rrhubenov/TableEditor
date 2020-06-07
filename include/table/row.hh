#pragma once

#include "./cell.hh"
#include <vector>

class Row {
    private:
        int rowNumber;
        std::vector<Cell*> cells;

        bool isValueDouble(const std::string &);
        bool isValueString(const std::string &);
        bool isValueEmpty(const std::string &);

        void trim(std::string &);

    public:
        Row(int rowNumber);

        Cell* getCell(int);
        unsigned getCellCount();
        void addCell(unsigned column, std::string value);
        void destroyCells();
        
        void print();
        std::string toRaw();

        ~Row();
};

