#pragma once

#include "./cell.hh"
#include <vector>

/*! \brief Class that represents a row in a table.

Each row class holds the cells which lay on it. This way 
the row becomes a pseudo CellManager.
*/
class Row {
    private:
        int rowNumber; /*!< The row number in the table */
        std::vector<Cell*> cells; /*!< The list of all the cells in the row */

        bool isValueDouble(const std::string &); /*!< Check if a values is a double */
        bool isValueString(const std::string &); /*!< Check if a value is a string */
        bool isValueEmpty(const std::string &); /*!< Check if a values is empty */

        void trim(std::string &); /*!< Trims a string from trailing whitepsaces from front and back */

    public:
        Row(int rowNumber); /*!< Sets the value of the row number */

        unsigned getCellCount(); /*!< Returns the amount of cells in the row */
        void addCell(unsigned column, std::string value); /*!< Logic for adding a cell to the row.
                                                            If the column does not exists, the row gets populated
                                                            with empty cells until the column is reached. */
        void destroyCells(); /*!< Logic for freeing all the cells in the row */
        
        void print(); /*!< Print all the cells in the row with a ',' delimeter */
        std::string toRaw(); /*!< Return the raw values of all the cells */

        ~Row(); /*!< Frees all the cells in the row */
};

