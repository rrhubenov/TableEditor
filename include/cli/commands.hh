#pragma once
#include <string>
#include <vector>

#include "../table/table_editor.hh"
#include "../file/file_manager.hh"

class ICommand {
    public:
        virtual void execute(std::vector<std::string> args) = 0;
        virtual std::string getName() = 0;

        virtual ~ICommand();
};

class Open: public ICommand {
    private:
        FileManager* fileManager;

    public:
        Open();

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
        FileManager* fileManager;

    public:
        Save();

        void execute(std::vector<std::string> args);
        std::string getName();
};

class SaveAs: public ICommand {
    private:
        FileManager* fileManager;

    public:
        SaveAs();

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

    public:
        Print();

        void execute(std::vector<std::string> args);
        std::string getName();
};

class Edit: public ICommand {
    private:
        TableEditor* tableEditor;

    public:
        Edit();

        void execute(std::vector<std::string> args);
        std::string getName();
};
