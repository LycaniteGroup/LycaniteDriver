#include "Vector.h"
#include <iostream>

int main(void)
{
    Vector<int> A;

    std::cout << "sizeof int : " << sizeof(int) << std::endl;

    A.assign(2, 666);

    A[1] = 333;

    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    std::cout << "capacity (assign.2): " << A.capacity() << std::endl;

    std::cout << "reserve (10): " << std::endl;
    A.reserve(10);
    std::cout << "capacity: " << A.capacity() << std::endl;
    std::cout << "memsize: " << A.max_size() << std::endl;

    A.at(9) = 999;
    std::cout << "A[9] : " << A[9] << std::endl;

    A.shrink_to_fit();
    std::cout << "Shrink to fit : Size : " << A.size() << " Capacity : " << A.capacity() << std::endl;
    std::cout << "memsize: " << A.max_size() << std::endl;

    return 0;
}