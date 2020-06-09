#include "../../include/table/row.hh"
#include "../../include/table/cell.hh"
#include <string>
#include <iostream>
#include <vector>

Row::Row(int rowNumber) {
    this->rowNumber = rowNumber;
}

void Row::destroyCells() {
    this->cells.clear();
}

void Row::trim(std::string & value) {
    std::string::iterator it = value.begin();

    while(*it == ' ') {
        value.erase(it);
        it = value.begin();
    }

    it = value.end();
    while(*it == ' ') {
        value.erase(it);
        it = value.end();
    }
}

bool Row::isValueDouble(const std::string & value) {
    try {
        std::stod(value);
        return true;
    } catch(std::invalid_argument e) {
        return false;
    }
}

bool Row::isValueString(const std::string & value) {
    return *value.begin() == '"' && *(--value.end()) == '"';
}

bool Row::isValueEmpty(const std::string & value) {
    return value.size() == 0;
}

void Row::addCell(unsigned column, std::string value) {
    Cell* cell;
    this->trim(value);

    if(this->isValueDouble(value)) {
        cell = new DoubleCell(this->rowNumber, column, value);
    } else if(this->isValueString(value) || this->isValueEmpty(value)) {
        cell = new StringCell(this->rowNumber, column, value);
    } else {
        std::cout << "ERROR: row"<< this->rowNumber
            << ", col " << column
            << ", "<< value << " is an unknown data type."
            << "\n";

        exit(EXIT_FAILURE);
    }

    if(column > this->cells.size()) {
        for(unsigned i = this->cells.size(); i < column-1; i++) {
            this->cells.push_back(new StringCell(this->rowNumber, i, ""));
        }
        this->cells.push_back(cell);
    } else {
        this->cells[column-1] = cell;
    }

}

void Row::print() {
    for(unsigned i = 0; i < cells.size(); i++) {
        cells[i]->print();
        if(i != cells.size() - 1) {
            std::cout << ",";
        }
    }
}

std::string Row::toRaw() {
    std::string rawForm = "";
    std::string delim = ",";
    for(unsigned i = 0; i < this->cells.size(); i++) {
        if(i == this->cells.size()-1) delim = "";
        rawForm += this->cells[i]->getRawValue() + delim;
    }

    return rawForm;
}

unsigned Row::getCellCount() {
    return this->cells.size();
}

Row::~Row() {
    this->destroyCells();
}
