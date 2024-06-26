#include <iostream>

using std::cout;
using std::endl;

class PointND {
    unsigned total {0};
    int *coords {nullptr};
public:
    PointND() : total(0), coords(nullptr) { }
    PointND(unsigned sz) : total(sz) { 
        coords = new int[total] {0};
        }
    PointND(int* cr, unsigned len) : total(len) {
        coords = new int[total];
        set_coords(cr, len);
    }

    PointND(const PointND& other) : total(other.total) { // copy constructor
        coords = new int[total];
        set_coords(other.coords, total);
        cout << "copy constructor" << endl;
    }

    ~PointND() {
        delete[] coords;
    }

    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len) {
        for (unsigned i = 0; i < total; ++i) {
            coords[i] = (i < len) ? cr[i] : 0;
        }
    }

    const PointND& operator=(const PointND& other) {
        if(this == &other) {
            return *this;
        }

        delete[] coords;
        total = other.total;
        coords = new int[total];
        set_coords(other.coords, other.total);

        return *this;
    }
};

int main() {
    PointND pt(5);
    PointND pt2;

    pt2 = pt;
    pt2 = pt2;

    return 0;
}