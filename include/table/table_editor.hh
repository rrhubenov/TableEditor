#pragma once

#include <vector>
#include <string>

#include "./row.hh"
#include "../file/file_manager.hh"
#include "./observer.hh" 


/*! \brief Class that handles changes to the current table.

Uses the file manager to receive/write changes from/to files.
Consists of a vector of rows and handles the logic for adding more rows.
This way it becomes a pseud RowManager.
*/
class TableEditor: public IObserver {
    private:
        FileManager* fileManager; /*!< Pointer to the file manager */
        std::vector<Row*> rows; /*!< The vector of rows */
        
        std::string toRaw(); /*!< Returns the raw values of all the cells in all the rows */

    public:
        TableEditor(FileManager* fileManager); /*!< Initializes the file manager pointer */

        void save(); /*!< Saves all the values in the rows by using the file manager in the current file */
        void saveAs(std::string file_path); /*!< Saves all the values in the rows by using the file manager to the given file */

        void addCell(unsigned row, unsigned column, std::string value); /*!< Handles the logic for adding 
                a cell to a row. If the row does not exist, more are created until the given row is reached */

        void update(std::vector<std::string> lines); /*!< Populates the rows by parsing the lines */

        void print(); /*!< Prints all the row values by using a new line between the rows */

        void destroyRows(); /*!< Frees all the rows */

        ~TableEditor(); /*!< Frees all the rows */
};

