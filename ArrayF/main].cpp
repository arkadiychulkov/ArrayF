#include "Array.h"
#include <iostream>

int main() {
    Array arr1(5, true);
    arr1.Show();
    Array arr2(arr1);
    arr2.Show();

    std::cout << "Min: " << arr1.Min() << std::endl;
    std::cout << "Max: " << arr1.Max() << std::endl;

    return 0;
}
