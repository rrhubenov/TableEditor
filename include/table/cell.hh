#pragma once

#include <string>

class Cell {
    protected:
        int row;
        int column;
        std::string value;
    public:
        Cell(int row, int column, std::string value);

        virtual double parse() = 0;
        virtual void print() = 0;

        int getRow() const;
        int getColumn() const;
        std::string getRawValue() const;

        virtual double operator+(Cell*) = 0; 
        virtual double operator*(Cell*) = 0;
        virtual double operator/(Cell*) = 0;
};


class FormulaCell: public Cell {
    private:
        Cell* lhsCell;
        Cell* rhsCell;
};

class StringCell: public Cell {
    public:
        StringCell(int row, int column, std::string value);

        double parse();
        void print();

        double operator+(Cell*);
        double operator*(Cell*);
        double operator/(Cell*);
};

class DoubleCell: public Cell {};

