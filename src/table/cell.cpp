#include "../../include/table/cell.hh"
#include <string>

Cell::Cell(std::string value) {
    this->value = value;
}

std::string Cell::getValue() {
    return this->value;
}

void Cell::setValue(std::string value) {
    this->value = value; 
}
