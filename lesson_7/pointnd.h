#ifndef _POINTND_H_
#define _POINTND_H_

class PointND {
    unsigned total {0};
    int *coords {nullptr};
    
public:
    PointND() : total(0), coords(nullptr) { }
    
    PointND(unsigned sz) : total(sz) { 
        coords = new int[total] {0};
        }
    
    PointND(int* cr, unsigned len) : PointND(len) { 
        set_coords(cr, len);
    }

    PointND(const PointND& other) : PointND(other.coords, other.total) { }

    const PointND& operator=(const PointND& other); 


    ~PointND() { delete[] coords; }

    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }

    void set_coords(int* cr, unsigned len);
};

#endif