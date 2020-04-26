#pragma once

#include <vector>
#include <string>

#include "./row.hh"
#include "../file/file_manager.hh"
#include "./observer.hh" 


class TableEditor: public IObserver {
    private:
        FileManager* fileManager;
        std::vector<Row*> rows;

    public:
        TableEditor(FileManager* fileManager);

        void update(std::vector<std::string> lines);

        ~TableEditor();
};

