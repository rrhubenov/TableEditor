#include <vector>
#include <string>

#include "./row.hh"
#include "../file/file_manager.hh"
#include "./observer.hh" 


class TableEditor: public IObserver {
    private:
        FileManager* fileManager;
        std::vector<*Row> rows;

    public:
        TableEditor();

        void update(std::vector<std::string> lines);

        ~TableEditro();
}
