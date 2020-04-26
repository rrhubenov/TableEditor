#pragma once

#include <string>

class Cell {
    private:
        std::string value;
    public:
        Cell(std::string value);

        std::string getValue();
        void setValue(std::string value);
};

