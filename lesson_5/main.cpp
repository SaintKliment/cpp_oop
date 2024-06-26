#include <iostream>

using std::cout;
using std::endl;

class Log {
    unsigned id {0};
public:
    Log(unsigned id_log) : id(id_log) { cout << "LOG initialized" << endl;}
    
    ~Log()
        { cout << "Log destructor" << endl; }
};

class Point {
    int x {-1};
    int y {-1};
    Log lg {5};

public:
    Point() : x(0), y(0) 
        { cout << "Point initialized" << endl; }
    Point(int a, int b) : x(a), y(b), lg(1)
        { cout << "Point initialized" << endl; }
    
    ~Point()
        { cout << "Point destructor" << endl; }

    void get_coords(int& a, int& b) { a = x; b = y; }
    void set_coords(int a, int b) { x = a; y = b; }
};

int main() {
    Point pt1, pt2(1, 2);
    Point* ptr_pt1 = new Point;
    Point* ptr_pt2 = new Point(10, 20);

    delete ptr_pt1;
    delete ptr_pt2;

    return 0;
}