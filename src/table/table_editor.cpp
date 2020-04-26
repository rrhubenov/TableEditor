#include "../../include/table/table_editor.hh"
#include "../../include/file/file_manager.hh"

#include <string>
#include <vector>

TableEditor::TableEditor(FileManager* fileManager) {
    this->fileManager = fileManager;
}

void TableEditor::update(std::vector<std::string> lines) {
    
}

TableEditor::~TableEditor() {
    for(unsigned i = 0; i < this->rows.size(); i++) {
        delete this->rows[i];
    }
}
