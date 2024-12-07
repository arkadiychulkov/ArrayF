#include "Array.h"
#include <iostream>

int main() {
    Array<int> arr1(5, true);
    arr1.Show();
    Array<int> arr2(arr1);
    arr2.Show();

    std::cout << "Min: " << arr1.Min() << std::endl;
    std::cout << "Max: " << arr1.Max() << std::endl;

    std::cout << "+: " << arr1 + arr2 << std::endl;
    std::cout << "[]" << arr1[0] << std::endl;
    std::cout << "<<: " << arr1 << std::endl;
    std::cout << "==: " << (arr1 == arr2) << std::endl;
    std::cout << "!=: " << (arr1 != arr2) << std::endl;
    std::cout << "<: " << (arr1 < arr2) << std::endl;
    std::cout << ">: " << (arr1 > arr2) << std::endl;

    return 0;
}
