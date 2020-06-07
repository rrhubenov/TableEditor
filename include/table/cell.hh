#pragma once

#include <string>

class Cell {
    protected:
        int row;
        int column;
        std::string value;
    public:
        Cell(int row, int column, std::string value);
        virtual ~Cell() = 0;

        virtual double parse() = 0;
        virtual void print() = 0;

        int getRow() const;
        int getColumn() const;
        std::string getRawValue() const;

        virtual double operator+(Cell*); 
        virtual double operator*(Cell*);
        virtual double operator/(Cell*);
};


class FormulaCell: public Cell {
    private:
        Cell* lhsCell;
        Cell* rhsCell;
    public:
        FormulaCell(int row, int column, std::string value);

        double parse();
        void print();
};

class StringCell: public Cell {
    public:
        StringCell(int row, int column, std::string value);

        double parse();
        void print();
};

class DoubleCell: public Cell {
    public:
        DoubleCell(int row, int column, std::string value);

        double parse();
        void print();
};

