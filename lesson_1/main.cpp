#include <iostream>

struct Point { // для описания набора данных
    int x, y;
};

class Point2D { // для описания объектов
    int x, y; 

public:
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
    // Point2D::get_coords;

    Point pt; // stackVar
    Point* ptr_pt = new Point; // *heapVar

    // pt.x = 1; по стандарту в структуре переменные = публичные

    delete ptr_pt; // Освобождение памяти в куче

    Point2D pt2D; // stackVar
    Point2D* ptr_pt2D = new Point2D; // *heapVar

    // pt2D.x = 120; по стандарту в классе переменный = приватные

    delete ptr_pt2D;

    return 0;
}