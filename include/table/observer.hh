#include <string>
#include <vector>

class IObserver {
    public:
         virtual void update(std::vector<std::string> lines) = 0;
}
