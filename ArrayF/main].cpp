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

    arr1.Append(1000);
    std::cout << "Append: " << arr1 << std::endl;

    arr1.Erase(5);
    std::cout << "Erase: " << arr1 << std::endl;

    std::cout << "Capacity: " << arr1.GetCopacity() << std::endl;

    arr1.Clear();
    std::cout << "Clear: " << arr1 << std::endl;

    arr1.Shrink();
    std::cout << "Capacity: " << arr1.GetCopacity() << std::endl;

    arr1.Reserve(10);
    std::cout << "Capacity: " << arr1.GetCopacity() << std::endl;

    return 0;
}
