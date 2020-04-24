#include <string>
#include <iostream>
#include <fstream>

class ICommand {
    std::string name;
    public:
        virtual void execute() = 0;
};

class Open: ICommand {
    private:
        void tableEditor;
    public:
        Open(void tableEditor) {
            this.tableEditor = tableEditor;
        }

        void execute(std::string fileName) {
            //Opens file and registers it to the table editor
        }
};

class Close: ICommand {
    private:
        void tableEditor;
    public:
        Close(void tableEditor) {
           this.tableEditor = tableEditor; 
        }

        void execute() {
            //Remove the file from the table editor
        }
};

class Save: ICommand {
    private:
        void tableEditor;
    public:
        Save(void tableEditor) {
            this.tableEditor = tableEditor;
        }

        void execute() {

        }
};

class SaveAs: ICommand {
    private:
        void tableEditor;
    public:
        SaveAs(void tableEditor)
        void execute() {

        }
};

class Help: ICommand {
    public:
        void execute() {

        }
};

class Exit: ICommand {
    public:
        void execute() {

        }
};

class Edit: ICommand {
    public:
        void execute() {

        }
};
