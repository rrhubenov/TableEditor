#pragma once

#include <string>

/*! \brief Cell interface that describes what
all cell classes must implement.

A cell is an element that holds a value and knows how that value
should be printer, calculated with, and parsed.


Using this interface all cell classes can execute operations on eachother.
*/
class Cell {
    protected:
        int row; /*!< Row of the cell. */
        int column; /*!< Column of the cell. */
        std::string value; /*!< Value of the cell in a string form. */
    public:
        Cell(int row, int column, std::string value); /*!< Just populates the fields */
        virtual ~Cell() = 0; /*!< Purely virtual destructor that is used by all children */

        virtual double parse() = 0; /*!< Parses the string value into a calculatable double value */
        virtual void print() = 0; /*!< Prints the value the way it should appear to the client */

        int getRow() const; /*!< Getter for the row */
        int getColumn() const; /*!< Getter for the column */
        std::string getRawValue() const; /*!< Gets the raw value of the cell. Should not be used to front-end */

        virtual double operator+(Cell*); /*!< Sum by parsing both cells */
        virtual double operator*(Cell*); /*!< Multiply by parsing both cell */
        virtual double operator/(Cell*); /*!< Divide by parsing both cells */
};

/*! \brief Class that represents a formula in a cell.

Holds pointers to the cells it operates with.
When parsing, it determines the operation by reading the raw value
and parses the two cells. After which it executes the operation on the
parsed value.
*/
class FormulaCell: public Cell {
    private:
        Cell* lhsCell; /*!< Left-hand side cell in the formula */
        Cell* rhsCell; /*!< Right-hand side cell in the formula */
    public:
        FormulaCell(int row, int column, std::string value); /*!< Uses the parent constructor. */

        double parse(); /*!< Parses lhsCell and rhsCell after which executes the operation on them */
        void print(); /*!< Prints the parsed value to the screen */
};

/*! \brief Class that represents a cell with a string value.

*/
class StringCell: public Cell {
    public:
        StringCell(int row, int column, std::string value); /*!< Calls the parent constructor. */

        double parse(); /*!< Extracts double value from string. If impossible returns 0 */
        void print(); /*!< Prints the raw string to the screen without the quotes */
};

/*! \brief Class that represents a cell with an integer/double value.
*/
class DoubleCell: public Cell {
    public:
        DoubleCell(int row, int column, std::string value); /*!< Call the parent constructor. */

        double parse(); /*!< Returns the value converted to a double */
        void print(); /*!< Prints the value */
};

