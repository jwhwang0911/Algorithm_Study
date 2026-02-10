#include "container.h"
#include <iostream>

int main() {
    container shared_list = {1, 2, 3};
    shared_list.push_front(0);

    std::cout << "first list : " << shared_list;

    std::cout << std::endl;

    container sh_list2 = shared_list;
    sh_list2.push_front(-1);
    std::cout << "add -1 of shared list :" << sh_list2 << std::endl;

    std::cout << "original list : " << shared_list << std::endl;

    shared_list.pop_front();

    std::cout << "pop front : " << shared_list;
}