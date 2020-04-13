#include <iostream>
#include <string>
#include "cli_controller.h"

int main(int argc, char **argv) {
    CLIController cli_controller = new CLIController();
    //Create table_editor
    //Register commands to the controller
    std::string arguments;
    while(true) {
        std::getline(std::cin, command, " ");
        cli_controller.execute_command(arguments[0], rest_of_args);
    }
}
