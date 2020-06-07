#pragma once

#include "./subject.hh"
#include "../table/observer.hh"

#include <fstream>
#include <string>
#include <vector>


class FileManager: public ISubject {
    private:
        std::fstream file_stream;
        std::string file_path;

        void notify();
    public:
        FileManager();

        void attach(IObserver* observer);

        void open(std::string file_path);
        void save(std::string contents);
        void saveAs(std::string file_path, std::string contents);

        ~FileManager();
};

