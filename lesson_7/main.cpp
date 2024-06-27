#include <iostream>
#include "pointnd.h"

using std::cout;
using std::endl;

int main() {
    PointND pt(5);

    int cr[5] = {1, 2, 3, 4, 5};
    pt.set_coords(cr, 5);
    const int* coords = pt.get_coords();
    cout << coords;
    return 0;
}