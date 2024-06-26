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
    PointND(int* cr, unsigned len) : PointND(len) { // delegate constructor 
        // coords = new int[total];
        set_coords(cr, len);
    }

    PointND(const PointND& other) : PointND(other.coords, other.total) { // copy constructor
        // coords = new int[total];
        // set_coords(other.coords, total);
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
};

int main() {
    PointND pt(5);
    PointND pt2 {pt};

    return 0;
}