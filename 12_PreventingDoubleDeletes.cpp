#include <iostream>
#include <memory>

class Widget {
    public:
        void greet() {
            std::cout << "Hello from Widget!" << std::endl;
        }
};

int main() {
    // 1. risky pattern, may lead to double delete//////////////////
    // Widget*w = new Widget();
    // w->greet();

    // delete w;   // first delete
    // w->greet(); // undefined behavior

    // delete w;   // second delete, undefined behavior
    /////////////////////////////////////////////////////////////////

    // 1. safer pattern, avoid double delete///////////////////////
    std::unique_ptr<Widget> w = std::make_unique<Widget>();
    w->greet();

    // Smart pointer goes out of scope and cleans up automatically
    // No use-after-free or double delete possible

    ////////////////////////////////////////////////////////////////
    std::cout << std::endl << std::endl;
    return 0;
}