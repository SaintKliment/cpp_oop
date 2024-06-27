#include "pointnd.h"

// [тип данных] <имя класса>::<элемент класса>

const PointND& PointND::operator=(const PointND& other) {
    if(this == &other) {
        return *this;
    }
    delete[] coords;
    total = other.total;
    coords = new int[total];
    set_coords(other.coords, other.total);
    
    return *this;
}

void PointND::set_coords(int* cr, unsigned len) {
    for (unsigned i = 0; i < total; ++i) {
        coords[i] = (i < len) ? cr[i] : 0;
    }
}