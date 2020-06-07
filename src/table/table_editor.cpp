#include "../../include/table/table_editor.hh"
#include "../../include/file/file_manager.hh"
#include "../../include/table/row.hh"

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

TableEditor::TableEditor(FileManager* fileManager) {
    this->fileManager = fileManager;
}

void TableEditor::destroyRows() {
    this->rows.clear();
}

void TableEditor::update(std::vector<std::string> lines) {
    this->destroyRows();

    unsigned longest_row = 0;
    
    for(unsigned i = 0; i < lines.size(); i++) {
        Row* row = new Row(i);

        std::string tmp;
        unsigned column = 1;
        std::stringstream ss(lines[i]);

        while(std::getline(ss, tmp, ',')) {
            row->addCell(column, tmp);
            column++;
        }

        if(longest_row < column) longest_row = column-1;

        this->rows.push_back(row);
    }

    for(Row* row: rows) {
        if(row->getCellCount() < longest_row) {
            row->addCell(longest_row, "");
        }
    }
}

void TableEditor::print() {
    for(Row* row: this->rows) {
        row->print();
        std::cout << "\n";
    }
}

std::string TableEditor::toRaw() {
    std::string rawContents = "";
    std::string delim = "\n";

    for(unsigned i = 0; i < this->rows.size(); i++) {
        if(i == this->rows.size() - 1) delim = "";
        rawContents += this->rows[i]->toRaw() + delim;
    }

    return rawContents;
}

void TableEditor::save() {
    std::string rawContents = this->toRaw();
    this->fileManager->save(rawContents);
}

void TableEditor::saveAs(std::string file_path) {
    std::string rawContents = this->toRaw();
    this->fileManager->saveAs(file_path, rawContents);
}

TableEditor::~TableEditor() {
    this->destroyRows();
}

void TableEditor::addCell(unsigned row, unsigned column, std::string value) {
    if(this->rows[0]->getCellCount() < column) {
        for(Row* row: this->rows) {
            row->addCell(column, "");
        }
    }

    if(this->rows.size() < row) {
        for(unsigned i = this->rows.size(); i < row; i++) {
            Row* row = new Row(i);

            row->addCell(column, "");

            this->rows.push_back(row);
        }
    }

    this->rows[row-1]->addCell(column, value);
}
