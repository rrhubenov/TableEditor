#pragma once

#include "./cell.hh"
#include <vector>

class Row {
    private:
        int rowNumber;
        std::vector<const Cell*> cells;

    public:
        Row(int rowNumber);
        Cell* getCell(int);
        void addCell(const Cell &);

        ~Row();
};

