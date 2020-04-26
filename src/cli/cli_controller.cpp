#include "../../include/cli/cli_controller.hh"
#include "../../include/cli/commands.hh"
#include <string.h>
#include <iostream>

CLIController::CLIController() {
    this->commands_count = 0;
}

CLIController::~CLIController() {
    for(unsigned i; i < this->commands_count; i++) {
        delete this->commands[i];
    }
}

void CLIController::begin_reading() {
    while(true) {
        char input[256];

        std::cout << "> ";
        std::cin.getline(input, 256);

        char* pch = strtok(input, " ");

        char commandName[256];
        
        short tokenCount = 0;
        char args[256][256] = {{0}};

        while(pch != NULL) {
            if(tokenCount == 0) {
                strcpy(commandName, pch);
                tokenCount++;
                continue;
            }
            pch = strtok(NULL, " ");
            if(pch != NULL) {
                strcpy(args[tokenCount - 1], pch);
                tokenCount++;
            }
        }

        this->execute_command(commandName, args);
    }
}

void CLIController::register_command(ICommand* command) {
    this->commands[this->commands_count] = command;
    this->commands_count++;
}

void CLIController::execute_command(char* command_name,
        char args[256][256]) {
    for(unsigned i = 0; i < this->commands_count; i++) {
        if(!strcmp(this->commands[i]->getName(), command_name)) {
            this->commands[i]->execute(args);
            return;
        }
    }
    std::cout << command_name << ": Command not found" << "\n";
}
