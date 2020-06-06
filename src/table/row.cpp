#include "../../include/table/row.hh"
#include "../../include/table/cell.hh"

Cell* Row::getCell(int column) {
    return this->cells[column - 1];
}

void Row::addCell(const Cell & cell) {
    if(this->cells.size() >= cell.getColumn()) {
        this->cells[cell.getColumn()-1] = &cell;
    } else {
        for(unsigned i = 0; i < cell.getColumn() - this->cells.size(); i++) {
            this->cells.push_back(new StringCell(this->rowNumber, cell.getColumn(), cell.getRawValue()));
        }
    }
}

Row::~Row() {
    for(unsigned i = 0; i < this->cells.size(); i++) {
        delete this->cells[i];
    }
}
