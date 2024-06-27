#include <iostream>

extern int global_counter; 

class Point {
    static unsigned counter;
    int x, y;
public:
    Point() : x(0), y(0) { ++counter; }

    static unsigned get_counter() { return counter; }

};

unsigned Point::counter = 0;

int main() {
    Point pt, pt2;

    std::cout << Point::get_counter() << std::endl;
    std::cout << pt.get_counter() << std::endl;

    return 0;
}