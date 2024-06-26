#include <iostream>

using std::cout;
using std::endl;

class Point2D { 
    const unsigned max_coord{100};  // нельзя инициализировать в теле конструктора
    int x{0}, y{0}; 
public:
    Point2D(int a = 0, int b = 0) : x(a), y(b) {
        // cout << "constructor" << endl;
    } // больший приоритет чем у инициализации выше

    void set_coords(int a, int b) {
        x = a;
        y = b;
    }
    void get_coords(int& a, int& b) {
        a = x;
        b = y;
    }
};

int main() {
    Point2D pt(1, 2);
    Point2D* ptr_pr = new Point2D(10, 20);

    int x, y;

    pt.get_coords(x, y);
    cout << x << "\t" << y << endl;

    ptr_pr->get_coords(x, y);
    cout << x << "\t" << y << endl;

    delete ptr_pr;

    // Point2D arr_pt[5];

    return 0;
}