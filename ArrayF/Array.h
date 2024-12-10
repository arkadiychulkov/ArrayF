#pragma once
#include <iostream>
template<typename T>
class Array {
private:
    T* array;
    size_t size;
    size_t capacity;

public:
    Array();
    Array(size_t n, bool israndom);
    Array(size_t n, int min, int max);
    Array(const Array& usar);
    Array(Array&& userArr);
    ~Array();

    void Show();
    void Random(int min, int max);
    void Sort();
    void Append(T elem);
    void resize(int newCapacity);
    void Erase(int index);
    void Clear();
    void Reserve(size_t extra);
    void Shrink();

    int Min();
    int Max();
    int GetCopacity();
    int GetSize();

    Array& operator=(const Array& usar);
    Array& operator=(Array&& userArr);
    Array operator+(const Array& other);
    Array& operator+=(const Array& other);

    int& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        for (size_t i = 0; i < arr.size; i++) {
            os << arr.array[i] << " ";
        }
        os << std::endl;
        return os;
    }

    bool operator==(const Array& other);
    bool operator!=(const Array& other);
    bool operator>(const Array& other);
    bool operator<(const Array& other);
};

template<typename T>
Array<T>::Array() {
    size = 0;
    capacity = 10;
    array = new int[capacity];
}

template<typename T>
Array<T>::Array(size_t n, bool israndom) {
    size = n;
    capacity = n+10;
    array = new int[capacity];
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

template<typename T>
Array<T>::Array(size_t n, int min, int max) {
    size = n;
    capacity = n + 10;
    array = new int[capacity];
    if (min <= max) {
        for (size_t i = 0; i < size; i++) {
            array[i] = min + rand() % (max - min);
        }
    }
}

template<typename T>
Array<T>::Array(const Array<T>& usar) {
    size = usar.size;
    capacity = usar.capacity + 10;
    array = new int[capacity];
    for (size_t i = 0; i < size; i++) {
        array[i] = usar.array[i];
    }
}

template<typename T>
Array<T>::Array(Array&& userArr) : array(userArr.array), size(userArr.size), capacity(userArr.capacity) {
    userArr.array = nullptr;
    userArr.size = 0;
    userArr.capacity = 0;
}





template<typename T>
Array<T>::~Array() {
    delete[] array;
    size = 0;
    capacity = 0;
}

template<typename T>
void Array<T>::Show() {
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Array<T>::Random(int min, int max) {
    if (min <= max) {
        for (size_t i = 0; i < size; i++) {
            array[i] = min + rand() % (max - min);
        }
    }
}

template<typename T>
void Array<T>::Sort() {
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

template<typename T>
void Array<T>::resize(int newCapacity) {
    T* newArray = new T[newCapacity];
    for (size_t i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

template<typename T>
void Array<T>::Append(T elem) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    array[size++] = elem;
}

template<typename T>
void Array<T>::Erase(int index) {
    for (size_t i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    if (capacity < 10) {
        resize(capacity + 10);
    }
}

template<typename T>
void Array<T>::Clear() {
    delete[] array;
    array = new T[capacity];
    size = 0;
}

template<typename T>
void Array<T>::Reserve(size_t extra) {
    resize(capacity + extra);
}

template<typename T>
void Array<T>::Shrink() {
        resize(size);//я сначала сделал ресайз
}






template<typename T>
int Array<T>::GetCopacity() {
    return capacity;
}

template<typename T>
int Array<T>::GetSize() {
    return size;
}

template<typename T>
int Array<T>::Min() {
    int minVal = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }
    return minVal;
}

template<typename T>
int Array<T>::Max() {
    int maxVal = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& userArr) {
    Array arr(10);

    arr.size = userArr.size;
    arr.array = userArr.array;

    userArr.array = nullptr;
    userArr.size = 0;

    return arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& usar) {
    Array arr(10);
    arr.size = usar.size;
    arr.array = new int[size];
    for (size_t i = 0; i < size; i++) {
        arr.array[i] = usar.array[i];
    }
    return arr;
}

template<typename T>
Array<T> Array<T>::operator+(const Array& other) {
    Array result ;

    for (size_t i = 0; i < size; i++) {
        result.array[i] = this->array[i];
    }

    for (size_t i = 0; i < other.size; i++) {
        result.array[size + i] = other.array[i];
    }

    return result;
}

template<typename T>
Array<T>& Array<T>::operator+=(const Array& other) {
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

template<typename T>
int& Array<T>::operator[](size_t index) {
    return array[index];
}

template<typename T>
bool Array<T>::operator==(const Array<T>& other) {
    for (size_t i = 0; i < size; i++) {
        if (array[i] != other.array[i]) return false;
    }
    return true;
}

template<typename T>
bool Array<T>::operator!=(const Array<T>& other) {
    if (*this == other)
        return false;
    else
        return true;
}

template<typename T>
bool Array<T>::operator>(const Array<T>& other) {
    return this->size > other.size;
}

template<typename T>
bool Array<T>::operator<(const Array<T>& other) {
    return this->size < other.size;
}