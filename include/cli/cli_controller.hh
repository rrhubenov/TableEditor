#pragma once
#include "commands.hh"

/*! \brief Class that handles communication with the CLI (Command line interface)
 * 
 * It's main goal is to recognise and execute commands.
 * It is a part of the Command pattern.
 */
class CLIController {
    private:
        std::vector<ICommand*> commands; /*!< List of registered commands */

        void execute_command(std::string command_name,
                std::vector<std::string> args); /*!< Finds the command based on the given name
                                                    and triggers the commands execute() method
                                                    by passing it the given args */

    public:
        void begin_reading(); /*!< Reads and parses lines from the CLI */
        void register_command(ICommand* command); /*!< Adds the command to the commands vector */

        ~CLIController(); /*!< Destructor frees all the commands */
};
