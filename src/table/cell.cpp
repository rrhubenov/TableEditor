#include "../../include/table/cell.hh"
#include <iostream>
#include <string>

Cell::~Cell() = default;

std::string Cell::getRawValue() const {
    return this->value;
}

int Cell::getRow() const {
    return this->row;
}

int Cell::getColumn() const {
    return this->column;
}

Cell::Cell(int row, int column, std::string value): row(row), column(column), value(value){}

double Cell::operator+(Cell* other) {
    return this->parse()+other->parse();
}

double Cell::operator*(Cell* other) {
    return this->parse()*other->parse();
}

double Cell::operator/(Cell* other) {
    return this->parse()/other->parse();
}

StringCell::StringCell(int row, int column, std::string value): Cell(row, column, value){}

double StringCell::parse() {
    return 1;
}

void StringCell::print() {
    if(this->value.length() == 0) {
        std::cout << this->value;
    } else {
        std::string copy = this->value;

        copy.erase(copy.begin());
        copy.erase(copy.end()-1);

        std::cout << copy;
    }
}

DoubleCell::DoubleCell(int row, int column, std::string value): Cell(row, column, value){}

double DoubleCell::parse() {
    return std::stod(this->value);
}

void DoubleCell::print() {
    std::cout << this->value;
}
