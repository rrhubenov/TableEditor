#include <vector>
#include <string>
#include "../table/observer.hh"

class ISubject {
    private:
        std::vector<IObserver*> observers;

    public:
        virtual void attach(IObserver* observer) = 0;

        virtual void notify() = 0;

        virtual void detach(IObserver* observer) = 0;
}
