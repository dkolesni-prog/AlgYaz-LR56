//
// Created by Daniil Kolesnik on 18/05/2021.
//all rights and lefts reserved

#include <iostream>
#include "my_vector.h"
#include<string>
#include <algorithm>


//1) at +
//2) [] +
//3) front +
//4) back +
//5) data +
//6) begin //implemented in insert and erase
//7) end //implemented in insert
//8) empty +
//9) size +
//10) reserve //implemented in insert
//11) capacity +
//12) clear +
//13) insert (вставка элемента) +
//14) erase (удаление по итератору , удаление
//диапазона по итераторам) ++
//15) push_back +
//16) pop_back +
//17) resize +
//18)swap +



int main() {




    my_vector<int> test_insert;

    test_insert.push_back(1);
    test_insert.push_back(2);
    test_insert.push_back(3);
    test_insert.push_back(4);
    test_insert.push_back(5);

    std::cout << "Before: " << std::endl;
    for (const auto& item : test_insert) {
        std::cout << item << std::endl;
    }

    std::cout << "number of elements after: " << test_insert.number_of_elements << std::endl
              << " capacity before: " << test_insert.capacity_ << std::endl;

    std::cout << "-------------------------" << std::endl;




    // auto it = test_insert.erase(test_insert.begin() + 2);//  erase по итератору
     //auto it = test_insert.erase(test_insert.begin() + 2, test_insert.end());// erase по диапазону

    test_insert.insert(test_insert.begin() + 2, 0);// insert по итератору
    std::cout << "After: " << std::endl;
    for (const auto& item : test_insert) {
        std::cout << item << std::endl;
    }

    std::cout << "number of elements after: " << test_insert.number_of_elements << std::endl
    << " capacity after: " << test_insert.capacity_ << std::endl;
   // std::cout << "deleted: " << " ' " << *it << " ' " << std::endl;


    return 0;
}