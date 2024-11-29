#include "Array.h"
#include <iostream>

Array::Array(size_t n) {
    size = n;
    array = new int[size];
}

Array::Array(size_t n, bool israndom) {
    size = n;
    array = new int[size];
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

Array::Array(size_t n, int min, int max) {
    if (min <= max) {
        for (size_t i = 0; i < size; i++) {
            array[i] = min + rand() % (max - min);
        }
    }
}

Array::Array(const Array& usar) {
    size = usar.size;
    array = new int[size];
    for (size_t i = 0; i < size; i++) {
        array[i] = usar.array[i];
    }
}

Array::~Array() {
    delete[] array;
}

void Array::Show() {
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
