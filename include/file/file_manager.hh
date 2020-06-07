#pragma once

#include "./subject.hh"
#include "../table/observer.hh"

#include <fstream>
#include <string>
#include <vector>

/*! \brief Class for working with files

The Observer pattern is used so that more editor types
can be hooked to this class. When opening a file all observers
are notified and the lines in the file are sent to them.

Main reason for using the Observer pattern was for educational
purposes
*/
class FileManager: public ISubject {
    private:
        std::fstream file_stream; /*!< File stream for the current file */
        std::string file_path; /*!< Path to the current file since fstream does not store it */

        void notify(); /*!< Method for the Observer pattern. Notifies all observers for changes */
    public:
        FileManager(); /*!< Sets the file path to a black string */

        void attach(IObserver* observer); /*!< Method for the Observer pattern. Attaches an observer to the
                                                list of observers */

        void open(std::string file_path); /*!< Sets the file stream to the given file */
        void save(std::string contents); /*!< Saves the contents to the current file */
        void saveAs(std::string file_path, std::string contents); /*!< Saves the contents to a given file */

        ~FileManager(); /*!< Closes the file stream */
};

