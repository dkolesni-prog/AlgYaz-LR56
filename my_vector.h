//
// Created by Daniil Kolesnik on 18/05/2021.
//all rights and lefts reserved

#ifndef INC_5THLABONLY_MY_VECTOR_H
#define INC_5THLABONLY_MY_VECTOR_H

/*ЗДЕСТ ДОЛЖНЫ БЫТЬ
 * !!!!
1) at
2) []
3) front
4) back
5) data
6) begin
7) end
8) empty
9) size
10) reserve
11) capacity
12) clear
13) insert (вставка элемента)
14) erase (удаление по итератору, удаление
диапазона по итераторам)
15) push_back
16) pop_back
17) resize
18)swap ----- !!!!!!!
 ПЛЮС
 1) == +
2) != +
3) -> +
4) * +
5) ++ (правосторонний) +
6) ++ (левосторонний) +
7) -- (правосторонний) + 8) -- (левосторонний) +
9) [] +
10) + (сдвиг + итератор)  +
11) + (итератор + сдвиг)
12) - (итератор – сдвиг) +
13) - (итератор – итератор) +
14) += +
15) -= +
16) > +
17) < +
18) >= +
19) <= +
 */


template<typename T>
class my_iterator {

public:
    using pointer = T*;
    using reference = T&;
    using value_type = T;
    using difference_type = int;
    using iterator_category = std::random_access_iterator_tag;

    pointer pos = nullptr;

    explicit my_iterator(pointer ptr) : pos(ptr) {};// теперь итератор смотрит на ptr.  explicit in order to prevent implicit cast from pointer to my_iterator



    bool operator==(const my_iterator& other) const { //PASS
        return pos == other.pos; // if slots are equal return 1
    }

    bool operator!=(const my_iterator& other) const { //PASS
        return pos != other.pos; // if slots are equal return 0
    }

    pointer operator->() { //PASS
        return pos; // get address of a pointer
    }

    reference operator*() const { //PASS
        return *pos; //return int position
    }

    my_iterator operator+(const difference_type& diff) const { //diff + iterator /10 //PASS
        return my_iterator(pos + diff); // return iterator with position pos + diff
    }



    my_iterator operator-(const difference_type& diff) const { //iterator - diff /12 //PASS
        return my_iterator(pos - diff); // return iterator with position pos - diff
    }

    difference_type operator-(const my_iterator& other) const { // iterator - iterator 13 //PASS
        return std::distance(other.pos, pos);
    } //--------

    bool operator>(const my_iterator& other) const {  //PASS
        return pos > other.pos; // look at the furthest from the origin and return 1 if the furthest 0 if other is the furthest
    }

    bool operator<(const my_iterator& other) const { //PASS
        return pos < other.pos; // look at the furthest from the origin and return 0 if the furthest 1 if other is the furthest
    }
    //-----------
    bool operator>=(const my_iterator& other) const { //PASS
        return pos >= other.pos; // look at the furthest from the origin and return 1 if the furthest 0 if other is the furthest
    } //also returns 1 if both point at the same element

    bool operator<=(const my_iterator& other) const { //PASS
        return pos <= other.pos; // look at the furthest from the origin and return 0 if the furthest 1 if the other is the furthest
    }// also returns 1 if both point at the same element

    reference operator[](size_t index) const { //PASS
        return pos[index]; // returns a reference to an element pointed by index . is pos an array? yes
    }



    my_iterator& operator++() { //right side //PASS
        ++pos;
        return *this;
    }

    my_iterator operator++(int) { //left side //PASS
        my_iterator tmp = *this;
        ++pos;
        return *this;
    }

    my_iterator& operator--() {//right side //PASS
        --pos;
        return *this;
    }

    my_iterator operator--(int) noexcept { //left side //PASS
        my_iterator tmp = *this;
        --pos;
        return tmp;
    }


    my_iterator& operator+=(const difference_type& diff) { // modify pos (+=) //PASS
        pos += diff;
        return *this;
    }

    my_iterator& operator-=(const difference_type& diff) { // modify pos (-=) //PASS
        pos -= diff;
        return *this;
    }

    friend my_iterator operator+(difference_type const& diff, my_iterator const& it) {
        return it + diff;
    } // 11 //iterator + diff


};

template<typename T>
class my_vector {
public:

    my_vector() :capacity_(1), number_of_elements(0), data_(new T[1]) { //def constructor via  initialization list instead of direct

    }

