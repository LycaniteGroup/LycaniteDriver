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

    std::cout << "Test emplace" << std::endl;

    std::cout << "capacity: " << A.capacity() << std::endl;
    std::cout << "size: " << A.size() << std::endl;
    std::cout << "memsize: " << A.max_size() << std::endl;


    for (int i = 1; i < 10; i++) {
        A.emplace_back(i);
    }

    std::cout << "emplace back: " << std::endl;
    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    Vector<int>::iterator a_iter = A.begin();
    a_iter++;
    a_iter++;

    a_iter = A.emplace(a_iter, 6);

    a_iter = A.emplace(a_iter, 1);

    a_iter++;

    A.emplace(a_iter, 9);

    std::cout << "after emplace: " << std::endl;

    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    A.push_back(666);
    A.push_back(111);

    std::cout << "after push_back: " << std::endl;

    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    A.clear();

    std::cout << "after clear: " << std::endl;
    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    A.resize(5);

    std::cout << "after resize: " << std::endl;
    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    A.resize(3, 666);

    std::cout << "after resize: " << std::endl;
    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    A.resize(10, 999);

    std::cout << "after resize: " << std::endl;
    for(Vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        std::cout << *i << std::endl;
    }

    std::cout << "capacity: " << A.capacity() << std::endl;
    std::cout << "size: " << A.size() << std::endl;
    std::cout << "memsize: " << A.max_size() << std::endl;

    return 0;
}