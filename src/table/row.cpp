#include "../../include/table/row.hh"
#include "../../include/table/cell.hh"

Cell* Row::getCell(int column) {
    return this->cells[column - 1];
}

void Row::addCell(std::string value, int column) {
    if(this->cells.size() >= column) {
        this->cells[column-1]->setValue(value);
    } else {
        for(unsigned i = 0; i < column - this->cells.size(); i++) {
            this->cells.push_back(new Cell(""));
        }
    }
}

Row::~Row() {
    for(unsigned i = 0; i < this->cells.size(); i++) {
        delete this->cells[i];
    }
}
