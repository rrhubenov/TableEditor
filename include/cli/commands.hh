#pragma once
#include <string>
#include <vector>

#include "../table/table_editor.hh"
#include "../file/file_manager.hh"

/*! \brief Interface for all the commands.


Following the Command pattern, this interface
has an execute method which accepts args.
*/


class ICommand {
    public:
        virtual void execute(std::vector<std::string> args) = 0; /*!< Runs the business logic for the command */
        virtual std::string getName() = 0; /*!< Method that specifies the command's name */

        virtual ~ICommand() = 0;
};

/*! \brief Command for opening a document

Uses the file manager to open files
by giving it a file path
*/
class Open: public ICommand {
    private:
        FileManager* fileManager;

    public:
        Open(FileManager* fileManager);

        void execute(std::vector<std::string> args);
        std::string getName();
};

/*! \brief Command for closing an opened file.

Uses the file manager to close opened files.
Can only open files after closing.
*/
class Close: public ICommand {
    private:
        FileManager* fileManager;

    public:
        Close();

        void execute(std::vector<std::string> args);
        std::string getName();
};

/*! \brief Command for saving changes in the current file.

Uses the table editor to write changes to the opened file.
*/
class Save: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        Save(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};

/*! \brief Command for saving changes as a new file

Uses the table editor to write the changes to a new file
*/
class SaveAs: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        SaveAs(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};

/*! \brief Command that prints the available commands

*/
class Help: public ICommand {
    public:
        Help();

        void execute(std::vector<std::string> args);
        std::string getName();
};

/*! \brief Command that exits the application

Uses the exit() function to shut down the application
*/
class Exit: public ICommand {
    public:
        Exit();

        void execute(std::vector<std::string> args);
        std::string getName();
};

/*! \brief Command that prints the current table

Uses the table editor to print all the cells in the 
current file.
*/
class Print: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        Print(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};


/*! \brief Command for editing a cell in a table.

Uses the table editor to add/edit a cell in 
the current file.
*/
class Edit: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        Edit(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};
