#include "./subject.hh"
#include "../table/observer.hh"
#include <fstream>

#include <string>
#include <vector>


class FileManager: public ISubject {
    private:
        std::fstream file_stream;

    public:
        FileManager();

        void attach(IObserver* observer);

        void detach(IObserver* observer);

        void notify();

        openFile(std::string file_path);
}
