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

Array::Array(Array&& userArr): array(userArr.array), size(userArr.size) {
    userArr.array = nullptr;
    userArr.size = 0;
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

Array& Array::operator=(Array&& userArr) {
    Array arr(10);

    arr.size = userArr.size;
    arr.array = userArr.array;

    userArr.array = nullptr;
    userArr.size = 0;

    return arr;
}

Array& Array::operator=(const Array& usar) {
    Array arr(10);
    arr.size = usar.size;
    arr.array = new int[size];
    for (size_t i = 0; i < size; i++) {
        arr.array[i] = usar.array[i];
    }
    return arr;
}

Array Array::operator+(const Array& other) {
    Array result(size + other.size);

    for (size_t i = 0; i < size; i++) {
        result.array[i] = this->array[i];
    }

    for (size_t i = 0; i < other.size; i++) {
        result.array[size + i] = other.array[i];
    }

    return result;
}

Array & Array::operator+=(const Array & other) {
    int* newArray = new int[this->size + other.size];

    for (size_t i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    for (size_t i = 0; i < other.size; i++) {
        newArray[this->size + i] = other.array[i];
    }

    this->array = newArray;
    this->size += other.size;

    return *this;
}

int& Array::operator[](size_t index) {
    return array[index];
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    for (size_t i = 0; i < arr.size; i++) {
        os << arr.array[i] << " ";
    }
    os << std::endl;
    return os;
}

bool Array::operator==(const Array& other) {
    for (size_t i = 0; i < size; i++) {
        if (array[i] != other.array[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) {
    if (*this == other)
        return false;
    else
        return true;
}

bool Array::operator>(const Array& other) {
    return this->size > other.size;
}

bool Array::operator<(const Array& other) {
    return this->size < other.size;
}
