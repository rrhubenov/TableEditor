#pragma once

#include "./subject.hh"
#include "../table/observer.hh"

#include <fstream>
#include <string>
#include <vector>


class FileManager: public ISubject {
    private:
        std::fstream file_stream;

        void notify();
    public:
        void attach(IObserver* observer);

        void openFile(std::string file_path);
};

