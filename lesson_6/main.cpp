#include <iostream>

class Vector {
    int x {0};
    int y {0};
    Vector(const Vector& other) = default; // use only внутри методов данного класса
public:
    // Vector(int a, int b) : x(a), y(b) {}
    Vector() = default; // delete удаляет default constructor
    // Vector(const Vector& other) {
    //     x = other.x;
    //     y = other.y;
    // }
    // const Vector& operator=(const Vector& left) {
    //     if(this == &left) { return *this;}
    //     this->x = left.x;
    //     this->y = left.y;
    //     return *this;
    // }
};

int main() {
    Vector v1;
    // Vector v2(v1);
    Vector v3;

    v3 = v1;

    return 0;
}