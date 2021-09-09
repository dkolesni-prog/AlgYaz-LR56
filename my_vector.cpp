//
// Created by Daniil Kolesnik on 31/08/2021.
//



//
// Created by Daniil Kolesnik on 31/08/2021.
//

#include "my_vector.h"

//template<typename T>
//my_vector<T>::my_vector(size_t n, const T &value) {
//    capacity_ = n;
//    number_of_elements = n;
//    data_ = new T[capacity_];
//    for (size_t i = 0; i < number_of_elements; ++i) {
//        data_[i] = value;
//    }
//}
//template<typename T>
//my_vector<T>::my_vector(const my_vector& other){
//    capacity_ = other.capacity_;
//    number_of_elements = other.number_of_elements;
//    T* tmp = new T[capacity_];
//    for (size_t i = 0; i < number_of_elements; ++i) {
//        tmp[i] = other.data_[i];
//    }
//    data_ = tmp;
//}


//template<typename T>
//my_vector<T>::~my_vector() {
//    if (data_) {
//        delete[] data_;
//    }
//}

//template<typename T>
//T &my_vector<T>::at(size_t pos) {
//    // returns data by index //PASS
//    return data_[pos];
//
//}

//template<typename T>
//const T &my_vector<T>::at(size_t pos) const {
//    return data_[pos];
//}

//template<typename T>
//void my_vector<T>::clear() {
//    delete[] this->data_;
//    capacity_ = 1;
//    number_of_elements = 0;
//    data_ = new T[1];
//}

//template<typename T>
//T &my_vector<T>::operator[](size_t pos) {
//    return data_[pos];
//}

//template<typename T>
//const T &my_vector<T>::operator[](size_t pos) const {
//    return data_[pos]; // return element by index in a constant way
//}

//template<typename T>
//T &my_vector<T>::front() {
//    return data_[0]; // returns the first element
//}

//template<typename T>
//const T &my_vector<T>::front() const {
//    return data_[0]; // returns the first element in a constant way
//}

//template<typename T>
//T &my_vector<T>::back() {
//    return data_[number_of_elements - 1]; // returns the last element
//}

//template<typename T>
//const T &my_vector<T>::back() const {
//    return data_[number_of_elements - 1]; // returns the last element in a constant way
//}

//template<typename T>
//size_t my_vector<T>::size() const {
//    return number_of_elements;
//}

//template<typename T>
//size_t my_vector<T>::capacity() const {
//    return capacity_;
//}

//template<typename T>
//T *my_vector<T>::data() {
//    return data_;
//}

//template<typename T>
//const T *my_vector<T>::data() const {
//    return data_;
//}

//template<typename T>
//my_iterator<T> my_vector<T>::begin() {
//    return my_iterator<T>(&data_[0]);
//}

//template<typename T>
//my_iterator<T> my_vector<T>::begin() const {
//    return my_iterator(&data_[0]);
//}

//template<typename T>
//my_iterator<T> my_vector<T>::end() {
//    return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element
//}
//
//template<typename T>
//my_iterator<T> my_vector<T>::end() const {
//    return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element in a constant way
//
//}

//template<typename T>
//bool my_vector<T>::empty() const {
//    return number_of_elements == 0;
//}

//template<typename T>
//void my_vector<T>::swap(my_vector &other) {
//    auto tmp = std::move(*this);
//    *this = std::move(other);
//    other = std::move(tmp);
//}

//template<typename T>
//void my_vector<T>::pop_back() {
//    if (number_of_elements == 1) {
//        delete[] data_;
//        capacity_ = 1;
//        number_of_elements = 0;
//        data_ = new T[1];
//    }
//    else {
//        --number_of_elements;
//    }
//}

//template<typename T>
//void my_vector<T>::push_back(const T &value) {
//    if (number_of_elements + 1 > capacity_) reserve(capacity_ * factor);
//    data_[number_of_elements] = value;
//    ++number_of_elements;
//}

//template<typename T>
//void my_vector<T>::reserve(size_t new_cap) {
//    if (new_cap <= capacity_) return;
//    // capacity_ = new_cap;
//    //cap
//
//    T* tmp = new T[new_cap];
//    for (size_t i = 0; i < number_of_elements; ++i) {
//        tmp[i] = data_[i];
//    }
//    delete[] data_;
//    data_ = tmp;
//    capacity_ = new_cap;
//}

//template<typename T>
//void my_vector<T>::resize_(size_t count, const T &value) {
//    size_t max_right = 0;
//    size_t threshold_l = 0; //minleft
//    if (count == number_of_elements) return;
//    if (number_of_elements > count) {
//        number_of_elements = count;
//        capacity_ = count + 1;
//        return;
//    }
//
//    if (number_of_elements < count) {
//        size_t old_size = this->number_of_elements;
//        T* tmp = new T[count + 1];
//        size_t new_size = count;
//        number_of_elements = count;
//        capacity_ = count + 1;
//        threshold_l = count;
//
//        for (size_t i = 0; i < old_size; ++i) {
//            tmp[i] = data_[i];
//        }
//        for (size_t i = old_size; i < count; ++i) {
//            tmp[i] = value;
//        }
//        delete[] data_;
//        data_ = tmp;
//        capacity_ = new_size + 1;
//        number_of_elements = new_size;
//        return void();
//    }
//
//}

//template<typename T>
//my_iterator<T> my_vector<T>::insert(my_iterator<T> iter, T value) {
//    auto tmp = iter - begin(); // элементов между тначалом и куда указали
//    if (number_of_elements + 1 > capacity_) {
//        reserve(number_of_elements * factor);
//        iter = begin() + tmp; // ?
//    }
//    auto initial_value = *iter.get_pos();
//    auto it = end();
//    for (; it > iter; --it) {
//        *it = *(it - 1);
//    }
//    *it = value;
//    ++number_of_elements;
//    return it;
//}

//template<typename T>
//my_iterator<T> my_vector<T>::erase(const my_iterator<T> pos) {
//    for (auto it = pos; it < end() - 1; ++it) {
//        *it = *(it + 1);
//    }
//    --number_of_elements;
//    return pos;
//}

//template<typename T>
//my_iterator<T> my_vector<T>::erase(const my_iterator<T> first, const my_iterator<T> last) {
//    auto new_size = number_of_elements - (last - first);
//    auto new_data_ = new T[capacity_];
//    size_t idx = 0;
//    auto it = begin();
//    for (; it != first; ++it) {
//        new_data_[idx++] = *it;
//    }
//    it = last;
//    auto tmp = idx;
//    for (; it != end(); ++it) {
//        new_data_[idx++] = *it;
//    }
//    delete[] data_;
//    data_ = new_data_;
//    number_of_elements = new_size;
//    return my_iterator<T>(new_data_ + tmp);
//}

