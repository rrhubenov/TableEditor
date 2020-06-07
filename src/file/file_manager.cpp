#include "../../include/file/file_manager.hh"
#include "../../include/table/observer.hh"
#include <string>
#include <iostream>
#include <fstream>

FileManager::FileManager() {
    this->file_path = "";
}

void FileManager::open(std::string file_path) {
    this->file_stream.open(file_path);
    this->file_path = file_path;

    this->notify();

    this->file_stream.close();
}

void FileManager::attach(IObserver* observer) {
    this->observers.push_back(observer);
}


void FileManager::notify() {
    std::string line;
    std::vector<std::string> lines;

    while(std::getline(this->file_stream, line)) {
        lines.push_back(line);
    }

    for(unsigned i = 0; i < this->observers.size(); i++) {
        this->observers[i]->update(lines);
    }
}

void FileManager::save(std::string contents){
    if(this->file_path != "") {
        this->file_stream.open(file_path);
        this->file_stream << contents;
        this->file_stream.close();
    } else {
        std::cout << "ERROR: No file open." << "\n";
    }
}

void FileManager::saveAs(std::string file_path, std::string contents) {
    std::ofstream output_file(file_path);
    output_file << contents;
    output_file.close();
}

FileManager::~FileManager() {
    this->file_stream.close();
}
