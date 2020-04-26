#include "../../include/cli/cli_controller.hh"
#include "../../include/cli/commands.hh"

#include <iostream>
#include <sstream>
#include <string>


CLIController::~CLIController() {
    for(unsigned i; i < this->commands.size(); i++) {
        delete this->commands[i];
    }
}

void CLIController::begin_reading() {
    while(true) {
        std::string input;

        std::cout << "> ";
        std::getline(std::cin, input);

        std::stringstream ss(input);

        std::string command_name;
        std::string arg;
        std::vector<std::string> args;

        std::getline(ss, command_name, ' ');

        while(std::getline(ss, arg, ' ')) {
            args.push_back(arg);
        }

        this->execute_command(command_name, args);
    }
}

void CLIController::register_command(ICommand* command) {
    this->commands.push_back(command);
}

void CLIController::execute_command(std::string command_name,
        std::vector<std::string> args) {
    for(unsigned i = 0; i < this->commands.size(); i++) {
        if(!this->commands[i]->getName().compare(command_name)) {
            this->commands[i]->execute(args);
            return;
        }
    }
    std::cout << command_name << ": Command not found" << "\n";
}
