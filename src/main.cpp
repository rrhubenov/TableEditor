#include "../include/file/file_manager.hh"
#include "../include/table/table_editor.hh"
#include "../include/cli/cli_controller.hh"
#include "../include/cli/commands.hh"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    FileManager file_manager;
    TableEditor table_editor(&file_manager);

    file_manager.attach(&table_editor);

    CLIController cli_controller;

    Open* openCommand = new Open(&file_manager);
    Print* printCommand = new Print(&table_editor);
    SaveAs* saveAsCommand = new SaveAs(&table_editor);
    Edit* editCommand = new Edit(&table_editor);
    Save* saveCommand = new Save(&table_editor);
    Exit* exitCommand = new Exit();

    cli_controller.register_command(openCommand);
    cli_controller.register_command(printCommand);
    cli_controller.register_command(saveAsCommand);
    cli_controller.register_command(editCommand);
    cli_controller.register_command(saveCommand);
    cli_controller.register_command(exitCommand);

    cli_controller.begin_reading();

    return 0;
}
