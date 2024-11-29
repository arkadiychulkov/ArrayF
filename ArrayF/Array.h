#pragma once
class Array {
private:
    int* array;
    size_t size;

public:
    Array(size_t n);
    Array(size_t n, bool israndom);
    Array(size_t n, int min, int max);
    Array(const Array& usar);
    ~Array();

    void Show();
};

//