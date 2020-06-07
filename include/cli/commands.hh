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

class Close: public ICommand {
    private:
        FileManager* fileManager;

    public:
        Close();

        void execute(std::vector<std::string> args);
        std::string getName();
};

class Save: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        Save(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};

class SaveAs: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        SaveAs(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};

class Help: public ICommand {
    public:
        Help();

        void execute(std::vector<std::string> args);
        std::string getName();
};

class Exit: public ICommand {
    public:
        Exit();

        void execute(std::vector<std::string> args);
        std::string getName();
};

class Print: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        Print(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};

class Edit: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        Edit(TableEditor* tableEditor);

        void execute(std::vector<std::string> args);
        std::string getName();
};
