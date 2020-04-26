#include "../../include/file/file_manager.hh"
#include "../../include/table/observer.hh"
#include <string>


void FileManager::openFile(std::string file_path) {
    this->file_stream.open(file_path);

    this->notify();
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


