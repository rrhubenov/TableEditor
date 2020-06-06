#include "../../include/table/cell.hh"
#include <iostream>
#include <string>

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

StringCell::StringCell(int row, int column, std::string value): Cell(row, column, value){}

double StringCell::parse() {
    return 1;
}

void StringCell::print() {
    std::cout << this->value;
}

double StringCell::operator+(Cell* other) {
    return this->parse()+other->parse();
}

double StringCell::operator*(Cell* other) {
    return this->parse()*other->parse();
}

double StringCell::operator/(Cell* other) {
    return this->parse()/other->parse();
}
