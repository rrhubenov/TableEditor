#pragma once
#include "commands.hh"

class CLIController {
    private:
        std::vector<ICommand*> commands;
    public:
        void begin_reading();
        void register_command(ICommand* command);
        void execute_command(std::string command_name,
                std::vector<std::string> args);
        ~CLIController();
};
