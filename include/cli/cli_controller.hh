#pragma once

class CLIController {
    private:
        void commands;//List
    public:
        void register_command(void command);
        void execute_command(void command_name, void args);
        void access_data(void data_name);
};
