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
    size = n;
    array = new int[size];
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

void Array::Random(int min, int max) {
    if (min <= max) {
        for (size_t i = 0; i < size; i++) {
            array[i] = min + rand() % (max - min);
        }
    }
}

void Array::Sort() {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int change = array[j];
                array[j] = array[j + 1];
                array[j + 1] = change;
            }
        }
    }
}

int Array::Min() {
    int minVal = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }
    return minVal;
}

int Array::Max() {
    int maxVal = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}
