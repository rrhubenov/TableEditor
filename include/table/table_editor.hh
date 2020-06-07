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
        
        std::string toRaw();

    public:
        TableEditor(FileManager* fileManager);

        void save();
        void saveAs(std::string file_path);

        void addCell(unsigned row, unsigned column, std::string value);

        void update(std::vector<std::string> lines);

        void print();

        void destroyRows();

        ~TableEditor();
};