    explicit my_vector(size_t n, const T& value) { //prevent implicit cast // constructor with args
        capacity_ = n;
        number_of_elements = n;
        data_ = new T[capacity_];
        for (size_t i = 0; i < number_of_elements; ++i) {
            data_[i] = value;
        }
    }

    my_vector(const my_vector& other) { // copy constructor
        capacity_ = other.capacity_;
        number_of_elements = other.number_of_elements;
        T* tmp = new T[capacity_];
        for (size_t i = 0; i < number_of_elements; ++i) {
            tmp[i] = other.data_[i];
        }
        data_ = tmp;
    }

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

    ~my_vector() { // according to RAII if weve taken memory we have to give it back;
        if (data_) {
            delete[] data_;
        }
    }


    T& at(size_t pos) { // returns data by index //PASS
        return data_[pos];
    }

    const T& at(size_t pos) const { // returns data by index //PASS
        return data_[pos];
    }


    void clear() { //PASS //clears entire array and invalidates pointers
        delete[] this->data_;
        capacity_ = 1;
        number_of_elements = 0;
        data_ = new T[1];
    };

    T& operator[](size_t pos) {// return element by index and reference //PASS
        return data_[pos];
    }

    const T& operator[](size_t pos) const {
        return data_[pos]; // return element by index in a constant way
    }



    T& front() { //PASS
        return data_[0]; // returns the first element
    }

    const T& front() const { //PASS
        return data_[0]; // returns the first element in a constant way
    }

    T& back() { //PASS
        return data_[number_of_elements - 1]; // returns the last element
    }

    const T& back() const { //PASS 1st const return cant be modified 2nd const liable for non modifying class ch
        return data_[number_of_elements - 1]; // returns the last element in a constant way
    }

    size_t size() const { // return number of elements //PASS
        return number_of_elements;
    }

    size_t capacity() const { // return capacity //PASS
        return capacity_;
    }

    T* data() { // return data //PASS
        return data_;
    }

    const T* data() const { //return data in a constant way //PASS
        return data_;
    }

    my_iterator<T> begin() { // returns iterator pointed at the first element //PASS
        return my_iterator(&data_[0]);
    }

    my_iterator<T> begin() const { // returns iterator pointed at the first element in a constant way //PASS
        return my_iterator(&data_[0]);
    }

    my_iterator<T> end() { //PASS
        return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element
    }

    my_iterator<T> end() const { //PASS
        return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element in a constant way
    }

    bool empty() const { // if the container is empty returns 1 //PASS
        return number_of_elements == 0;
    }

    void swap(my_vector& other) { // swapping two vectors with each other //It throws an error if the vector is not of the same type.

        auto tmp = std::move(*this);
        *this = std::move(other);
        other = std::move(tmp);

    }

    void pop_back() { //PASS
        if (number_of_elements == 1) {
            delete[] data_;
            capacity_ = 1;
            number_of_elements = 0;
            data_ = new T[1];
        }
        else {
            --number_of_elements;
        }
    }

    void push_back(const T& value) { //PASS
        if (number_of_elements + 1 > capacity_) reserve(capacity_ * factor);
        data_[number_of_elements] = value;
        ++number_of_elements;
    }

    void reserve(size_t new_cap) { //PASS
        if (new_cap <= capacity_) return;
        // capacity_ = new_cap;
        //cap

        T* tmp = new T[new_cap];
        for (size_t i = 0; i < number_of_elements; ++i) {
            tmp[i] = data_[i];
        }
        delete[] data_;
        data_ = tmp;
        capacity_ = new_cap;
    }


    void resize_(size_t count, const T& value) { //PASS
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

    }





    my_iterator<T> insert(my_iterator<T> iter, T value) {
        auto tmp = iter - begin(); // элементов между тначалом и куда указали
        if (number_of_elements + 1 > capacity_) {
            reserve(number_of_elements * factor);
            iter = begin() + tmp; // ?
        }
        auto initial_value = *iter.pos;
        auto it = end();
        for (; it > iter; --it) {
            *it = *(it - 1);
        }
        *it = value;
        ++number_of_elements;
        return it;
    }

    my_iterator<T> erase(const my_iterator<T> pos) { //PASS
        for (auto it = pos; it < end() - 1; ++it) {
            *it = *(it + 1);
        }
        --number_of_elements;
        return pos;
    }


    my_iterator<T> erase(const my_iterator<T> first, const my_iterator<T> last) { //PASS
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
    }

    friend int main();

private:



    size_t capacity_ = 0;
    size_t number_of_elements = 0;
    T* data_ = nullptr;

    size_t factor = 2;
};


#endif //INC_5THLABONLY_MY_VECTOR_Hx