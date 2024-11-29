#include "Array.h"
#include <iostream>

int main() {
    Array arr1(5);

    Array arr2(5, true);
    arr2.Show();

    Array arr3(5, 10, 50);
    arr3.Show();

    arr1.Random(20, 30);
    arr1.Show();

    arr1.Sort();
    arr1.Show();

    std::cout << "Min: " << arr1.Min() << std::endl;
    std::cout << "Max: " << arr1.Max() << std::endl;

    return 0;
}
