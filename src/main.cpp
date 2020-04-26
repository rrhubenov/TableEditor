#include "../include/file/file_manager.hh"
#include "../include/table/table_editor.hh"
#include "../include/cli/cli_controller.hh"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    FileManager file_manager;
    TableEditor table_editor(&file_manager);

    file_manager.attach(&table_editor);

    CLIController cli_controller;

    cli_controller.begin_reading();

    return 0;
}
