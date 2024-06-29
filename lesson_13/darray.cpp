#include "darray.h"

void DArray::_resize_array(int size_new) {
    if (size_new <= capacity) {
        return;
    } 
    while ( capacity <= size_new ) {
        capacity *= resize_factor;
        if(capacity >= max_length_array) {
            capacity = max_length_array;
            break;
        }
    }

    int *p = new int[capacity];
    for (int i = 0; i < length; ++i) {
        p[i] = data[i];
    }
    delete[] data;
    data = p;    
}

const DArray& DArray::operator=(const DArray& other) {
    if (this == &other) {
        return other;
    }
    length = other.length;
    capacity = other.capacity;
    
    delete[] data;
    data = new int[capacity];
    for (int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
    
    return other;
}

void DArray::push_back(int value) {
    if(length > capacity) {
        _resize_array(capacity * resize_factor);
    }
    if(length < capacity) {
        data[length++] = value;
    }
}


int DArray::pop_back() {
    if(length  > 0) {
        return data[--length];
    }
    return value_error;
}