#include <iostream>

class Point {
    int x{0}, y{0};
public:
    mutable int count_call {0};

    Point(int a = 0, int b = 0) : x(a), y(b) { }

    void set_coords(const Point& p) {
        x = p.x; y = p.y;
        int a, b;
        p.get_coords(a, b);
        std::cout << a << "\t" << b << std::endl;
        a = p.get_x();
        std::cout << a << std::endl;
        count_call++;
    }

    const int& get_x() const { count_call++; return x; }

    const int* get_y() const { count_call++; return &y; }

    void get_coords(int& x, int& y) const {
        count_call++;
        x = get_x(); y = *get_y();
    }
};

int main() {
    Point pt, pt2(1, 10);
    pt.set_coords(pt2);

    int x, y;
    pt.get_coords(x, y);
    std::cout << x << "\t" << y << std::endl;
    std::cout << pt.count_call<< std::endl;

    return 0;
}