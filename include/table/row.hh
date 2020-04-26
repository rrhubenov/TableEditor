#pragma once

#include "./cell.hh"
#include <vector>

class Row {
    private:
        std::vector<Cell*> cells;

    public:
        Cell* getCell(int column);
        void addCell(std::string value, int column);

        ~Row();
};

