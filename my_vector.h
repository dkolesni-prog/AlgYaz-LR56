//
// Created by Daniil Kolesnik on 31/08/2021.
//

#ifndef LR5_ISSUERESOLUTION_MY_VECTOR_H
#define LR5_ISSUERESOLUTION_MY_VECTOR_H


#include "my_iterator.h"
#include <stddef.h>
#include <iostream>
template<typename T>
class my_vector {


private:


    size_t capacity_ext = 0;
    size_t capacity_ = 0;
    size_t number_of_elements = 0;
    T* data_ = nullptr;

    double factor = 1.5;



public:

    my_vector() :capacity_(0), number_of_elements(0), data_(new T[1]) {
        capacity_ext = 1;
        capacity_ = 0;
    }

//    my_vector()


    explicit my_vector(size_t n, const T& value){
        capacity_ = n;
        number_of_elements = n;

        data_ = new T[capacity_ + 1]; //fixed in reserve

        for (size_t i = 0; i < number_of_elements; ++i) {
            data_[i] = value;
        }
    }

    my_vector(const my_vector& other){
        capacity_ = other.capacity_;
        number_of_elements = other.number_of_elements;
        T* tmp = new T[capacity_ + 1];
        for (size_t i = 0; i < number_of_elements; ++i) {
            tmp[i] = other.data_[i];
        }
        data_ = tmp;
    }  // copy constructor




    ~my_vector() {
        if (data_) {
            delete[] data_;
        }
    }




    T& at(size_t pos) {

        return data_[pos];

    }

    const T& at(size_t pos) const {
        return data_[pos];
    }


    void clear() {
        delete[] this->data_;
        capacity_ = 1;
        number_of_elements = 0;
        data_ = new T[1];
    }

    T& operator[](size_t pos) {
        try{
            if (pos >= number_of_elements) throw 5.5;
            return data_[pos];
        }
        catch(double) {
            std::cout << " Out of range " << std::endl;
        }
    }

    const T& operator[](size_t pos) const {
        try{
            if (pos >= number_of_elements) throw 5.5;
            return data_[pos];
        }
        catch(double) {
            std::cout << " Out of range " << std::endl;
        }
    }

    T& front() {
        return data_[0];
    }

    const T& front() const {
        return data_[0];
    }

    T& back() {
        return data_[number_of_elements - 1];
    }

    const T& back() const {
        return data_[number_of_elements - 1];
    }

    size_t size() const {
        return number_of_elements;
    } // return number of elements //PASS

    size_t capacity() const {
        return capacity_;
    } // return capacity //PASS

    my_vector& operator=(const my_vector& other) {  // overloading "equalize" operation for 2 vectors
        if (this == &other) std::cout << "youre trying to equalize same objects" << std::endl;
        if (this != &other) { // self initialization check

            delete[] data_;
            capacity_ = other.capacity_;
            number_of_elements = other.number_of_elements;
            T* tmp = new T[capacity_];
            for (size_t i = 0; i < number_of_elements; ++i) {
                tmp[i] = other.data_[i];
            }
            data_ = tmp;

        }
        return *this;
    }

    T* data() {
        return data_;
    } // return data

    const T* data() const {
        return data_;
    } //return data

    my_iterator<T> begin() {
        return my_iterator<T>(&data_[0]);
    } // returns iterator pointed at the first element //PASS

    my_iterator<T> begin() const {
        return my_iterator(&data_[0]);
    } // returns iterator pointed at the first element in a constant way //PASS

    my_iterator<T> end() {
        return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element
    } //PASS

    my_iterator<T> end() const {
        return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element in a constant way

    } //PASS

    bool empty() const {
        return number_of_elements == 0;
    } // if the container is empty returns 1 //PASS

    void swap(my_vector& other) {
        auto tmp = std::move(*this);
        *this = std::move(other);
        other = std::move(tmp);
    }// swapping two vectors with each other //It throws an error if the vector is not of the same type.

    void pop_back() {
        if (number_of_elements == 1) {
            delete[] data_;
            capacity_ = 1;
            number_of_elements = 0;
            data_ = new T[1];
        }
        else {
            --number_of_elements;
        }
    } //PASS

    void push_back(const T& value) {
        if (capacity_ == 1) reserve(2);
        if (number_of_elements + 1 > capacity_){
            if (capacity_ == 0) ++capacity_;
            reserve(capacity_ * factor);
        }
        data_[number_of_elements] = value;
        ++number_of_elements;
    } //PASS

    void reserve(size_t new_cap) {
        if (new_cap <= capacity_){
            return;
        }
        T* tmp = new T[(new_cap * factor) + 1];
        capacity_ext = (new_cap * factor) + 1;
        for (size_t i = 0; i < number_of_elements; ++i) {
            tmp[i] = data_[i];
        }
        delete[] data_;
        data_ = tmp;
        capacity_ = new_cap * factor;
    } //PASS

    void resize_(size_t count, const T& value) {
        size_t max_right = 0;
        size_t threshold_l = 0; //minleft
        if (count == number_of_elements) return;
        if (number_of_elements > count) {
            number_of_elements = count;
            capacity_ = count + 1;
            return;
        }

        if (number_of_elements < count) {
            size_t old_size = this->number_of_elements;
            T* tmp = new T[count + 1];
            size_t new_size = count;
            number_of_elements = count;
            capacity_ = count + 1;
            threshold_l = count;

            for (size_t i = 0; i < old_size; ++i) {
                tmp[i] = data_[i];
            }
            for (size_t i = old_size; i < count; ++i) {
                tmp[i] = value;
            }
            delete[] data_;
            data_ = tmp;
            capacity_ = new_size + 1;
            number_of_elements = new_size;
            return void();
        }

    } //PASS

    my_iterator<T> insert(my_iterator<T> iter, T value) {
        auto tmp = iter - begin(); // элементов между тначалом и куда указали
        if (number_of_elements + 1 > capacity_) {
            reserve(number_of_elements * factor);
            iter = begin() + tmp; // ?
        }
        auto initial_value = *iter.get_pos();
        auto it = end();
        for (; it > iter; --it) {
            *it = *(it - 1);
        }
        *it = value;
        ++number_of_elements;
        return it;
    }



    my_iterator<T> erase(const my_iterator<T> pos) {
        for (auto it = pos; it < end() - 1; ++it) {
            *it = *(it + 1);
        }
        --number_of_elements;
        return pos;
    } //PASS




    my_iterator<T> erase(const my_iterator<T> first, const my_iterator<T> last) {
        auto new_size = number_of_elements - (last - first);
        auto new_data_ = new T[capacity_];
        size_t idx = 0;
        auto it = begin();
        for (; it != first; ++it) {
            new_data_[idx++] = *it;
        }
        it = last;
        auto tmp = idx;
        for (; it != end(); ++it) {
            new_data_[idx++] = *it;
        }
        delete[] data_;
        data_ = new_data_;
        number_of_elements = new_size;
        return my_iterator<T>(new_data_ + tmp);
    } //PASS



   // friend int main();

   size_t get_capacity(){
       return capacity_;
    }
    size_t get_n(){
        return number_of_elements;
    }
    size_t get_ext(){
        return capacity_ext;
    }










};



#endif //LR5_ISSUERESOLUTION_MY_VECTOR_H
