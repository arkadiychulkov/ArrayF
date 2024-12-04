#pragma once
#include <iostream>
class Array {
private:
    int* array;
    size_t size;

public:
    Array(size_t n);
    Array(size_t n, bool israndom);
    Array(size_t n, int min, int max);
    Array(const Array& usar);
    Array(Array&& userArr);
    ~Array();

    void Show();
    void Random(int min, int max);
    void Sort();
    int Min();
    int Max();

    Array& operator=(const Array& usar);
    Array& operator=(Array&& userArr);
    Array operator+(const Array& other);
    Array& operator+=(const Array& other);

    int& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& os, const Array& arr);

    bool operator==(const Array& other);
    bool operator!=(const Array& other);
    bool operator>(const Array& other);
    bool operator<(const Array& other);
};

