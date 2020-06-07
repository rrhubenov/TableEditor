#include "../../include/cli/commands.hh"
#include <iostream>
#include <string>

ICommand::~ICommand() = default;

Print::Print(TableEditor* tableEditor) {
    this->tableEditor = tableEditor;
}

void Print::execute(std::vector<std::string> args) {
    this->tableEditor->print();
}

std::string Print::getName() {
    return "print";
}

Open::Open(FileManager* fileManager) {
    this->fileManager = fileManager;
}

void Open::execute(std::vector<std::string> args) {
    this->fileManager->open(args[0]);
    std::cout << "Successfully opened " << args[0] << "\n";
}

std::string Open::getName() {
    return "open";
}

Save::Save(TableEditor* tableEditor) {
    this->tableEditor = tableEditor;
}

void Save::execute(std::vector<std::string> args) {
    this->tableEditor->save();
}

std::string Save::getName() {
    return "save";
}

SaveAs::SaveAs(TableEditor* tableEditor) {
    this->tableEditor = tableEditor;
}

void SaveAs::execute(std::vector<std::string> args) {
    this->tableEditor->saveAs(args[0]);
}

std::string SaveAs::getName() {
    return "saveas";
}

Edit::Edit(TableEditor* tableEditor) {
    this->tableEditor = tableEditor;
}

void Edit::execute(std::vector<std::string> args) {
    this->tableEditor->addCell(std::stoi(args[0]), std::stoi(args[1]), args[2]);
}

std::string Edit::getName() {
    return "edit";
}

Exit::Exit(){}

void Exit::execute(std::vector<std::string> args) {
    exit(EXIT_SUCCESS);
}

std::string Exit::getName() {
    return "exit";
}
