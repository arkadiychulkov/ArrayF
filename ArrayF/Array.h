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
    Array(Array&& userArr);
    ~Array();

    void Show();
    void Random(int min, int max);
    void Sort();
    int Min();
    int Max();
    Array& operator=(Array&& userArr);
};

